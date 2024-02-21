//66070503416 Thapana Liamthongkaow
//Lab 5.2 When Will It Be  My Turn
#include<stdio.h>
#include<string.h>

void insertq(int *queue, int val);
void dequeue(int *queue);
void show(int *queue);

int front = -1, rear = -1;
int max_size = 0;

int main(){
    int val;
    char option;
    scanf("%d",&max_size);
    if(max_size<1 || max_size>10){
        return 0;
    }
    int queue[max_size];

    while(scanf(" %c",&option)==1){
        switch(option){
            case 'I':
                scanf("%d",&val);
                if(front != (rear + 1)%max_size){
                    insertq(queue, val);
                }
                else{
                    printf("Queue is full!!\n");
                }
                break;
            case 'D':
                dequeue(queue);
                break;
            case 'S':
                show(queue);
                break;
            case 'E':
                return 0;
            default:
                continue;
        }
    }
}

void insertq(int *queue, int val){
    if(front == (rear + 1) % max_size){
        printf("Queue is full!!\n");
        return;
    }
    else{
        if(front == -1 && rear == -1){
            front = rear = 0;
            queue[rear] = val;    
        }
        else{
            rear = (rear + 1) % max_size;
            queue[rear] = val;
        }
    }
}

void dequeue(int *queue){
    int val = queue[front];
    if(front == -1 && rear == -1){
        printf("Queue is empty!!\n");
        return;
    }
    else{
        if(front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1) % max_size;
        }
        printf("%d\n",val);
    }
}

void show(int *queue){
    if(front == -1 && rear == -1){
        printf("Queue is empty!!\n");
        return;
    }
    else{
        printf("Front: %d\n",front);
        printf("Items: ");
        if(front != -1 && rear != -1 && front == rear){
            printf("%d",queue[front]);
        }
        else{
            for(int i=front;i!=rear;i = (i+1) % max_size){
                printf("%d ",queue[i]);
            }
            printf("%d",queue[rear]);
        }
        printf("\nRear: %d\n",rear);
    }
}