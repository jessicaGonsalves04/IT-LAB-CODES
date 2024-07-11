#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] > target) {
            return binarySearch(arr, low, mid - 1, target);
        }
        return binarySearch(arr, mid + 1, high, target);
    }

    return -1;
}

int main() {
    int n, target, found=0, pos;

    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int arr[n];

    printf("\nEnter the elements: ");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to be found :");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at position %d.\n", result+1);
    }

    return 0;
}

