# Lab Exercise 2: Execute the following for PKSE:
# 2a. Create a dataset:
# o Generate a text corpus of at least ten documents. Each document should contain
# multiple words.
# 2b. Implement encryption and decryption functions:
# o Use the Paillier cryptosystem for encryption and decryption.
# 2c. Create an encrypted index:
# o Build an inverted index mapping word to the list of document IDs containing
# those words.o Encrypt the index using the Paillier cryptosystem.
# 2d. Implement the search function:
# o Take a search query as input.
# o Encrypt the query using the public key.
# o Search the encrypted index for matching terms.
# o Decrypt the returned document IDs using the private key.
import phe as paillier
from collections import defaultdict

# 2a. Create a smaller dataset (text corpus)
docs = [
    "quick fox jumps",
    "encryption ensures",
    "searchable works",
    "data matters",
    "cryptography involves",
    "fox runs",
    "pillars important",
    "cloud uses",
    "datasets require",
    "data is crucial"
]

# 2b. Generate Paillier keypair
pub_key, priv_key = paillier.generate_paillier_keypair()


# Function to encrypt data using the Paillier public key
def enc_num(pub_key, num):
    return pub_key.encrypt(num)


# Function to decrypt data using the Paillier private key
def dec_num(priv_key, enc_num):
    return priv_key.decrypt(enc_num)


# 2c. Create an inverted index
inv_idx = defaultdict(list)

for doc_id, doc in enumerate(docs):
    words = set(doc.lower().split())  # Avoid duplicate words in the same doc
    for word in words:
        inv_idx[word].append(doc_id)

# Encrypt the index: Encrypt document IDs using Paillier
enc_inv_idx = {
    word: [enc_num(pub_key, doc_id) for doc_id in doc_ids]
    for word, doc_ids in inv_idx.items()
}


# 2d. Implement the search function
def search_enc_idx(query, enc_idx, priv_key):
    query = query.lower()

    # If the word exists in the index, retrieve encrypted document IDs
    if query in enc_idx:
        enc_doc_ids = enc_idx[query]

        # Decrypt the document IDs using the private key
        dec_doc_ids = [dec_num(priv_key, enc_doc_id) for enc_doc_id in enc_doc_ids]
        return dec_doc_ids
    else:
        return []


# Example usage

# Input search query
query = "data"

# 2d. Search for the encrypted query and decrypt the results
search_results = search_enc_idx(query, enc_inv_idx, priv_key)
print("Decrypted Search Results (Document IDs):", search_results)

# Display the corresponding documents
for doc_id in search_results:
    print(f"Document {doc_id}: {docs[doc_id]}")
