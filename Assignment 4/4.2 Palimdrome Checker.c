//66070503416 Thapana Liamthogkaow
//Assignment 4.2 Palimdrome Checker
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void push(char stack[], char item, int *top) {
    if (*top < MAX_LENGTH - 1) {
        stack[++(*top)] = item;
    }
}

char pop(char stack[], int *top) {
    if (*top >= 0) {
        return stack[(*top)--];
    } else {
        return '\0';
    }
}

int is_palindrome(char sequence[]) {
    int length = strlen(sequence);
    char stack[MAX_LENGTH];
    int top = -1;

    for (int i = 0; i < length; i++) {
        push(stack, sequence[i], &top);
    }

    for (int i = 0; i < length; i++) {
        if (sequence[i] != pop(stack, &top)) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}

int main() {
    char sequence[MAX_LENGTH];

    fgets(sequence, MAX_LENGTH, stdin);
    sequence[strcspn(sequence, "\n")] = '\0';
    if (is_palindrome(sequence)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}

