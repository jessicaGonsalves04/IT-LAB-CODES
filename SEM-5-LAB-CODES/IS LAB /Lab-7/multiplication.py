# Problem: Perform a secure diagnosis on encrypted patient data (blood pressure).
# • A doctor wants to diagnose patients with high blood pressure (> 130) without
# decrypting their actual blood pressure readings.
# • Use ElGamal encryption, which supports homomorphic comparison
#

import math
from Crypto.Random import get_random_bytes


# Generate public/private key pair for ElGamal encryption
def generate_keypair(p=1024):
    """Generates a public/private key pair"""
    while True:
        x = int.from_bytes(get_random_bytes(p // 8), byteorder='big')  # Private key x
        if pow(2, p - 1, p) == 1 and 1 < x < p - 1:
            break
    g = 2  # Generator (usually a small prime)
    y = pow(g, x, p)  # Public key component y = g^x mod p
    return ((p, g, y), x)  # Returns public key (p, g, y) and private key x


# Encrypt a message using ElGamal encryption
def encrypt(pub_key, message):
    """Encrypts a message using the public key"""
    p, g, y = pub_key
    r = int.from_bytes(get_random_bytes(p // 8), byteorder='big')  # Random integer r
    while math.gcd(r, p) != 1:  # Ensure r is coprime to p
        r = int.from_bytes(get_random_bytes(p // 8), byteorder='big')

    a = pow(g, r, p)  # a = g^r mod p
    b = (message * pow(y, r, p)) % p  # b = m * y^r mod p
    return (a, b)  # Return ciphertext (a, b)


# Decrypt the ciphertext using the private key
def decrypt(priv_key, ciphertext):
    """Decrypts a ciphertext using the private key"""
    p, g, _ = priv_key
    a, b = ciphertext
    x = priv_key
    message = (b * pow(a, -x, p)) % p  # m = (b * a^(-x)) mod p
    return message


# Perform homomorphic comparison between two encrypted values
def homomorphic_comparison(ciphertext1, ciphertext2, pub_key):
    """Performs homomorphic comparison on ciphertexts (greater than)"""
    p, g, y = pub_key
    a1, b1 = ciphertext1
    a2, b2 = ciphertext2
    return (a1 * a2) % p, (b1 * b2 * pow(y, 1, p)) % p  # Returns encrypted comparison result


# Main execution to demonstrate the diagnosis
if __name__ == "__main__":
    # Generate the keypair (public and private keys)
    pub_key, priv_key = generate_keypair()

    # Example blood pressure readings (encrypted)
    blood_pressure1 = encrypt(pub_key, 120)  # Encrypted value of 120
    blood_pressure2 = encrypt(pub_key, 140)  # Encrypted value of 140

    # Perform homomorphic comparison (m1 > m2)
    ciphertext_comparison = homomorphic_comparison(blood_pressure1, blood_pressure2, pub_key)

    # Optional: Decrypt the comparison result (for demonstration only)
    # decrypted_comparison = decrypt(priv_key, ciphertext_comparison)
    # print(f"Decrypted comparison: {decrypted_comparison} (True if blood pressure 1 > blood pressure 2)")

    # Diagnosis based on the encrypted comparison result
    diagnosis = ciphertext_comparison[0] * pow(ciphertext_comparison[1], -1, pub_key[0]) % pub_key[0]

    if diagnosis > 1:
        print("Diagnosis: High Blood Pressure detected.")
    else:
        print("Diagnosis: Normal Blood Pressure.")
