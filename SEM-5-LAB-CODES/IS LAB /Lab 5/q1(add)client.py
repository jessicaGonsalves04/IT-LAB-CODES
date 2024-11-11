# Write server and client scripts where the client sends a message in multiple parts to
# the server, the server reassembles the message, computes the hash of the reassembled
# message, and sends this hash back to the client. The client then verifies the integrity
# of the message by comparing the received hash with the locally computed hash of the
# original message.





import socket
import hashlib

def compute_hash(data):
    """Compute the SHA-256 hash of the given data."""
    return hashlib.sha256(data).hexdigest()

def start_client(server_host='127.0.0.1', server_port=65432):
    """Start the client and send data to the server in multiple parts."""
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((server_host, server_port))

    try:
        # Define the full message to send (as bytes)
        full_message = b"Hello, Server! This message is sent in multiple parts."
        print(f"Original message: {full_message.decode()}")

        # Split the message into parts
        parts = [full_message[i:i+10] for i in range(0, len(full_message), 10)]

        # Send each part to the server
        for part in parts:
            print(f"Sending part: {part.decode()}")
            client_socket.send(part)

        # Indicate the end of sending data
        client_socket.shutdown(socket.SHUT_WR)

        # Receive the hash from the server
        received_hash = client_socket.recv(64).decode()
        print(f"Received hash from server: {received_hash}")

        # Compute the hash of the original message
        expected_hash = compute_hash(full_message)

        # Verify the hash
        if expected_hash == received_hash:
            print("Message integrity verified. No corruption or tampering detected.")
        else:
            print("Message integrity check failed. Possible corruption or tampering.")

    finally:
        client_socket.close()

if __name__ == "__main__":
    start_client()
