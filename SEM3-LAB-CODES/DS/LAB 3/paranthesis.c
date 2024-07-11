#include <stdio.h>
#include <string.h>
#define MAX 20

typedef struct {
    char arr[MAX];
    int top;
} stack;

stack s;

void push(char c) {
    if (s.top == MAX - 1) {
        printf("Stack is full.");
        return;
    }
    s.arr[++s.top] = c;
}

char pop() {
    char ch;
    if (s.top == -1) {
        printf("Stack underflow.");
        return '\0'; 
    }
    ch = s.arr[s.top--];
    return ch;
}

int main() {
    int l;
    s.top = -1;
    char str[30], ele;
    printf("Enter a string:");
    gets(str);
    l = strlen(str);
    for (int i = 0; i < l; i++) {
        if (str[i] == '(') {
            push(str[i]);
        } else if (str[i] == ')') {
            ele = pop();
            if (ele == '\0') {
                printf("Unbalanced.");
                return 0; 
            }
        }
    }

    if (s.top == -1) {
        printf("Balanced.");
    } else {
        printf("Unbalanced.");
    }
    return 0;
}

