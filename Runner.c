#include <stdio.h>
#include <stdlib.h>

// Define the sorted set data structure
typedef struct sortedset
{
    int *elements;
    int size;
} sortedset;

// Function prototypes
sortedset *init(int size);
int checkDuplicate(sortedset *s, int target);
void insertElement(sortedset *s, int newNum);
void printArray(sortedset *s);

int main()
{
    // Initialize a sorted set with a capacity of n elements
    int k;
    scanf("%d", &k);
    sortedset *s = init(k);

    // Insert some elements into the set
    for (int i = 0; i < k; i++)
    {
        int num;
        scanf("%d", &num);
        insertElement(s, num);
    }
    // Print the contents of the set
    printArray(s);

    // Free the memory allocated for the set
    free(s);

    return 0;
}

// Function definitions
sortedset *init(int size)
{
    sortedset *s = (sortedset *) malloc(sizeof(sortedset));

    if (s == NULL)
    {
        printf("Error: unable to allocate memory for sorted set\n");
        exit(1);
    }

    s->size = 0;
    s->elements = (int *) malloc(size * sizeof(int));

    if (s->elements == NULL)
    {
        printf("Error: unable to allocate memory for sorted set elements\n");
        exit(1);
    }

    return s;
}

int checkDuplicate(sortedset *s, int target)
{
    int i;
    for (i = 0; i < s->size; i++)
    {
        if (s->elements[i] == target)
        {
            return 1;
        }
    }

    return 0;
}

void insertElement(sortedset *s, int newNum)
{
    int i;

    // Check if the element is a duplicate
    if (checkDuplicate(s, newNum))
    {
        printf("Error: element %d is a duplicate\n", newNum);
        return;
    }

    // Shift elements to make room for the new element
    for (i = s->size; i > 0 && s->elements[i - 1] > newNum; i--)
    {
        s->elements[i] = s->elements[i - 1];
    }

    // Insert the new element
    s->elements[i] = newNum;
    s->size++;
}

void printArray(sortedset *s)
{
    int i;

    printf("Size: %d\n", s->size);
    for (i = 0; i < s->size; i++)
    {
        printf("%d ", s->elements[i]);
    }
    printf("\n");
}