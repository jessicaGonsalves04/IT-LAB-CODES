#include <stdio.h>
#include <stdlib.h>

// Define a singly linked list node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to add a new node to the end of a linked list
Node* insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        return head;
    }
}

// Function to find the symmetric difference between two singly linked lists
Node* symmetricDifference(Node* listA, Node* listB) {
    Node* currentA = listA;
    Node* currentB = listB;
    Node* resultA = NULL;
    Node* resultB = NULL;

    while (currentA != NULL && currentB != NULL) {
        if (currentA->data < currentB->data) {
            resultA = insert(resultA, currentA->data);
            currentA = currentA->next;
        } else if (currentB->data < currentA->data) {
            resultB = insert(resultB, currentB->data);
            currentB = currentB->next;
        } else {
            // Skip common elements
            currentA = currentA->next;
            currentB = currentB->next;
        }
    }

    // Add any remaining elements in listA to resultA
    while (currentA != NULL) {
        resultA = insert(resultA, currentA->data);
        currentA = currentA->next;
    }

    // Add any remaining elements in listB to resultB
    while (currentB != NULL) {
        resultB = insert(resultB, currentB->data);
        currentB = currentB->next;
    }

    // Merge elements in resultA and resultB
    Node* currentResult = resultA;
    while (currentResult->next != NULL) {
        currentResult = currentResult->next;
    }
    currentResult->next = resultB;

    return resultA;
}

// Function to display a linked list
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* listA = NULL;
    Node* listB = NULL;

    int n, data;

    // Take user input to create listA
    printf("Enter the number of elements for List A: ");
    scanf("%d", &n);
    printf("Enter elements for List A:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        listA = insert(listA, data);
    }

    // Take user input to create listB
    printf("Enter the number of elements for List B: ");
    scanf("%d", &n);
    printf("Enter elements for List B:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        listB = insert(listB, data);
    }

    printf("List A: ");
    displayList(listA);

    printf("List B: ");
    displayList(listB);

    Node* result = symmetricDifference(listA, listB);

    printf("Symmetric Difference: ");
    displayList(result);

    // Free memory (you can add a freeList function if needed)

    return 0;
}
