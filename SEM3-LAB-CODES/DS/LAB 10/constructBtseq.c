#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *lcl;
    struct node *rcl;
} node;

node *newNode(int data) {
    node *temp = (node *)malloc(sizeof(node));
    temp->lcl = temp->rcl = NULL;
    temp->info = data;
    return temp;
}

int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
}

node *createbt(int in[], int pre[], int instart, int inend) {
    static int i = 0;
    if (instart > inend)
        return NULL;

    node *tnode = newNode(pre[i++]);
    // If no children
    if (instart == inend)
        return tnode;
    int inIndex = search(in, instart, inend, tnode->info);

    tnode->lcl = createbt(in, pre, instart, inIndex - 1);
    tnode->rcl = createbt(in, pre, inIndex + 1, inend);
    return tnode;
}

void display(node *root, int level) {
    if (root == NULL)
        return;

    display(root->rcl, level + 1);
    for (int i = 0; i < level; i++) {
        printf("       ");
    }
    printf("%d\n", root->info);
    display(root->lcl, level + 1);
}

int main() {
    int pre[20], inorder[20];
    printf("Enter the preorder sequence\n");
    int i = 0;
    char c;
    int count = 0;
    do {
        count++;
        printf("Enter the element: ");
        scanf("%d", &pre[i]);
        i++;
        printf("Is the sequence completed?(y/n)\n");
        fflush(stdin);
        scanf(" %c", &c);  // Added a space before %c to consume the newline character
    } while (c == 'n');

    printf("Enter the inorder sequence\n");
    int j = 0;
    char d;
    do {
        printf("Enter the element: ");
        scanf("%d", &inorder[j]);
        j++;
        printf("Is the sequence completed?(y/n)\n");
        fflush(stdin);
        scanf(" %c", &d);  // Added a space before %c to consume the newline character
    } while (d == 'n');

    node *root;
    root = createbt(inorder, pre, 0, count - 1);
    printf("\nTree Structure:\n");
    display(root, 0);

    return 0;
}
