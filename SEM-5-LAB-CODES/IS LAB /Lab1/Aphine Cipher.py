keys=[1,3,5,7,9,11,15,17,19,21,23,25]
key1=17
key2=20
def findMultiplicativeInverse(key1):
	mkey=0
	for i in keys:
		if((i*key1)%26==1):
			mkey=i
			return(mkey)
def encryptMessage(msg,key1,key2):
	secret=""
	for i in range(len(msg)):
		char=msg[i]
		if(char.isupper()):
			secret+= chr((((ord(char)-65)*key1+key2)%26)+65)
		elif(char.islower()):
			secret+= chr((((ord(char)-97)*key1+key2)%26)+97)
		else:
			continue
	return secret

def decryptMessage(code,key1,key2):
	decode=""
	a=findMultiplicativeInverse(key1)
	for i in range(len(code)):
		c=code[i];
		if(c.isupper()):
			decode+=chr((((ord(c)-65)-key2)*a)%26+65)
		else:
			decode+=chr((((ord(c)-97)-key2)*a)%26+97)
	return decode
msg=input("Enter the message: ")
code=encryptMessage(msg,key1,key2);
print("Encrypted message is:",code)
print("Decrpyted:",decryptMessage(code,key1,key2))