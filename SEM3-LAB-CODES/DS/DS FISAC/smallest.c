#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node.
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new doubly linked list node.
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of a doubly linked list.
Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to delete the node with the smallest key element.
Node* deleteSmallestNode(Node* head) {
    if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return NULL;
    }

    Node* current = head;
    Node* smallestNode = head;
    int smallestKey = head->data;

    // Traverse the list to find the smallest key element.
    while (current != NULL) {
        if (current->data < smallestKey) {
            smallestKey = current->data;
            smallestNode = current;
        }
        current = current->next;
    }

    // Update the pointers to remove the smallest node from the list.
    if (smallestNode == head) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        smallestNode->prev->next = smallestNode->next;
        if (smallestNode->next != NULL) {
            smallestNode->next->prev = smallestNode->prev;
        }
    }

    // Free the memory associated with the deleted node.
    free(smallestNode);

    return head;
}

// Function to display the doubly linked list.
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        head = insertEnd(head, data);
    }

    printf("Original List:\n");
    displayList(head);

    head = deleteSmallestNode(head);

    printf("List after deleting the smallest element:\n");
    displayList(head);

    return 0;
}
