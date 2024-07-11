#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

Node* concatenate(Node* X1, Node* X2) {
    if (X1 == NULL) {
        return X2;
    }
    if (X2 == NULL) {
        return X1;
    }

    // Find the last node of X1
    Node* last = X1;
    while (last->next != NULL) {
        last = last->next;
    }

    // Concatenate X2 to X1
    last->next = X2;
    X2->prev = last;

    return X1;
}


void display(Node* start) {
    Node* current = start;
    while (current != NULL) {
        printf("%d  ", current->data);
        current = current->next;
    }

}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    int n, data;

    // Input for X1
    printf("Enter the number of elements in List1: ");
    scanf("%d", &n);
    printf("Enter elements for List1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        Node* newNode = createNode(data);
        list1 = concatenate(list1, newNode);
    }

    // Input for X2
    printf("Enter the number of elements in List2: ");
    scanf("%d", &n);
    printf("Enter elements for List2:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        Node* newNode = createNode(data);
        list2 = concatenate(list2, newNode);
    }

    // Concatenate X2 to X1
    list1 = concatenate(list1, list2);

    printf("Concatenated List: \n");
    display(list1);

    return 0;
}
