# Implement the
# Diffie-Hellman key exchange protocol, enabling peers to generate their public
# and private keys and securely compute the shared secret key. Measure the time
# taken for key generation and key exchange processes.

import time
from Crypto.Random import get_random_bytes
from Crypto.Util import number

# Step 1: Generate Diffie-Hellman parameters (prime number q and generator a)
def generate_parameters():
    q = number.getPrime(2048)  # Generate a large 2048-bit prime number (q)
    a = number.getPrime(256) % q  # Generate a small prime number (generator a) and take modulo q
    return q, a

# Step 2: Generate public and private keys for a peer
def generate_keys(q, a):
    private_key = number.getRandomRange(1, q-1)  # Generate a private key: random integer between 1 and q-1
    public_key = pow(a, private_key, q)  # Compute the public key: a^private_key mod q
    return private_key, public_key

# Step 3: Compute the shared secret key using the other peer's public key
def compute_shared_secret(private_key, other_public_key, q):
    shared_secret = pow(other_public_key, private_key, q)  # Compute shared secret: other_public_key^private_key mod q
    return shared_secret

# Step 4: Measure the time taken for key generation and key exchange
def measure_time():
    # Generate the Diffie-Hellman parameters (prime q and generator a)
    p, g = generate_parameters()

    # Peer 1 generates its private and public keys
    start_time = time.time()  # Start time for key generation
    private_key1, public_key1 = generate_keys(p, g)  # Generate private and public keys for Peer 1
    end_time = time.time()  # End time for key generation
    peer1_keygen_time = end_time - start_time  # Measure time taken for Peer 1's key generation

    # Peer 2 generates its private and public keys
    start_time = time.time()  # Start time for Peer 2 key generation
    private_key2, public_key2 = generate_keys(p, g)  # Generate private and public keys for Peer 2
    end_time = time.time()  # End time for Peer 2 key generation
    peer2_keygen_time = end_time - start_time  # Measure time taken for Peer 2's key generation

    # Compute the shared secret keys for both peers
    start_time = time.time()  # Start time for key exchange
    shared_secret1 = compute_shared_secret(private_key1, public_key2, p)  # Peer 1 computes shared secret
    shared_secret2 = compute_shared_secret(private_key2, public_key1, p)  # Peer 2 computes shared secret
    end_time = time.time()  # End time for key exchange
    key_exchange_time = end_time - start_time  # Measure time taken for key exchange

    # Output the time taken for key generation and key exchange
    print(f"Peer 1 Key Generation Time: {peer1_keygen_time:.2f} seconds")
    print(f"Peer 2 Key Generation Time: {peer2_keygen_time:.2f} seconds")
    print(f"Key Exchange Time: {key_exchange_time:.2f} seconds")

    # Verify that both peers have computed the same shared secret
    if shared_secret1 == shared_secret2:
        print("Shared secret is correctly computed by both peers.")
    else:
        print("Shared secret mismatch!")

    # Return the public keys and shared secret for further use or analysis
    return public_key1, public_key2, shared_secret1

# Step 5: Call the measure_time function to execute the Diffie-Hellman key exchange process
public_key1, public_key2, shared_secret = measure_time()

# Output the public keys and shared secret for inspection
print(f"Peer 1 Public Key: {public_key1}")
print(f"Peer 2 Public Key: {public_key2}")
print(f"Shared Secret: {shared_secret}")


