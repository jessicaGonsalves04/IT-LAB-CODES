#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char arr[MAX][MAX];
    int top;
} stack;

stack s;

void push(char c[]) {
    if (s.top == MAX - 1) {
        printf("Stack is full.\n");
        return;
    }
    strcpy(s.arr[++s.top], c);
}

void pop() {
    if (s.top == -1) {
        printf("Stack underflow.\n");
        return;
    }
    s.top--;
}

int countMissingTags() {
    int count = 0;
    char input[MAX];
    s.top = -1;
    
    printf("Enter the input string (end with #):\n");
    gets(input);
    
    int i = 0;
    char tag[MAX];
    while (input[i] != '#') {
        if (input[i] == '<') {
            i++;
            int j = 0;
            while (input[i] != '>' && input[i] != '\0') {
                tag[j++] = input[i++];
            }
            tag[j] = '\0';

            if (tag[0] == '/') {
                if (s.top == -1) {
                    count++;
                } else if (strcmp(s.arr[s.top], tag + 1) != 0) {
                    count++;
                } else {
                    pop();
                }
            } else {
                push(tag);
            }
        }
        i++;
    }

    while (s.top >= 0) {
        count++;
        pop();
    }

    return count;
}

int main() {
    int missingTagsCount = countMissingTags();
    printf("Count of missing or invalid tags: %d\n", missingTagsCount);
    return 0;
}
