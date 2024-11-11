def encryptMessage(msg,key):
	secret=""
	for i in range(len(msg)):
		char=msg[i]
		if(char.isupper()):
			secret+= chr((ord(char)+key-65)%26+65)
		elif(char.islower()):
			secret+=chr((ord(char)+key-97)%26+97)
		else:
			continue
	return secret
def decryptMessage(code,key):
	decode=""
	for i in range(len(code)):
		c=code[i];
		if(c.isupper()):
			k=(ord(c)-key-65)%26+65
			if(k<0):
				k+26
			decode+=chr(k)
		else:
			l=(ord(c)-key-97)%26+97
			if(l<0):
				l+26
			decode+=chr(l)
	return decode
key=20
msg=input("Enter the message: ")
code=encryptMessage(msg,key);
print("Encrypted message is:",code)
print("Decrpyted:",decryptMessage(code,key))