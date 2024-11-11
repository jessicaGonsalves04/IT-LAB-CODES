#  Eve secretly gets access to Alice's computer and using her cipher types
# "abcdefghi". The screen shows "CABDEHFGL". If Eve knows that Alice is using
# a keyed transposition cipher, answer the following questions:
# a) What type of attack is Eve launching?
# b) What is the size of the permutation key?-
# c) Use the Vigenere cipher with keyword "HEALTH" to encipher the
# message "Life is full of surprises".


def vigenere_encrypt(plaintext, keyword):
    # Remove spaces and convert to uppercase
    plaintext = plaintext.replace(" ", "").upper()
    keyword = keyword.upper()

    # Create a list to hold the ciphertext
    ciphertext = []

    # Repeat the keyword to match the length of the plaintext
    keyword_repeated = (keyword * (len(plaintext) // len(keyword) + 1))[:len(plaintext)]

    for p, k in zip(plaintext, keyword_repeated):
        # Calculate the shift
        shift = ord(k) - ord('A')
        # Encrypt the letter
        encrypted_char = chr(((ord(p) - ord('A') + shift) % 26) + ord('A'))
        ciphertext.append(encrypted_char)

    return ''.join(ciphertext)


# Given plaintext and keyword
plaintext = "Life is full of surprises"
keyword = "HEALTH"

# Encrypt the message
encrypted_message = vigenere_encrypt(plaintext, keyword)

print("Encrypted Message:", encrypted_message)
