from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP
from Crypto.Hash import SHA256


# Key generation function
def generate_keys():
    keyPair = RSA.generate(2048)
    pubKey = keyPair.publickey()
    privKey = keyPair
    return pubKey, privKey


# Encryption function using RSA
def encrypt_data(pubKey, data):
    cipher = PKCS1_OAEP.new(pubKey)
    ciphertext = cipher.encrypt(data)
    return ciphertext


# Decryption function using RSA
def decrypt_data(privKey, ciphertext):
    cipher = PKCS1_OAEP.new(privKey)
    plaintext = cipher.decrypt(ciphertext)
    return plaintext


# Create encrypted index
def create_index(documents, pubKey):
    index = {}

    for doc_id, doc in documents.items():
        for word in doc.split():
            word_hash = SHA256.new(word.encode()).digest()  # Create a hash of the word
            if word_hash not in index:
                index[word_hash] = []
            index[word_hash].append(doc_id)

    # Encrypt the index
    encrypted_index = {}
    for word_hash, doc_ids in index.items():
        encrypted_index[encrypt_data(pubKey, word_hash)] = [encrypt_data(pubKey, str(doc_id).encode()) for doc_id in
                                                            doc_ids]

    return encrypted_index


# Search in the encrypted index
def search(encrypted_index, query, pubKey, privKey):
    query_hash = SHA256.new(query.encode()).digest()  # Create a hash for the query
    encrypted_query_hash = encrypt_data(pubKey, query_hash)

    if encrypted_query_hash in encrypted_index:
        encrypted_doc_ids = encrypted_index[encrypted_query_hash]
        doc_ids = [decrypt_data(privKey, doc_id).decode() for doc_id in encrypted_doc_ids]  # Decrypt document IDs
        return doc_ids
    else:
        return []


# Example usage
documents = {
    "doc1": "this is a document with some words",
    "doc2": "another document with different words",
    "doc3": "yet another document with some common words"
}

pubKey, privKey = generate_keys()  # Generate RSA keys
encrypted_index = create_index(documents, pubKey)  # Create the encrypted index
query = "document"  # Query to search for
results = search(encrypted_index, query, pubKey, privKey)  # Perform a search

print("Search results:", results)
