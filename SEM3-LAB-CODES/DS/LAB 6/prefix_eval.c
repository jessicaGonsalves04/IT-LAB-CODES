#include <stdio.h>
#include <string.h>
#define MAX 50

typedef struct {
    int arr[MAX];
    int top;
} stack;

stack s;
char pfix[MAX];

void push(int value) {
    if (s.top == MAX - 1) {
        printf("Stack is full\n");
        return;
    }
    s.arr[++s.top] = value;
}

int pop() {
    if (s.top == -1) {
        printf("Stack is empty\n");
        return 0;
    }
    return s.arr[s.top--];
}

int operate(int x, int y, char c) {
    switch(c) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/':
            if (y != 0) {
                return x / y;
            } else {
                printf("Division by zero\n");
                return 0;
            }
    }
    return 0;
}

void eval_prefix(){
    
    int op1, op2, result;
    printf("Enter the prefix expression: ");
    fflush(stdin);
    gets(pfix);

    s.top = -1;
    int i;
    int l=strlen(pfix);
    for (i=l-1;i>=0;i--) {
        if (pfix[i] >= '0' && pfix[i] <= '9') {
            push(pfix[i] - '0'); // Convert character to integer
        } else if (pfix[i] == '+' || pfix[i] == '-' || pfix[i] == '*' || pfix[i] == '/') {
            op1 = pop();
            op2 = pop();
            result = operate(op1, op2, pfix[i]);
            push(result);
        }
    }

    if (s.top == 0) {
        result = pop();
        printf("Result: %d\n", result);
    } else {
        printf("Invalid prefix expression\n");
    }
}


int main() {
    char ch;
    do {
        eval_prefix();
        printf("Do you wish to continue(y/n)? ");
        scanf(" %c", &ch);
        //fflush(stdin);
    } while (ch == 'y');
    return 0;
}



