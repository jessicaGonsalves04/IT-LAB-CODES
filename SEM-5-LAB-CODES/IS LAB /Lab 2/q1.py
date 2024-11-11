#Encrypt the message "Confidential Data" using DES with the following key:
#"A1B2C3D4". Then decrypt the ciphertext to verify the original message.
from Crypto.Cipher import DES
from Crypto.Util.Padding import pad, unpad

# Define the key and message
key = b'A1B2C3D4'  # DES requires a 64-bit key
message = b"Confidential Data"
print("message: "+message.decode('utf-8')+" key :"+key.decode('utf-8'))

# Create a DES cipher object in ECB mode
cipher = DES.new(key, DES.MODE_ECB)

# Pad the message to be a multiple of 8 bytes
padded_message = pad(message, DES.block_size)

# Encrypt the message
ciphertext = cipher.encrypt(padded_message)
print("Ciphertext:", ciphertext.hex())

# Decrypt the ciphertext
decrypted_padded_message = cipher.decrypt(ciphertext)
print(decrypted_padded_message)

# Unpad the decrypted message
decrypted_message = unpad(decrypted_padded_message, DES.block_size)
print(decrypted_message)
print("Decrypted Message:", decrypted_message.decode('utf-8'))