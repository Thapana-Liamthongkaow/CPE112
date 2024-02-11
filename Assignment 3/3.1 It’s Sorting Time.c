//66070503416 Thapana Liamthongkaow
//Assingment 3.1 It’s Sorting Time

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int ID, score;
    struct node *next;
} Student;

Student *Create_Node() {
    int ID, Score;
    scanf("%d %d", &ID, &Score);
    Student *New_Node = malloc(sizeof(Student));
    New_Node->ID = ID;
    New_Node->score = Score;
    New_Node->next = NULL;
    return New_Node;
}

void Traverse(Student **start) {
    for (Student *cur = *start; cur != NULL; cur = cur->next)
        printf("%d ", cur->score);
}

void Sort(Student **start, int (*compare)(Student*, Student*)) {
    if (*start == NULL) return;

    int sorted;
    Student *cur, *prev, *post;

    do {
        sorted = 0;
        cur = *start;
        prev = NULL;

        while (cur->next != NULL) {
            post = cur->next;

            if (compare(cur, post) > 0) {
                if (prev == NULL) *start = post;
                else prev->next = post;

                cur->next = post->next;
                post->next = cur;
                sorted = 1;
                break;
            }

            prev = cur;
            cur = cur->next;
        }
    } while (sorted);
}

int CompareByID(Student *a, Student *b) {
    return a->ID - b->ID;
}

int CompareByScore(Student *a, Student *b) {
    return a->score - b->score;
}

int main(void) {
    int n, mode;
    scanf("%d", &n);

    Student *start = NULL, *cur = start;

    for (int i = 0; i < n; i++) {
        Student *New_Node = Create_Node();
        if (start == NULL) start = New_Node;
        else cur->next = New_Node;

        cur = New_Node;
    }

    scanf("%d", &mode);

    if (mode == 0) Sort(&start, CompareByID);
    else Sort(&start, CompareByScore);

    Traverse(&start);
    return 0;
}
