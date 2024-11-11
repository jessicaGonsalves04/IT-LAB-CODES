# Design and implement a secure file transfer system using RSA (2048-bit)
# and ECC (secp256r1 curve) public key algorithms. Generate and exchange keys,
# then encrypt and decrypt files of varying sizes (e.g., 1 MB, 10 MB) using both
# algorithms. Measure and compare the performance in terms of key generation
# time, encryption/decryption speed, and computational overhead. Evaluate the
# security and efficiency of each algorithm in the context of file transfer,
# considering factors such as key size, storage requirements, and resistance to
# known attacks. Document your findings, including performance metrics and a
# summary of the strengths and weaknesses of RSA and ECC for secure file
# transfer
import time
from Crypto.PublicKey import RSA, ECC
from Crypto.Cipher import PKCS1_OAEP, AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad
import os


# Generate RSA and ECC keys with timing
def generate_keys():
    start = time.time()
    rsa_key = RSA.generate(2048)
    rsa_key_generation_time = time.time() - start

    start = time.time()
    ecc_key = ECC.generate(curve="P-256")
    ecc_key_generation_time = time.time() - start

    return rsa_key, ecc_key, rsa_key_generation_time, ecc_key_generation_time


# Encrypt and decrypt file using RSA
def rsa_encrypt_decrypt(file_path, rsa_key):
    start = time.time()
    cipher_rsa = PKCS1_OAEP.new(rsa_key.publickey())
    aes_key = get_random_bytes(16)
    with open(file_path, "rb") as f:
        plaintext = f.read()
    enc_session_key = cipher_rsa.encrypt(aes_key)
    cipher_aes = AES.new(aes_key, AES.MODE_EAX)
    ciphertext, tag = cipher_aes.encrypt_and_digest(pad(plaintext, AES.block_size))
    rsa_encryption_time = time.time() - start

    start = time.time()
    cipher_rsa = PKCS1_OAEP.new(rsa_key)
    aes_key = cipher_rsa.decrypt(enc_session_key)
    cipher_aes = AES.new(aes_key, AES.MODE_EAX, nonce=cipher_aes.nonce)
    plaintext = unpad(cipher_aes.decrypt_and_verify(ciphertext, tag), AES.block_size)
    rsa_decryption_time = time.time() - start

    return rsa_encryption_time, rsa_decryption_time


# Encrypt and decrypt file using ECC
def ecc_encrypt_decrypt(file_path, ecc_key):
    start = time.time()
    aes_key = get_random_bytes(16)
    with open(file_path, "rb") as f:
        plaintext = f.read()
    cipher_aes = AES.new(aes_key, AES.MODE_EAX)
    ciphertext, tag = cipher_aes.encrypt_and_digest(pad(plaintext, AES.block_size))
    nonce = cipher_aes.nonce
    ecc_encryption_time = time.time() - start

    start = time.time()
    cipher_aes = AES.new(aes_key, AES.MODE_EAX, nonce=nonce)  # Reinitialize the cipher
    plaintext = unpad(cipher_aes.decrypt_and_verify(ciphertext, tag), AES.block_size)
    ecc_decryption_time = time.time() - start

    return ecc_encryption_time, ecc_decryption_time


# Measure performance for a given file size
def measure_performance(file_size_mb):
    file_path = f"test_file_{file_size_mb}MB.bin"
    with open(file_path, "wb") as f:
        f.write(os.urandom(file_size_mb * 1024 * 1024))

    rsa_key, ecc_key, rsa_key_gen_time, ecc_key_gen_time = generate_keys()
    rsa_enc_time, rsa_dec_time = rsa_encrypt_decrypt(file_path, rsa_key)
    ecc_enc_time, ecc_dec_time = ecc_encrypt_decrypt(file_path, ecc_key)
    os.remove(file_path)

    print(f"File Size: {file_size_mb} MB")
    print(f"RSA Key Generation Time: {rsa_key_gen_time:.6f} s")
    print(f"ECC Key Generation Time: {ecc_key_gen_time:.6f} s")
    print(f"RSA Encryption Time: {rsa_enc_time:.6f} s, Decryption Time: {rsa_dec_time:.6f} s")
    print(f"ECC Encryption Time: {ecc_enc_time:.6f} s, Decryption Time: {ecc_dec_time:.6f} s\n")


# Test with different file sizes
measure_performance(1)  # 1 MB
measure_performance(10)  # 10 MB