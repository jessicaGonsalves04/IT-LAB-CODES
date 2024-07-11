#include <stdio.h>
#define MAX 100

typedef struct {
    int top;
    int arr[MAX];
} stack;

stack s;

void push(int n) {
    if (s.top == MAX - 1) {
        printf("Stack overflow.\n");
        return;
    }
    s.arr[++s.top] = n;
}

void pop() {
    if (s.top == -1) {
        printf("Stack underflow.\n");
        return;
    }
    if (s.arr[s.top] <= 9)
        printf("%d", s.arr[s.top--]);
    else if (s.arr[s.top] >= 65 && s.arr[s.top] <= 70)
        printf("%c", s.arr[s.top--]);
}

int main() {
    s.top = -1;
    int choice, num;
    while(1){
    printf("\n1. Decimal to binary\n2. Decimal to Octal\n3. Decimal to Hexadecimal\n4.Exit  ");
    scanf("%d", &choice);
    if(choice==4)
        break;
    printf("\nEnter the number: ");
    scanf("%d", &num);
    switch (choice) {
        case 1:
            while (num != 0) {
                int n = num % 2;
                push(n);
                num = num / 2;
            }
            printf("The binary equivalent is: ");
            while (s.top != -1)
                pop();
            break;

        case 2:
            while (num != 0) {
                int n = num % 8;
                push(n);
                num = num / 8;
            }
            printf("The Octal equivalent is: ");
            while (s.top != -1)
                pop();
            break;

        case 3:
            while (num != 0) {
                int n = num % 16;
                if (n <= 9)
                    push(n);
                else {
                    switch (n) {
                        case 10:
                            push(65);
                            break;
                        case 11:
                            push(66);
                            break;
                        case 12:
                            push(67);
                            break;
                        case 13:
                            push(68);
                            break;
                        case 14:
                            push(69);
                            break;
                        case 15:
                            push(70);
                            break;
                    }
                }
                num = num / 16;
            }
            printf("The Hexadecimal equivalent is: ");
            while (s.top != -1)
                pop();
            break;

        default:
            printf("Invalid input\n");
            break;
    }
    }
    return 0;
}
