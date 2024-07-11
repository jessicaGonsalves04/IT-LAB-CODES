#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[10][10], b[10][10], c[10][10];
    int m, n, p, q, i, j, k;

    printf("Enter the dimensions of the first matrix (m x n):\n");
    scanf("%d%d", &m, &n);

    printf("Enter the dimensions of the second matrix (p x q):\n");
    scanf("%d%d", &p, &q);

    if (n != p) {
        printf("Matrix dimensions are incompatible for multiplication. Columns of the first matrix must be equal to rows of the second matrix.\n");
        return 1; // Exit with an error code
    }

    printf("Enter the elements of matrix 1:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the elements of matrix 2:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            c[i][j] = 0;
            for (k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("The product of the matrices is:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
