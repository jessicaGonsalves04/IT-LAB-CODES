#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct TreeNode {
    int info;
    struct TreeNode* lcl;
    struct TreeNode* rcl;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->info = data;
    newNode->lcl = newNode->rcl = NULL;
    return newNode;
}

TreeNode* createBinaryTree() {
    TreeNode* root = NULL;
    char choice;

    do {
        TreeNode* temp = createNode(0);
        printf("Enter element: ");
        scanf("%d", &temp->info);
        temp->lcl = temp->rcl = NULL;

        if (root == NULL) {
            root = temp;
        } else {
            char d[MAX];
            printf("Enter path: ");
            scanf("%s", d);

            TreeNode* current = root;
            TreeNode* parent = NULL;
            int i;

            for (i = 0; i < strlen(d); i++) {
                if (current == NULL) {
                    break;
                }
                parent = current;

                if (d[i] == 'l') {
                    current = current->lcl;
                } else {
                    current = current->rcl;
                }
            }

            if (current != NULL || i != strlen(d)) {
                printf("Invalid path: i = %d, len = %d\n", i, (int)strlen(d));
                free(temp);
            } else {
                if (d[i - 1] == 'l') {
                    parent->lcl = temp;
                } else {
                    parent->rcl = temp;
                }
            }
        }

        printf("Do you want to create another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return root;
}

// Function to display the binary tree using in-order traversal
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->lcl);
        printf("%d ", root->info);
        inorderTraversal(root->rcl);
    }
}

TreeNode* copyBinaryTree(TreeNode* source) {
    if (source == NULL) {
        return NULL;
    }

    TreeNode* copy = createNode(source->info);
    copy->lcl = copyBinaryTree(source->lcl);
    copy->rcl = copyBinaryTree(source->rcl);

    return copy;
}

int main() {
    TreeNode* root = createBinaryTree();

    printf("In-order traversal of the created binary tree: ");
    inorderTraversal(root);
    printf("\n");

    TreeNode* copy = copyBinaryTree(root);

    printf("In-order traversal of the copied binary tree: ");
    inorderTraversal(copy);
    printf("\n");

    return 0;
}
