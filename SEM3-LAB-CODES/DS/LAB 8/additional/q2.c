#include <stdio.h>
#include <string.h>

// Function to add two long positive integers
char* addLongIntegers(const char* num1, const char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxSize = len1 > len2 ? len1 : len2;

    // Create character arrays to store the result and intermediate sum
    char result[maxSize + 2];  // +2 for possible carry and null-terminator
    char temp[maxSize + 2];

    int carry = 0;
    int i = len1 - 1;
    int j = len2 - 1;
    int k = maxSize + 1;

    // Initialize result with null-terminator
    result[maxSize + 1] = '\0';

    // Process digits from right to left
    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;

        carry = sum / 10;
        temp[k] = (sum % 10) + '0';

        i--;
        j--;
        k--;
    }

    // Check if there is a carry left
    if (carry > 0) {
        temp[k] = carry + '0';
        k--;
    }

    // Copy the result to the final result array
    strcpy(result, &temp[k + 1]);

    return strdup(result);  // Allocate memory for the result and return
}

int main() {
    char num1[1000];  // Adjust the size as needed
    char num2[1000];

    printf("Enter the first long positive integer: ");
    scanf("%s", num1);
    printf("Enter the second long positive integer: ");
    scanf("%s", num2);

    char* sum = addLongIntegers(num1, num2);
    printf("Sum: %s\n", sum);

    return 0;
}
