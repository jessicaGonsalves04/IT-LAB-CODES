# 1c: Secure Thresholding (PHE): Explore how PHE can be used for secure multi-party
# computation, where a certain number of parties need to collaborate on a computation without
# revealing their individual data.
import random

class SecureThreshold:
    def __init__(self, threshold):
        self.threshold = threshold
        self.secrets = []

    def share_secret(self, secret):
        """Share a secret among participants."""
        shares = []
        for _ in range(self.threshold):
            shares.append(random.randint(1, 100))  # Random shares
        shares.append(secret)  # Last share is the secret
        self.secrets = shares

    def reconstruct_secret(self):
        """Reconstruct the secret from the shares."""
        if len(self.secrets) < self.threshold:
            raise ValueError("Not enough shares to reconstruct the secret.")
        return self.secrets[-1]  # Last share is the secret

# Example Usage for Secure Thresholding
if __name__ == "__main__":
    threshold = 3
    secret = 42

    secure_threshold = SecureThreshold(threshold)
    secure_threshold.share_secret(secret)

    # Simulate reconstructing the secret
    reconstructed_secret = secure_threshold.reconstruct_secret()
    print("Reconstructed Secret:", reconstructed_secret)  # Should output 42
