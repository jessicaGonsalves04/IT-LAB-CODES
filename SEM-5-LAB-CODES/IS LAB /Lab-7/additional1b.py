# 1b: Secure Data Sharing (Paillier): Simulate a scenario where two parties share encrypted data
# and perform calculations on the combined data without decryption.
import random
from sympy import isprime, randprime, mod_inverse

class Paillier:
    def __init__(self, p=None, q=None):
        self.p = p or self.generate_large_prime(512)
        self.q = q or self.generate_large_prime(512)
        self.n = self.p * self.q
        self.n_sq = self.n ** 2
        self.g = self.n + 1
        self.lam = (self.p - 1) * (self.q - 1)  # λ(n) for decryption
        self.mu = mod_inverse(self.lam, self.n)  # precompute for decryption efficiency

    @staticmethod
    def generate_large_prime(bits):
        # Generate a large random prime of the specified bit length
        return randprime(2**(bits - 1), 2**bits)

    def encrypt(self, plaintext):
        r = random.randint(1, self.n - 1)
        c = (pow(self.g, plaintext, self.n_sq) * pow(r, self.n, self.n_sq)) % self.n_sq
        return c

    def decrypt(self, ciphertext):
        u = (pow(ciphertext, self.lam, self.n_sq) - 1) // self.n
        plaintext = (u * self.mu) % self.n
        return plaintext

    def add_encrypted(self, c1, c2):
        return (c1 * c2) % self.n_sq

# Example Usage for Paillier Secure Data Sharing
if __name__ == "__main__":
    # Both parties use the same Paillier instance (same key)
    paillier = Paillier()

    # Party 1 shares encrypted data
    plaintext1 = 25
    ciphertext1 = paillier.encrypt(plaintext1)

    # Party 2 shares encrypted data
    plaintext2 = 15
    ciphertext2 = paillier.encrypt(plaintext2)

    # Combine the encrypted data securely without decryption
    combined_encrypted = paillier.add_encrypted(ciphertext1, ciphertext2)

    # Decrypt the combined ciphertext
    decrypted_combined = paillier.decrypt(combined_encrypted)  # This will work as both use the same key

    print("Decrypted Combined Value:", decrypted_combined)  # Expecting the sum of plaintext1 and plaintext2
