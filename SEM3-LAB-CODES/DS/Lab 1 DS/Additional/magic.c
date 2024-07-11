#include <stdio.h>

#define MAX 10

int isMagicSquare(int matrix[MAX][MAX], int n) {
    int rowsum, colsum, pd= 0, sd = 0;

    
    for (int i = 0; i < n; i++) {
        pd += matrix[i][i];
    }

    
    for (int i = 0; i < n; i++) {
        sd += matrix[i][n - i - 1];
    }

    
    if (pd != sd) {
        return 0; 
    }

    
    for (int i = 0; i < n; i++) {
        rowsum = 0;
        colsum = 0;

        for (int j = 0; j < n; j++) {
            rowsum += matrix[i][j];
            colsum += matrix[j][i];
        }

        if (rowsum != pd || colsum != pd) {
            return 0; // Not 
        }
    }

    return 1; // a magic square
}

int main() {
    int magicMatrix[MAX][MAX];
    int n;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);

    printf("Enter elements of the square matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &magicMatrix[i][j]);
        }
    }

    printf("Matrix for Magic Square Check:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", magicMatrix[i][j]);
        }
        printf("\n");
    }

    if (isMagicSquare(magicMatrix, n)) {
        printf("The entered square matrix is a magic square.\n");
    } else {
        printf("The entered square matrix is not a magic square.\n");
    }

    return 0;
}
