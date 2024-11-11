key=input("Enter the key:")
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
    n=len(key)
    for i in range (len(msg)):
        c=key[i%n]
        if(c.isupper() or c.islower()):
            new+=c
        else:
            continue
    print(new)
    return new
def encryptMessage(key,msg):
    cipher=""
    n=len(key)
    for i in range (len(msg)):
        a=msg[i]
        b=newKey[i%n]
        cipher+=chr((ord(a)+ord(b)-2*ord('A'))%26+ord('A'))
    return cipher
def decryptMessage(newKey,newMsg):
    decode = ""
    n=len(key)
    for i in range(len(code)):
        a = code[i]
        b = newKey[i%n]
        decode += chr((ord(a) - ord(b) + 26) % 26 + ord('A'))
    return decode
msg=input("Enter the message:")
newMsg=newMessage(msg)
newKey=findNewKey(key,newMsg)
code=encryptMessage(newKey,newMsg)
print("Encrypted Message is:",code)
print("Decrypted message is:",decryptMessage(newKey,code))
