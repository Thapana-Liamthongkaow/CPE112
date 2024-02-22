//66070503416 Thapana Liamthongkaow
//Lab 4.3 Tower of Hanoi

#include <stdio.h>

int totalMoves = 0;

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        totalMoves++;
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary);
    totalMoves++;
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int numDisks;

    // Get the number of disks from the user

    scanf("%d", &numDisks);

    // Reset the totalMoves variable
    totalMoves = 0;

    // Call the towerOfHanoi function
    towerOfHanoi(numDisks, 'A', 'B', 'C');

    // Output the total number of moves
    printf("Total moves: %d\n", totalMoves);

    return 0;
}
