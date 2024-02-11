//66070503416 Thapana Liamthongkaow
//Lab 2.5 List Slicing

#include <stdio.h>

int main(void){
    int size, flag = 0;
    scanf("%d", &size);

    int arr[size];
    for(int i = 0 ; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int start,stop,step;
    scanf("%d %d %d", &start, &stop, &step);
    int isIncrease = 0;

    if(step == 0 || size == 0 || start == stop){
        printf("empty");
        return 0;
    }
    if(start < -size)
        start = -size;
    if(stop < -size)
        stop = -size;
    if(start < 0)
        start = size + start;

    if(stop < 0)
        stop = size + stop;
    if(stop > size - 1)
        stop = size;
    if(start < stop && step > 0)
        isIncrease = 1;


    if(isIncrease){
        for(int i = start; i < stop; i+=step){
            flag = 1;
            printf("%d ", arr[i]);
        }
    }else{
        if(step > 0)
            step *= -1;
        if(start > size)
            start = size - 1;
        for(int i = start; i > stop; i+=step){
            flag = 1;
            printf("%d ", arr[i]);
        }
    }

    if(!flag){
        printf("empty");
    }
    return 0;
}
