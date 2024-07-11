#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct node {
    int info;
    struct node *lcl, *rcl;
} node;

node* createbt(node *root) {
    node *temp = (node*)malloc(sizeof(node));
    
    printf("Enter element: ");
    scanf("%d", &temp->info);
    temp->lcl = temp->rcl = NULL;

    if (root == NULL) {
        root = temp;
        return root;
    }

    char d[MAX];
    printf("Enter the directions:\n");
    scanf("%s", d);

    node *c = root, *p = NULL;
    int i;

    for (i = 0; i < strlen(d); i++) {
        if (c == NULL) {
            printf("Invalid path: %s\n", d);
            free(temp);
            return root;
        }

        p = c;
        if (d[i] == 'l') {
            c = c->lcl;
        } else {
            c = c->rcl;
        }
    }

    if (c != NULL || i != strlen(d)) {
        printf("Invalid path: %s\n", d);
        free(temp);
        return root;
    }

    if (d[i - 1] == 'l') {
        p->lcl = temp;
    } else {
        p->rcl = temp;
    }

    return root;
}

void display(node *root, int level) {
    if (root == NULL) {
        return;
    }

    display(root->rcl, level + 1);

    for (int i = 0; i < level; i++) {
        printf("\t");
    }

    printf("%d\n", root->info);

    display(root->lcl, level + 1);
}

int main() {
    node *root = NULL;
    char ch;

    printf("Create Binary tree:\n");
    do {
        root = createbt(root);
        printf("Do you wish to add another node (y/n): ");
        fflush(stdin);
        scanf(" %c", &ch);
    } while (ch == 'y');

    int level;
    printf("Enter the level of the tree: ");
    scanf("%d", &level);
    display(root, level);

    return 0;
}
