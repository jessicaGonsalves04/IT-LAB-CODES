#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a binary tree
TreeNode* createTree() {
    TreeNode* root = NULL;
    int val;
    printf("Enter the value of the root node (or 0 to exit): ");
    scanf("%d", &val);
    if (val == 0) {
        return NULL;
    }
    root = (TreeNode*)malloc(sizeof(TreeNode));
    root->val = val;
    printf("Enter the left subtree for node %d:\n", val);
    root->left = createTree();
    printf("Enter the right subtree for node %d:\n", val);
    root->right = createTree();
    return root;
}

// Function to check the equality of two binary trees
int isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) {
        return 1;
    }
    if (p == NULL || q == NULL) {
        return 0;
    }
    if (p->val != q->val) {
        return 0;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    printf("Enter the first tree:\n");
    TreeNode* root1 = createTree();

    printf("Enter the second tree:\n");
    TreeNode* root2 = createTree();

    int result = isSameTree(root1, root2);
    if (result) {
        printf("The two trees are equal.\n");
    } else {
        printf("The two trees are not equal.\n");
    }

    return 0;
}
