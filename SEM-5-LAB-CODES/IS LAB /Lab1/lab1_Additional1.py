# Use a brute-force attack to decipher the following message enciphered by Alice
# using an additive cipher. Suppose that Alice always uses a key that is close to her
# birthday, which is on the 13th of the month:
# NCJAEZRCLAS/LYODEPRLYZRCLASJLCPEHZDTOPDZOLN&BY

def additive_decrypt(ciphertext, key):
    decrypted_text = ""

    for char in ciphertext:
        if char.isalpha():  # Check if the character is a letter
            # Determine if the character is uppercase or lowercase
            if char.isupper():
                # Decrypt with wrap-around using ASCII values
                decrypted_char = chr(((ord(char) - ord('A') - key) % 26) + ord('A'))
            else:
                decrypted_char = chr(((ord(char) - ord('a') - key) % 26) + ord('a'))
            decrypted_text += decrypted_char
        else:
            # Keep non-alphabetic characters unchanged
            decrypted_text += char

    return decrypted_text

def brute_force_additive(ciphertext, key_range):
    for key in key_range:
        decrypted_message = additive_decrypt(ciphertext, key)
        print(f"Key {key}: {decrypted_message}")

# Given ciphertext
ciphertext = "NCJAEZRCLAS/LYODEPRLYZRCLASJLCPEHZDTOPDZOLN&BY"

# Define a range of keys close to Alice's birthday (13th)
key_range = range(10, 17)  # Keys from 10 to 16

# Perform the brute-force attack
brute_force_additive(ciphertext, key_range)
