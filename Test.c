#include <cs509.h>
#include <stdio.h>

int main (){
    int n = get_int("Number: ");
    if (n % 2 == 0){
        printf("Even\n");
    }
    else{
        printf("Odd\n");
    }
}