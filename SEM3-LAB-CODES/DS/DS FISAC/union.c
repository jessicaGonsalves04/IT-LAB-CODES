#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* next;
} node;

node* ins_end(node* start) {
    node* temp = (node*)malloc(sizeof(node));
    int ele;
    printf("Enter ele: ");
    scanf("%d", &temp->info);
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        node* t = start;
        while (t->next != NULL) {
            t = t->next;
        }
        t->next = temp;
    }

    return start;
}

node* traverse(node* start) {
    if (start != NULL) {
        node* temp = start;
        while (temp->next != NULL) {
            printf("%d ", temp->info);
            temp = temp->next;
        }
        printf("%d ", temp->info);
    } else {
        printf("Underflow");
    }
    return start;
}

node* symmdiff(node* s, node* s1, node* s2) {
    int flag;
    node* p = s1;
    node* q = s2;
    node* z = s;

    while (p != NULL) {
        flag = 1;
        q = s2;

        while (q != NULL) {
            if (p->info == q->info) {
                flag = 0;
                break;
            }
            q = q->next;
        }

        if (flag) {
            node* temp = (node*)malloc(sizeof(node));
            temp->info = p->info;
            temp->next = NULL;

            if (s == NULL) {
                s = temp;
                z = s;
            } else {
                z->next = temp;
                z = z->next;
            }
            p = p->next;
            continue;
        }

        p = p->next;
    }

    p = s1;
    q = s2;

    while (q != NULL) {
        flag = 1;
        p = s1;

        while (p != NULL) {
            if (p->info == q->info) {
                flag = 0;
                break;
            }
            p = p->next;
        }

        if (flag) {
            node* temp = (node*)malloc(sizeof(node));
            temp->info = q->info;
            temp->next = NULL;

            if (s == NULL) {
                s = temp;
                z = s;
            } else {
                z->next = temp;
                z = z->next;
            }
        }
        q = q->next;
    }

    return s;
}

int main() {
    node* s1 = NULL;
    node* s2 = NULL;
    node* s = NULL;
    char ch;

    printf("Create sll1:\n");
    do {
        s1 = ins_end(s1);
        printf("Add another node? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y');

    printf("Create sll2:\n");
    do {
        s2 = ins_end(s2);
        printf("Add another node? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y');

    s = symmdiff(s, s1, s2);

    printf("\nsll1: ");
    s1 = traverse(s1);
    printf("\nsll2: ");
    s2 = traverse(s2);
    printf("\nSymmetric Difference: ");
    s = traverse(s);

    return 0;
}
