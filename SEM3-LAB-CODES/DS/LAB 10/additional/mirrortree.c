#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct TreeNode {
    int info;
    struct TreeNode* lcl;
    struct TreeNode* rcl;
} TreeNode;

// Function to create a binary tree node
TreeNode* createbt(TreeNode* root) {
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    printf("Enter element: ");
    scanf("%d", &temp->info);
    temp->lcl = temp->rcl = NULL;

    if (root == NULL) {
        return temp;
    }

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
        return root;
    }

    if (d[i - 1] == 'l') {
        parent->lcl = temp;
    } else {
        parent->rcl = temp;
    }

    return root;
}

// Function to check if a binary tree is a mirror tree
int isMirror(TreeNode* root1, TreeNode* root2) {
    // If both trees are empty, they are mirror images.
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }

    // If one of the trees is empty, they are not mirror images.
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }

    // Check if the current nodes have the same value and
    // if their subtrees are mirror images of each other.
    return (root1->info == root2->info) &&
           isMirror(root1->lcl, root2->rcl) &&
           isMirror(root1->rcl, root2->lcl);
}

int main() {
    TreeNode* root = NULL;
    char choice;

    do {
        root = createbt(root);

        printf("Do you want to create another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    if (isMirror(root, root)) {
        printf("The binary tree is a mirror tree.\n");
    } else {
        printf("The binary tree is not a mirror tree.\n");
    }

    return 0;
}
