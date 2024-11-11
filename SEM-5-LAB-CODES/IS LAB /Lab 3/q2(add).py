from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.hkdf import HKDF
from cryptography.hazmat.primitives.kdf.concatkdf import ConcatKDFHash
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.padding import PKCS7
import os

# 1. Generate ECC private and public key
private_key = ec.generate_private_key(ec.SECP256R1(), default_backend())
public_key = private_key.public_key()

# Serialize public key to share
public_bytes = public_key.public_bytes(
    encoding=serialization.Encoding.PEM,
    format=serialization.PublicFormat.SubjectPublicKeyInfo
)


# Encrypt the message using the recipient's public key
def ecc_encrypt(public_key, message):
    # Generate ephemeral private key
    ephemeral_key = ec.generate_private_key(ec.SECP256R1(), default_backend())

    # Perform ECDH key exchange to derive a shared secret
    shared_key = ephemeral_key.exchange(ec.ECDH(), public_key)

    # Use HKDF (or another KDF) to derive an AES key from the shared secret
    derived_key = HKDF(
        algorithm=hashes.SHA256(),
        length=32,
        salt=None,
        info=b'handshake data',
        backend=default_backend()
    ).derive(shared_key)

    # Use AES to encrypt the message
    cipher = Cipher(algorithms.AES(derived_key), modes.GCM(os.urandom(16)), backend=default_backend())
    encryptor = cipher.encryptor()

    # Pad the message for AES encryption
    padder = PKCS7(128).padder()
    padded_message = padder.update(message) + padder.finalize()

    ciphertext = encryptor.update(padded_message) + encryptor.finalize()

    return ephemeral_key.public_key(), encryptor.tag, ciphertext, cipher.algorithm.block_size


# Decrypt the ciphertext using the private key
def ecc_decrypt(private_key, ephemeral_public_key, tag, ciphertext, block_size):
    # Perform ECDH key exchange to derive the same shared secret
    shared_key = private_key.exchange(ec.ECDH(), ephemeral_public_key)

    # Derive the same AES key from the shared secret
    derived_key = HKDF(
        algorithm=hashes.SHA256(),
        length=32,
        salt=None,
        info=b'handshake data',
        backend=default_backend()
    ).derive(shared_key)

    # Use AES to decrypt the message
    cipher = Cipher(algorithms.AES(derived_key), modes.GCM(os.urandom(16), tag), backend=default_backend())
    decryptor = cipher.decryptor()

    # Decrypt and unpad the message
    padded_message = decryptor.update(ciphertext) + decryptor.finalize()
    unpadder = PKCS7(block_size).unpadder()
    original_message = unpadder.update(padded_message) + unpadder.finalize()

    return original_message


# Encrypt the message "Secure Transactions"
message = b"Secure Transactions"
ephemeral_public_key, tag, ciphertext, block_size = ecc_encrypt(public_key, message)

# Decrypt to verify the original message
decrypted_message = ecc_decrypt(private_key, ephemeral_public_key, tag, ciphertext, block_size)

# Print results
print("Original message:", message)
print("Decrypted message:", decrypted_message)
