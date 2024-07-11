#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* next;
} node;

node* list1 = NULL;
node* list2 = NULL;

node* insert(node* start, int item) {
    node* temp = (node*)malloc(sizeof(node));
    temp->info = item;
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        node* cur = start;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = temp;
    }

    return start;
}

void splitList(node* start) {
    if (start == NULL || start->next == NULL) {
        printf("The linked list is empty or has only one element, nothing to split.\n");
        return;
    }

    list1 = start;
    list2 = start->next;
    
    node* cur1 = list1;
    node* cur2 = list2;

    while (cur1 != NULL && cur2 != NULL) {
        cur1->next = cur2->next;

        if (cur1->next != NULL) {
            cur1 = cur1->next;
            cur2->next = cur1->next;
            cur2 = cur2->next;
        } else {
            cur2->next = NULL;
        }
    }
}
void displayOriginal(node* start) {
    if (start == NULL) {
        printf("Original List is empty.\n");
        return;
    }

    node* cur = start;
    while (cur != NULL) {
        printf("%d\t", cur->info);
        cur = cur->next;
    }
    printf("\n");
}



void display(node* start) {
    if (start == NULL) {
        printf("Nothing to print.\n");
        return;
    }

    node* cur = start;
    while (cur != NULL) {
        printf("%d\t", cur->info);
        cur = cur->next;
    }
    printf("\n");
}

void freeList(node* start) {
    while (start != NULL) {
        node* temp = start;
        start = start->next;
        free(temp);
    }
}

int main() {
    node* start = NULL;
    while (1) {
        int choice, item;
        printf("\nMenu:\n");
        printf("1. Insert elements\n");
        printf("2. Split the list\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                start = insert(start, item);
                break;
            case 3:
                printf("Main List: ");
                displayOriginal(start);
                break;
            case 2:
                list1 = list2 = NULL;
                splitList(start);
                printf("List 1: ");
                display(list1);
                printf("List 2: ");
                display(list2);
                break;
            case 4:
                freeList(start);
                freeList(list1);
                freeList(list2);
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
}
