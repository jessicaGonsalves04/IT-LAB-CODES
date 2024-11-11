#Using ECC (Elliptic Curve Cryptography), encrypt the message "Secure
# Transactions" with the public key. Then decrypt the ciphertext with the private
# key to verify the original message.

from cryptography.hazmat.primitives.asymmetric import ec
from cryptography.hazmat.primitives import serialization,hashes
from cryptography.hazmat.primitives.ciphers import Cipher,algorithms,modes
import os

private_key=ec.generate_private_key(ec.SECP256R1())#generate private key for the curve SECP256R1
public_key=private_key.public_key()

# Serialize keys to PEM format (for display purposes)
private_pem = private_key.private_bytes(
    encoding=serialization.Encoding.PEM,
    format=serialization.PrivateFormat.TraditionalOpenSSL,
    encryption_algorithm=serialization.NoEncryption()
)
public_pem = public_key.public_bytes(
    encoding=serialization.Encoding.PEM,
    format=serialization.PublicFormat.SubjectPublicKeyInfo
)
# Display keys
print("Public Key:\n", public_pem.decode())
print("Private Key:\n", private_pem.decode())

# Message to be encrypted
message = b"Secure Transactions"

# Generate a shared secret using ECDH
ephemeral_private_key = ec.generate_private_key(ec.SECP256R1())
ephemeral_public_key = ephemeral_private_key.public_key()
shared_secret = ephemeral_private_key.exchange(ec.ECDH(), public_key)



