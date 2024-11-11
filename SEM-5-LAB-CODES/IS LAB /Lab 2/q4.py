from Crypto.Cipher import DES3
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes

# Generate a valid 24-byte (192-bit) key for Triple DES
key = DES3.adjust_key_parity(get_random_bytes(24))

message = b"Classified Text"

# Create a Triple DES cipher object in ECB mode
cipher = DES3.new(key, DES3.MODE_ECB)

# Pad the message to be a multiple of the block size (8 bytes for DES3)
padded_message = pad(message, DES3.block_size)

# Encrypt the message
ciphertext = cipher.encrypt(padded_message)
print("Ciphertext (hex):", ciphertext.hex())

# To decrypt, create a new cipher object with the same key
cipher_decrypt = DES3.new(key, DES3.MODE_ECB)

# Decrypt the ciphertext
decrypted_padded_message = cipher_decrypt.decrypt(ciphertext)

# Unpad the decrypted message
decrypted_message = unpad(decrypted_padded_message, DES3.block_size)
print("Decrypted Message:", decrypted_message.decode())
