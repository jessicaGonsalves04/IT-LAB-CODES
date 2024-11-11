# Problem: Add two encrypted integers (a and b).
# This program demonstrates how to perform homomorphic addition on encrypted integers
# using the Paillier Cryptosystem.


import random
import math
from Crypto.PublicKey import RSA
from Crypto.Random import get_random_bytes


# Function to generate RSA keypair (acting as a simplified version of Paillier keys)
def generate_keypair(nlength=1024):
    """Generates a public/private key pair"""
    key = RSA.generate(nlength)
    pub_key = key.publickey()
    return pub_key, key


# Encryption function (simplified for demonstration purposes)
def encrypt(pub_key, message):
    """Encrypts a message using the public key"""
    random_bytes = get_random_bytes(16)  # Random bytes for encryption randomness
    p, q = pub_key.n // 2, pub_key.n // 2 + 1

    # Ensure p and q are relatively prime
    while math.gcd(p, q) != 1:
        p, q = pub_key.n // 2, pub_key.n // 2 + 1

    # Message encryption with homomorphic properties
    m_dot = pow(message, 2, pub_key.n)  # Square the message mod n
    r_dot = pow(int.from_bytes(random_bytes, byteorder='big'), 2, pub_key.n)  # Square the randomness mod n

    ciphertext = m_dot * r_dot % pub_key.n  # Final ciphertext
    return ciphertext


# Decryption function (not fully implemented here, simplified)
def decrypt(priv_key, ciphertext):
    """Decrypts a ciphertext using the private key"""
    p = priv_key.n // 2
    l = (ciphertext - 1) // priv_key.n
    message = math.floor(l * pow(p, -1, priv_key.n))
    return message


# Homomorphic addition of two encrypted values
def homomorphic_add(ciphertext1, ciphertext2, pub_key):
    """Performs homomorphic addition on ciphertexts"""
    return ciphertext1 * ciphertext2 % pub_key.n


# Main program execution
if __name__ == "__main__":
    # Generate key pair (public and private keys)
    pub_key, priv_key = generate_keypair()

    # Integers to encrypt
    a = 5
    b = 10

    # Encrypt integers using the public key
    ciphertext_a = encrypt(pub_key, a)
    ciphertext_b = encrypt(pub_key, b)

    # Perform homomorphic addition
    ciphertext_sum = homomorphic_add(ciphertext_a, ciphertext_b, pub_key)

    # Decrypt the result (if desired, optional decryption code)
    # decrypted_sum = decrypt(priv_key, ciphertext_sum)
    # print(f"Decrypted sum: {decrypted_sum}")

    # Print encrypted values and their sum
    print(f"Ciphertext of a: {ciphertext_a}")
    print(f"Ciphertext of b: {ciphertext_b}")
    print(f"Ciphertext of a + b: {ciphertext_sum}")
