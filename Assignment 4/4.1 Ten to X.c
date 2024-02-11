//66070503416 Thapana Liamthongkaow
//Assignment 4.1 Ten to X
#include <stdio.h>

int isValidDigit(char digit, int base) {
    if (digit >= '0' && digit <= '9') {
        return digit - '0' < base;
    } else if (digit >= 'A' && digit <= 'Z') {
        return digit - 'A' + 10 < base;
    } else {
        return 0;
    }
}

void decimalToBaseX(int n, int x) {
    if (x < 2 || x > 36) {
        printf("invalid\n");
        return;
    }

    if (n == 0) {
        printf("0\n");
        return;
    }

    char result[32];
    int index = 0;

    while (n > 0) {
        int remainder = n % x;
        char digit;

        if (remainder < 10) {
            digit = remainder + '0';
        } else {
            digit = remainder - 10 + 'A';
        }

        result[index++] = digit;
        n /= x;
    }
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }

    printf("\n");
}

int main() {
    int n, x;

    scanf("%d", &n);
    scanf("%d", &x);

    decimalToBaseX(n, x);

    return 0;
}

