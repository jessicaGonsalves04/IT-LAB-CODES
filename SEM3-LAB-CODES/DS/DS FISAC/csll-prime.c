#include <stdio.h>
#include <stdlib.h>

// Define the structure for the CSLL node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the CSLL
Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode; // Create a self-loop for the first node
        return newNode;
    } else {
        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        newNode->next = head; // Make it circular
        current->next = newNode;
        return head;
    }
}

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to delete nodes containing prime numbers
Node* deletePrimes(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* current = head;
    Node* previous = NULL;

    do {
        if (isPrime(current->data)) {
            if (current == head) {
                head = head->next;
                free(current);
                current = head;
                if (current == head) {
                    // The list is now empty
                    break;
                }
            } else {
                previous->next = current->next;
                free(current);
                current = previous->next;
            }
        } else {
            previous = current;
            current = current->next;
        }
    } while (current != head);

    return head;
}


// Function to display the CSLL
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("...\n");
}

int main() {
    Node* head = NULL;
    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printf("Original Circular Singly Linked List:\n");
    displayList(head);

    head = deletePrimes(head);

    printf("Circular Singly Linked List after deleting prime numbers:\n");
    displayList(head);

    return 0;
}
