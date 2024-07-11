#include <stdio.h>
#define MAX 20

typedef struct {
    char arr[50];
    int top;
} stack;

stack s;

char infix[50], pfix[50];

void push(char symbol) {
    if (s.top == MAX - 1) {
        printf("Stack is full\n");
        return;
    } else
        s.arr[++s.top] = symbol;
}

char pop() {
    if (s.top == -1) {
        printf("Stack underflow.\n");
        return '#';
    } else
        return (s.arr[s.top--]);
}

void read() {
    printf("Enter the infix expression:\n");
    scanf("%s", infix);
    //fflush(stdin);
}

int isNotEmpty() {
    if (s.top == -1)
        return 0;
    else
        return 1;
}

int prec(char symbol) {
    switch (symbol) {
        case '/':
        case '*':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
            return 0;
        default:
            return -1;
     }
}

void convert() {
    int i, precedence, p;
    char e1, e2;
    p = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        e1 = infix[i];
        switch (e1) {
            case '(':
                push(e1);
                break;
            case ')':
                while ((e2 = pop()) != '(')
                    pfix[p++] = e2;
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while (isNotEmpty() && prec(e1) <= prec(s.arr[s.top])) {
                    e2 = pop();
                    pfix[p++] = e2;
                }
                push(e1);
                break;
            default:
                pfix[p++] = e1;
                break;
        }
    }
    while (isNotEmpty())
        pfix[p++] = pop();
    pfix[p] = '\0';
    printf("The postfix expression is: %s\n", pfix);
}

int main() {
    char ch;
    do {
        read();
        convert();
        printf("Do you wish to continue(y/n)? ");
        scanf(" %c", &ch);
    } while (ch == 'y');
    return 0;
}






