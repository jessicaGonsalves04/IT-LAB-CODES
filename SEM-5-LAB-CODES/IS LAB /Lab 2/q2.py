from Crypto.Cipher import AES
from Crypto.Util.Padding import pad,unpad

key=bytes.fromhex("0123456789ABCDEF0123456789ABCDEF")
msg=b"Sensitive Information"
print("Message: "+msg.decode('utf-8')+" | Key:"+key.hex())
cipher= AES.new(key,AES.MODE_ECB)
padded_msg=pad(msg,AES.block_size)
ciphertext=cipher.encrypt(padded_msg)
print("ciphertext(hex): ",ciphertext.hex())
cipher_decrypt=AES.new(key,AES.MODE_ECB)
decrypted_padded_msg=cipher_decrypt.decrypt(ciphertext)
decrypted_msg=unpad(decrypted_padded_msg,AES.block_size)
print("Decrypted Message: ",decrypted_msg.decode())