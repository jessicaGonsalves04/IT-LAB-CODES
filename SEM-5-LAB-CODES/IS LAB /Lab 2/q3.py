import time
from Crypto.Cipher import DES , AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad,unpad


message=b"Performance Testing of Encryption Algorithms"
des_key=get_random_bytes(8) #des need 64 bits for key
aes_key=get_random_bytes(32)#aes 256 bits which is 32 bytes

des_cipher=DES.new(des_key,DES.MODE_ECB)#des initially uses IV in CBC
padded_message=pad(message,DES.block_size)

#measure des encryption time
start_time=time.time()
des_ciphertext=des_cipher.encrypt(padded_message)
des_time=time.time()-start_time
#decryption for DES
start_time=time.time()
des_decipher=DES.new(des_key,DES.MODE_ECB)
des_decrypted_message=unpad(des_decipher.decrypt(des_ciphertext), DES.block_size)
des_dtime=time.time()-start_time


aes_cipher=AES.new(aes_key,AES.MODE_ECB)#here IV is 16 bytes
padded_message=pad(message,AES.block_size)
#measure aes encryption time
start_time=time.time()
aes_ciphertext=aes_cipher.encrypt(padded_message)
aes_time=time.time()-start_time
# Measure AES Decryption Time
start_time = time.time()
aes_decipher = AES.new(aes_key, AES.MODE_ECB)
aes_decrypted_message = unpad(aes_decipher.decrypt(aes_ciphertext), AES.block_size)
aes_decrypt_time = time.time() - start_time

# Report Results
print(f"DES Encryption Time: {des_time:.6f} seconds")
print(f"DES Decryption Time: {des_dtime:.6f} seconds")
print(f"AES-256 Encryption Time: {aes_time:.6f} seconds")
print(f"AES-256 Decryption Time: {aes_decrypt_time:.6f} seconds")