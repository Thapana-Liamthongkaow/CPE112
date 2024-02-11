//66070503416 Thapana Liamthongkaow
//Assignment 4.4 Infix to Postfix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int top;
    char items[MAX_SIZE];
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = item;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

int getPrecedence(char operator) {
    if (operator == '^')
        return 3;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else
        return -1;  // Invalid operator
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack operatorStack;
    initialize(&operatorStack);
    int i, j;
    char token;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        token = infix[i];

        if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(&operatorStack, token);
        } else if (token == ')') {
            while (!isEmpty(&operatorStack) && operatorStack.items[operatorStack.top] != '(') {
                postfix[j++] = pop(&operatorStack);
            }
            pop(&operatorStack);
        } else {
            while (!isEmpty(&operatorStack) && getPrecedence(operatorStack.items[operatorStack.top]) >= getPrecedence(token)) {
                postfix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, token);
        }
    }

    while (!isEmpty(&operatorStack)) {
        postfix[j++] = pop(&operatorStack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    printf("%s\n", postfix);

    return 0;
}

