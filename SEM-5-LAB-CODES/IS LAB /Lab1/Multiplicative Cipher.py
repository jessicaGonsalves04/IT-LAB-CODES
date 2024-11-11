keys=[1,3,5,7,9,11,15,17,19,21,23,25]
def findMultiplicativeInverse(key1):
	mkey=0
	for i in keys:
		if((i*key1)%26==1):
			mkey=i
			return(mkey)
def encryptMessage(msg,key):
	secret=""
	for i in range(len(msg)):
		char=msg[i]
		#cipher=(char*key)%26
		secret+= chr(((ord(char)-ord('A'))*key%26+65))
	return secret

def decryptMessage(code,key):
	decode=""
	#find multiplicative inverse
	# k=pow(key,-1,26)
	k=findMultiplicativeInverse(key)
	for i in range(len(code)):
		c=code[i];
		#multiply with multiplicative inverse mod 26
		decode+=chr((ord(c) - ord('A'))*k% 26 + ord('A'))
	return decode
key=7
msg=input("Enter the message(in caps no spaces): ")
code=encryptMessage(msg,key);
print("Encrypted message is:",code)
print("Decrpyted:",decryptMessage(code,key))