#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}


Node* insertAtEnd(Node* start, int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
 temp->prev = temp->next = NULL;

    if (start == NULL) {
        return temp;
    }

    Node* cur= start;
    while (cur->next != NULL) {
        cur = cur->next;
    }

    cur->next = temp;
    temp->prev = cur;

    return start;
}

// Function to display a doubly linked list
void display(Node* start) {
    Node* current = start;
    while (current != NULL) {
        printf("%d  ", current->data);
        current = current->next;
    }
    
}

// Function to find the union of two doubly linked lists
Node* unionList(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* temp1 = list1;
    Node* temp2 = list2;

    while (temp1 != NULL) {
        result = insertAtEnd(result, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        if (!search(result, temp2->data)) {
            result = insertAtEnd(result, temp2->data);
        }
        temp2 = temp2->next;
    }

    return result;
}


int search(Node* start, int data) {
    Node* current = start;
    while (current != NULL) {
        if (current->data == data) {
            return 1; // Node found
        }
        current = current->next;
    }
    return 0; // Node not found
}

// Function to find the intersection of two doubly linked lists
Node* intersection(Node* list1, Node* list2) {
    Node* result = NULL;
    Node* temp1 = list1;

    while (temp1 != NULL) {
        if (search(list2, temp1->data)) {
            result = insertAtEnd(result, temp1->data);
        }
        temp1 = temp1->next;
    }

    return result;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    int n, data;

    // Input for list1
    printf("Enter the number of elements in list1: ");
    scanf("%d", &n);
    printf("Enter elements for list1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        list1 = insertAtEnd(list1, data);
    }

    // Input for list2
    printf("Enter the number of elements in list2: ");
    scanf("%d", &n);
    printf("Enter elements for list2:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        list2 = insertAtEnd(list2, data);
    }

    printf("List 1: ");
    display(list1);
    printf("\n");

    printf("List 2: ");
    display(list2);
    printf("\n");

    // Union of lists
    Node* unionResult = unionList(list1, list2);
    printf("Union: ");
    display(unionResult);
    printf("\n");

    // Intersection of lists
    Node* intersectionResult = intersection(list1, list2);
    printf("Intersection: ");
    display(intersectionResult);
    printf("\n");

    return 0;
}
