#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_NAME_LENGTH 50

char queue[MAX_SIZE][MAX_NAME_LENGTH];
int front = -1, rear = -1;

int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

int isEmpty() {
    return front == -1;
}
//Enqueue Function
void enqueue(char name[]) {
    if (isFull()) {
        printf("Queue overflow\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % MAX_SIZE;
    strcpy(queue[rear], name);
    printf("%s enqueued to queue\n", name);
}
//Dequque Funtion
char* dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return NULL;
    }

    char* name = queue[front]; 
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }

    return name; 
}
//Display Queue Function
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    int count=0;
    printf("Queue elements:\n");
    for (; i != rear; i = (i + 1) % MAX_SIZE) {
        printf("%s\n", queue[i]);
        count++;
    }
    printf("%s\n", queue[rear]);
    printf("Total queue : %d\n", count+1);
}
//Main
int main() {
    int choice, num_names, num_dequeue;
    char name[MAX_NAME_LENGTH];

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue name\n");
        printf("2. Dequeue name\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of names to enqueue: ");
                scanf("%d", &num_names);
                if(num_names > MAX_SIZE){
                    printf("Stack Overflow!\n");
                    break;
                }
                for (int i = 0; i < num_names; i++) {
                    printf("Enter name %d: ", i + 1);
                    scanf(" %s", name);
                    enqueue(name);
                }
                break;
            case 2:
                printf("Enter the number of names to dequeue: ");
                scanf("%d", &num_dequeue);
                for (int i = 0; i < num_dequeue; i++) {
                    char* dequeued_name = dequeue();
                    if (dequeued_name != NULL) {
                        printf("Dequeued name: %s\n", dequeued_name);
                    }
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}