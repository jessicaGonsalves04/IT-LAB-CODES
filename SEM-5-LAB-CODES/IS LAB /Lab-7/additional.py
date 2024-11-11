# Implement similar exercise for other PHE operations (like homomorphic multiplication using ElGamal)
# or explore different functionalities within Paillier.
# 1a: Homomorphic Multiplication (ElGamal Cryptosystem): Implement ElGamal encryption
# and demonstrate homomorphic multiplication on encrypted messages. (ElGamal supports
# multiplication but not homomorphic addition.)
# 1b: Secure Data Sharing (Paillier): Simulate a scenario where two parties share encrypted data
# and perform calculations on the combined data without decryption.
# 1c: Secure Thresholding (PHE): Explore how PHE can be used for secure multi-party
# computation, where a certain number of parties need to collaborate on a computation without
# revealing their individual data.
# 1d: Performance Analysis (Benchmarking): Compare the performance of different PHE
# schemes (Paillier and ElGamal) for various operations

import random
from sympy import mod_inverse

class ElGamal:
    def __init__(self, p=None, g=None):
        self.p = p or self.generate_large_prime(512)
        self.g = g or random.randint(2, self.p - 1)
        self.private_key = random.randint(1, self.p - 2)
        self.public_key = pow(self.g, self.private_key, self.p)

    @staticmethod
    def generate_large_prime(bits):
        # Generate a large prime number using random
        return random.getrandbits(bits)  # Note: Replace with proper prime generation

    def encrypt(self, plaintext):
        y = random.randint(1, self.p - 2)
        c1 = pow(self.g, y, self.p)
        c2 = (plaintext * pow(self.public_key, y, self.p)) % self.p
        return (c1, c2)

    def decrypt(self, ciphertext):
        c1, c2 = ciphertext
        s = pow(c1, self.private_key, self.p)
        s_inv = mod_inverse(s, self.p)
        plaintext = (c2 * s_inv) % self.p
        return plaintext

    def multiply_encrypted(self, ciphertext1, ciphertext2):
        # Homomorphic multiplication of two ciphertexts
        c1_1, c2_1 = ciphertext1
        c1_2, c2_2 = ciphertext2
        # New ciphertext will be (c1_1 * c1_2, c2_1 * c2_2 % p)
        c1_new = (c1_1 * c1_2) % self.p
        c2_new = (c2_1 * c2_2) % self.p
        return (c1_new, c2_new)

# Example Usage for ElGamal Homomorphic Multiplication
if __name__ == "__main__":
    elgamal = ElGamal()

    # Encrypt two messages
    plaintext1 = 5
    plaintext2 = 10

    encrypted1 = elgamal.encrypt(plaintext1)
    encrypted2 = elgamal.encrypt(plaintext2)

    # Perform homomorphic multiplication on encrypted messages
    encrypted_product = elgamal.multiply_encrypted(encrypted1, encrypted2)

    # Decrypt the product
    decrypted_product = elgamal.decrypt(encrypted_product)

    print("Decrypted Product:", decrypted_product)  # Should output 50 (5 * 10)
