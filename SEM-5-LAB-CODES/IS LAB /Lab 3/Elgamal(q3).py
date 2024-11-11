# Given an ElGamal encryption scheme with a public key (p, g, h) and a
# private key x, encrypt the message "Confidential Data". Then decrypt the
# ciphertext to retrieve the original message.

from Crypto.Util import number
import random

p=number.getPrime(512)#obtain a prime number which is 512 bits longf
g=random.randint(2,p-1)#generator and 2 - p-1 is the range
x=random.randint(1,p-2)#x is private key

#compute public key
h= pow(g,x,p) #g^x mod p here g=e1  h=e2 x=d

print(f"Public Key: (p={p}, g={g}, h={h})")
print(f"Private Key: x={x}")

def encrypt(message, p, g, h):
    # Convert message to an integer
    m = int.from_bytes(message.encode(), 'big')
    k = random.randint(1, p-2)  # Choose a random integer k (ephemeral key)

    c1 = pow(g, k, p)  # Compute ciphertext component c1 = g^k mod p
    c2 = (m * pow(h, k, p)) % p  # Compute ciphertext component c2 = m * h^k mod p
    return c1,c2

def decrypt(c1, c2, x, p):
    s = pow(c1, x, p)  # Compute the shared secret s = c1^x mod p
    s_inv = pow(s, -1, p)  # Compute the modular inverse of s using pow function
    m = (c2 * s_inv) % p  # Recover the original message m = c2 * s_inv mod p
    message = m.to_bytes((m.bit_length() + 7) // 8, 'big').decode()  # Convert integer back to bytes
    return message

plaintext = "Confidential Data"
c1, c2 = encrypt(plaintext, p, g, h)
print(f"Ciphertext: (c1={c1}, c2={c2})")

decrypted_message = decrypt(c1, c2, x, p)
print(f"Decrypted Message: {decrypted_message}")
