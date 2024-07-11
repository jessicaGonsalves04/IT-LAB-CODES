#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    return head;
}

void reversePositions(Node* head) {
    Node* front = head;
    Node* back = head;

    // Move the back pointer to the end
    while (back->next != NULL) {
        back = back->next;
    }

    // Swap values while moving towards each other
    while (front != back && front->prev != back) {
        int temp = front->data;
        front->data = back->data;
        back->data = temp;

        front = front->next;
        back = back->prev;
    }
}

void displayList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    for (int i = 1; i <= 5; i++) {
        head = insert(head, i);
    }

    printf("Original Line: ");
    displayList(head);

    reversePositions(head);

    printf("Reversed Line: ");
    displayList(head);

    return 0;
}
