# #Using RSA, encrypt the message "Asymmetric Encryption" with the public
# key (n, e). Then decrypt the ciphertext with the private key (n, d) to verify the
# original message.

from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
import binascii

key=RSA.generate(2048)#this is to generate an RSA key which is usually 2048 bits long
public_key=key.public_key()#gives the public key part
n=public_key.n#extract value of n and e
e=public_key.e
d=key.d#extract value of d from the main key itself
print(f"Public Key (n ,e): ({n},{e})")
print(f"Private Key (n,d): ({n},{d})")

message=b"Asymmetric Encryption"
cipher_rsa=PKCS1_OAEP.new(public_key)#create a rsa cipher object using public key
ciphertext=cipher_rsa.encrypt(message)#encrypt the message using the cipher
print("Ciphertext (hex):",binascii.hexlify(ciphertext).decode())#this value is in binary so convert it into hex and decode

cipher_rsa_decrypt=PKCS1_OAEP.new(key)
decrypted_message=cipher_rsa_decrypt.decrypt(ciphertext)
print("Decrypted Message:",decrypted_message.decode())
