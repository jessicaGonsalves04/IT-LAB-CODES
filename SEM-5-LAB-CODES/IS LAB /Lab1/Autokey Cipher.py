key=chr(ord('A')+7)
newKey=""
def newMessage(msg):
    newMsg=""
    for i in range(len(msg)):
        c=msg[i]
        if(c.isupper()):
            newMsg+=c
        elif(c.islower()):
            newMsg+=c.upper()
        else:
            continue
    return newMsg

def findNewKey(key,msg):
    new=""
    for i in range (len(msg)):
        c=msg[i]
        new+=c
    newKey=key+new[:-1]
    print(newKey)
    return newKey
def encryptMessage(key,msg):
    cipher=""
    for i in range (len(msg)):
        a=msg[i]
        b=newKey[i]
        cipher+=chr((ord(a)+ord(b)-2*ord('A'))%26+ord('A'))
    return cipher
def decryptMessage(newKey,newMsg):
    decode = ""
    for i in range(len(code)):
        a = code[i]
        b = newKey[i]
        decode += chr((ord(a) - ord(b) + 26) % 26 + ord('A'))
    return decode
msg=input("Enter the message:")
newMsg=newMessage(msg)
newKey=findNewKey(key,newMsg)
code=encryptMessage(newKey,newMsg)
print("Encrypted Message is:",code)
print("Decrypted message is:",decryptMessage(newKey,code))