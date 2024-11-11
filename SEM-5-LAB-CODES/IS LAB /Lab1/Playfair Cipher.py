import numpy as np
def generate_newKey(key):
    new_key = ""
    i = 0
    while i < len(key) - 1:
        if key[i] != key[i + 1]:
            new_key += key[i]
            new_key += key[i + 1]
            i += 2
        else:
            new_key += key[i] + 'x'
            i += 1

    # Append the last character if it's not part of a processed pair
    if i < len(key):
        new_key += key[i]
    if len(new_key) % 2 != 0:
        new_key += 'x'

    print("Processed Key:", new_key)
    return new_key

def find_position(matrix, char):
    for r, row in enumerate(matrix):
        for c, cell in enumerate(row):
            if cell == char:
                return r, c
    return None, None

def encrypt_message(matrix, new_key):
    encrypted_key = ""
    i = 0
    while i < len(new_key) - 1:
        a = new_key[i]
        b = new_key[i + 1]

        row1, col1 = find_position(matrix, a)
        row2, col2 = find_position(matrix, b)

        if row1 == row2:
            encrypted_key += matrix[row1][(col1 + 1) % 5]
            encrypted_key += matrix[row2][(col2 + 1) % 5]
        elif col1 == col2:
            encrypted_key += matrix[(row1 + 1) % 5][col1]
            encrypted_key += matrix[(row2 + 1) % 5][col2]
        else:
            encrypted_key += matrix[row1][col2]
            encrypted_key += matrix[row2][col1]

        i += 2
    return encrypted_key
def decrypt_message(matrix, new_key):
    decrypted_key = ""
    i = 0
    while i < len(new_key) - 1:
        a = new_key[i]
        b = new_key[i + 1]

        row1, col1 = find_position(matrix, a)
        row2, col2 = find_position(matrix, b)

        if row1 == row2:
            decrypted_key += matrix[row1][(col1 - 1) % 5]
            decrypted_key += matrix[row2][(col2 - 1) % 5]
        elif col1 == col2:
            decrypted_key += matrix[(row1 - 1) % 5][col1]
            decrypted_key += matrix[(row2 - 1) % 5][col2]
        else:
            decrypted_key += matrix[row1][col2]
            decrypted_key += matrix[row2][col1]

        i += 2
    decrypted_message=""
    for i in decrypted_key:
        if(i=='x'):
            continue
        else:
            decrypted_message+=i
    return decrypted_message

# Main script
key = input("Enter the key: ").lower().replace('j', 'i')
plain_text=input("Enter the plain text")
tableStr = ""
for c in key:
    if c not in tableStr:
        tableStr += c
for i in range(ord('a'), ord('z') + 1):
    if chr(i) not in tableStr and chr(i) != 'j':
        tableStr += chr(i)

# Convert String to a matrix
rows = []
for i in range(0, len(tableStr), 5):
    row = tableStr[i:i + 5]
    rows.append(list(row))

# Print the matrix
for row in rows:
    print(' '.join(row))

# Generate new key and encrypt message
new_Plain = generate_newKey(plain_text)
encrypted_message = encrypt_message(rows, new_Plain)
print("Encrypted Message:", encrypted_message)
print("Decrypted Message:", decrypt_message(rows,encrypted_message))
