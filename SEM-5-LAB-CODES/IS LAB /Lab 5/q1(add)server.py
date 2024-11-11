import socket
import hashlib

def compute_hash(data):
    """Compute the SHA-256 hash of the given data."""
    return hashlib.sha256(data).hexdigest()

def handle_client_connection(client_socket):
    """Handle incoming client connection."""
    message_parts = []
    try:
        while True:
            # Receive a part of the message from the client
            data = client_socket.recv(1024)
            if not data:
                break  # If no data is received, end the connection
            print(f"Received part: {data.decode()}")
            message_parts.append(data)  # Collect the parts

        # Reassemble the message
        full_message = b''.join(message_parts)
        print(f"Reassembled message: {full_message.decode()}")

        # Compute the hash of the reassembled message
        reassembled_hash = compute_hash(full_message)
        print(f"Computed hash: {reassembled_hash}")

        # Send the computed hash back to the client
        client_socket.send(reassembled_hash.encode())
    finally:
        client_socket.close()

def start_server(host='127.0.0.1', port=65432):
    """Start the server."""
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Set socket option to reuse the address and port
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    server_socket.bind((host, port))
    server_socket.listen(1)
    print(f"Server listening on {host}:{port}")

    while True:
        client_socket, addr = server_socket.accept()
        print(f"Accepted connection from {addr}")
        handle_client_connection(client_socket)

if __name__ == "__main__":
    start_server()
