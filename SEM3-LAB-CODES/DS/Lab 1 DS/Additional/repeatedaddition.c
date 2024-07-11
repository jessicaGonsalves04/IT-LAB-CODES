#include <stdio.h>


int multiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a + multiply(a, b - 1);
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int result = multiply(num1, num2);

    printf("Multiplication result: %d\n", result);

    return 0;
}

