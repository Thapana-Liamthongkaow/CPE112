//66070503416 Thapaan Liamthongkaow
//Exam 2:Palindrom Creator
#include <stdio.h>
#include <string.h>

void create_palindrome(char str[]) {
    int len = strlen(str);
    char palindrome[len * 2 + 1];

    // Copy the original string to the front
    strcpy(palindrome, str);

    // Create the back part of the palindrome
    for (int i = len - 1; i >= 0; i--) {
        palindrome[len * 2 - 2 - i] = str[i];
    }
    palindrome[len * 2] = '\0';

    printf("%s\n", palindrome);
}

int main() {
    char input[1000000];

    scanf("%[^\n]", input);

    create_palindrome(input);

    return 0;
}

