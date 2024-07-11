#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;


Node *insertAtEnd(Node *start, int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev=NULL;
    if (start == NULL) {
        newNode->prev = NULL;
        start = newNode;
    } else {
        Node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    return start;
}


Node *deleteFromEnd(Node *start) {
    if (start == NULL) {
        printf("List is empty. Nothing to delete.\n");
    } else if (start->next == NULL) {
        printf("Element Deleted is: %d\n", start->data);
        free(start);
        start = NULL;
    } else {
        Node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        printf("Element Deleted is: %d\n", temp->data);
        temp->prev->next = NULL;
        free(temp);
    }

    return start;
}


Node *insertAtPosition(Node *start, int data, int position) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if (start == NULL) {
        newNode->prev = newNode->next = NULL;
        start = newNode;
    } else if (position <= 1) {
        newNode->next = start;
        newNode->prev = NULL;
        start->prev = newNode;
        start = newNode;
    } else {
        Node *temp = start;
        int count = 1;

        while (count < position - 1 && temp->next != NULL) {
            temp = temp->next;
            count++;
        }

        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    return start;
}


Node *insertAfterElement(Node *start, int data, int element) {
    if (start == NULL) {
        printf("List is empty. Cannot insert.\n");
        return start;
    }

    Node *temp = start;
    while (temp != NULL) {
        if (temp->data == element) {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = data;
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            return start;
        }
        temp = temp->next;
    }

    printf("Element not found.\n");
    return start;
}


Node *insertBeforeElement(Node *start, int data, int element) {
    if (start == NULL) {
        printf("List is empty.\n");
        return start;
    }

    Node *temp = start;
    while (temp != NULL) {
        if (temp->data == element) {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = data;
            newNode->next = temp;
            newNode->prev = temp->prev;
            if (temp->prev != NULL) {
                temp->prev->next = newNode;
            }
            temp->prev = newNode;

            if (temp == start) {
                start = newNode;
            }

            return start;
        }
        temp = temp->next;
    }

    printf("Element not found.\n");
    return start;
}

// Function to reverse the list
Node *reverseList(Node *start) {
    Node *temp = NULL;
    Node *current = start;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        start = temp->prev;
    }

    return start;
}

// Function to traverse and display the list
void traverseList(Node *start) {
    if (start == NULL) {
        printf("List is empty.\n");
    } else {
        Node *temp = start;
        printf("List elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Node *start = NULL;
    int choice, data, position, element;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert  end of the list\n");
        printf("2. Delete element from the rear end\n");
        printf("3. Insert an element at a given position \n");
        printf("4. Delete an element from a given position \n");
        printf("5. Insert  after \n");
        printf("6. Insert before\n");
        printf("7. Traverse \n");
        printf("8. Reverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                start = insertAtEnd(start, data);
                break;
            case 2:
                start = deleteFromEnd(start);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                start = insertAtPosition(start, data, position);
                break;
            case 4:
                // Implement deletion from a given position
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                // Implement the function for deletion from a given position
                break;
            case 5:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element after which to insert: ");
                scanf("%d", &element);
                start = insertAfterElement(start, data, element);
                break;
            case 6:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                printf("Enter the element before which to insert: ");
                scanf("%d", &element);
                start = insertBeforeElement(start, data, element);
                break;
            case 7:
                traverseList(start);
                break;
            case 8:
                start = reverseList(start);
                break;
            case 9:
                printf("Exit\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
