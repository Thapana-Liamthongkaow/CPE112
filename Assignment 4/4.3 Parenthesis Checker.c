//66070503416 Thapana Liamthongkaow
//Assignment 4.3 Parenthesis Checker
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

struct Stack {
    char items[MAX_LENGTH];
    int top;
};

void initialize(struct Stack *stack) {
    stack->top = -1;
}

void push(struct Stack *stack, char item) {
    stack->items[++stack->top] = item;
}

char pop(struct Stack *stack) {
    return stack->items[stack->top--];
}

bool isBalanced(char str[]) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(&stack, str[i]);
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (stack.top == -1) {
                return false;
            } else {
                char popped = pop(&stack);
                if ((str[i] == ')' && popped != '(') ||
                    (str[i] == '}' && popped != '{') ||
                    (str[i] == ']' && popped != '[')) {
                    return false;
                }
            }
        }
    }

    return stack.top == -1; // Check if the stack is empty at the end
}

int main() {
    char input[MAX_LENGTH];
    scanf("%s", input);

    if (isBalanced(input)) {
        printf("The string is balanced\n");
    } else {
        printf("The string is not balanced\n");
    }

    return 0;
}

