#include <stdio.h>


int findMinIndex(int arr[], int start, int end) {
    int minIndex = start;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    return minIndex;
}


void recursiveSelectionSort(int arr[], int start, int end) {
    if (start < end) {

        int minIndex = findMinIndex(arr, start, end);

        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;

        recursiveSelectionSort(arr, start + 1, end);
    }
}

int main() {
    int n;

    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("\nEnter the elements: ");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    recursiveSelectionSort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

