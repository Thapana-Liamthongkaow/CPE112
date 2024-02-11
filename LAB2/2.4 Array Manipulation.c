//66070503416 Thapaan Liamthongkaow
//Lab 2.4 Array Manipulation

#include <stdio.h>
#include<stdlib.h>

int insertArray(int *arr, int size, int index, int value);
int deleteArray(int *arr, int size, int index);
int mergeArray(int *arr1, int size1, int *arr2, int size2);
void printArray(int arr[],int size);

int main()
{
    int size1, size2;
    scanf("%d",&size1);
    if(size1<1 || size1>10000){
        return 0;
    }
    int *arr1 = (int *)malloc(size1 * sizeof(int)), temp;
    for(int i=0;i<size1;i++){
        scanf("%d",&temp);
        *(arr1 + i) = temp;
    }
    scanf("%d",&size2);
    if(size2<1 || size2>10000){
        return 0;
    }
    int *arr2 = (int *)malloc(size2 * sizeof(int));
    for(int i=0;i<size2;i++){
        scanf("%d",&temp); //input ln4
        *(arr2 + i) = temp;
    }
    int index_insert, index_delete, num_insert;
    scanf("%d",&index_insert); //input ln5
    scanf("%d",&num_insert); //input ln6
    scanf("%d",&index_delete); //input ln7
    //====================output====================
    size1 = insertArray(arr1, size1, index_insert, num_insert);
    size1 = deleteArray(arr1, size1, index_delete);
    size1 = mergeArray(arr1, size1, arr2, size2);

    free(arr1);
    free(arr2);
    return 0;
}

int insertArray(int *arr, int size, int index, int value){
    arr = (int *)realloc(arr, (size) * sizeof(int));
    for(int i=size;i>index;i--){
        arr[i] = arr[i-1];
    }
    arr[index]=value;
    printArray(arr, size+1);
    return (size+1);
}

int deleteArray(int *arr, int size, int index){
    if(index+1>size || size==0){
        printf("Index out of bounds\n");
        return size;
    }
    for(int i=index;i<size;i++){
        arr[i]=arr[i+1];
    }
    printArray(arr, size-1);
    return (size-1);
}

int mergeArray(int *arr1, int size1, int *arr2, int size2){
    int *arr3 = (int *)malloc((size1+size2) * sizeof(int));
    for(int i=0;i<size1;i++){
        arr3[i]=arr1[i];
    }
    for(int i=0;i<size2;i++){
        arr3[size1+i]=arr2[i];
    }
    printArray(arr3,size1+size2);
    free(arr3);
    return (size1+size2);
}

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
