#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char info;
    struct node *lcl;
    struct node *rcl;
} node;

typedef struct stack {
    int top;
    node *arr[100];
} stack;

stack stk;

void push(node *ele) {
    if (stk.top == 99) {
        printf("Stack Overflow\n");
        return;
    }
    stk.arr[++stk.top] = ele;
}

node *pop() {
    if (stk.top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stk.arr[stk.top--];
}

int isempty() {
    return (stk.top == -1);
}

/*void display() {
    if (isempty()) {
        printf("Stack is empty\n");
        return;
    }
    int i = stk.top;
    while (i >= 0) {
        printf("%p\t", (void *)stk.arr[i--]);
    }
    printf("\n");
}/**/

void itr_inorder(node *root) {
    for (;;) {
        for (; root; root = root->lcl) {
            push(root);
        }
        root = pop();
        if (!root) {
            break;
        }
        printf("%c  ", root->info);
        root = root->rcl;
    }
}

void displaytree(node *root, int level) {
    if (root == NULL)
        return;
    displaytree(root->rcl, level + 1);
    for (int i = 0; i < level; i++) {
        printf("       ");
    }
    printf("%c\n", root->info);
    displaytree(root->lcl, level + 1);
}

node *create(char info) {
    node *temp = malloc(sizeof(node));
    temp->info = info;
    temp->lcl = temp->rcl = NULL;
    return temp;
}

node *expressiontree(node *root) {
    char s[100];
    printf("Enter PostFix: ");
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*') {
            node *temp = create(s[i]);
            node *e2 = pop();
            node *e1 = pop();
            temp->lcl = e1;
            temp->rcl = e2;
            push(temp);
        } else {
            push(create(s[i]));
        }
    }
    return pop(); // Return the final root of the expression tree
}


int main() {
    node *root = NULL;
    stk.top = -1;
    node *t = expressiontree(root);
    displaytree(t, 0);
    itr_inorder(t);

    return 0;
}
