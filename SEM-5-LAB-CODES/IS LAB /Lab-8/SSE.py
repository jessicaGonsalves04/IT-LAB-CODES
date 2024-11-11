from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad
import hashlib


# Encryption function using AES
def encrypt_data(key, data, iv=None):
    cipher = AES.new(key, AES.MODE_CBC, iv=iv or get_random_bytes(AES.block_size))
    iv = cipher.iv
    ciphertext = cipher.encrypt(pad(data.encode(), AES.block_size))
    return iv, ciphertext


# Decryption function using AES
def decrypt_data(key, iv, ciphertext):
    cipher = AES.new(key, AES.MODE_CBC, iv)
    plaintext = unpad(cipher.decrypt(ciphertext), AES.block_size)
    return plaintext.decode()


# Create encrypted index
def create_index(documents, key):
    index = {}
    iv_store = {}  # Store IVs for each word hash to reuse during search

    for doc_id, doc in documents.items():
        for word in doc.split():
            word_hash = hashlib.sha256(word.encode()).hexdigest()  # Hash word and convert to hex
            if word_hash not in index:
                index[word_hash] = []
            index[word_hash].append(doc_id)

    # Encrypt the index
    encrypted_index = {}
    for word_hash, doc_ids in index.items():
        # Encrypt the word hash and doc_ids with a fixed IV
        iv, encrypted_word = encrypt_data(key, word_hash)
        iv_store[encrypted_word] = iv  # Store the IV for each encrypted word
        encrypted_index[encrypted_word] = [encrypt_data(key, str(doc_id))[1] for doc_id in doc_ids]

    return encrypted_index, iv_store


# Search in the encrypted index
def search(encrypted_index, query, key, iv_store):
    query_hash = hashlib.sha256(query.encode()).hexdigest()  # Hash the query word
    iv, encrypted_query_hash = encrypt_data(key, query_hash)  # Encrypt query hash

    # Search for the encrypted query in the encrypted index using the same IV from the index
    if encrypted_query_hash in encrypted_index:
        doc_ids = encrypted_index[encrypted_query_hash]
        iv_for_doc_ids = iv_store[encrypted_query_hash]  # Get the IV corresponding to the query hash
        return [decrypt_data(key, iv_for_doc_ids, encrypted_doc_id) for encrypted_doc_id in doc_ids]
    else:
        return []


# Example usage
documents = {
    "doc1": "this is a document with some words",
    "doc2": "another document with different words",
    "doc3": "yet another document with some common words"
}

key = get_random_bytes(16)  # Generate random AES key
encrypted_index, iv_store = create_index(documents, key)  # Create encrypted index
query = "document"
results = search(encrypted_index, query, key, iv_store)  # Perform a search

print("Search results:", results)
