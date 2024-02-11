//66070503416 Thapana Liamthongkaow
//Assignment  3.2 Circular table

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

Node *Create_Node() {
    Node *New_Node = (Node *)malloc(sizeof(Node));
    scanf("%d", &New_Node->value);
    New_Node->next = NULL;
    return New_Node;  // Added return statement
}

Node *LastManStanding(Node **start, int Step) {
    if (*start == NULL) {  // Empty List
        return NULL;
    }

    if ((*start)->next == *start) {  // Last Man
        return *start;
    }
    Node *Cur = *start;
    Node *Prev = NULL;
    for (int i = 0; i < Step; i++) {
        Prev = Cur;
        Cur = Cur->next;
    }

    Prev->next = Cur->next;
    return LastManStanding(&(Prev), Step);
}

int main(void) {
    int n, step;
    scanf("%d %d", &n, &step);

    Node *Start = NULL;
    Node *Cur = Start;
    for (int i = 0; i < n; i++) {
        Node *New_Node = Create_Node();
        if (Start == NULL) {
            Start = New_Node;
            Cur = Start;
        } else {
            Cur->next = New_Node;
            Cur = New_Node;
        }
        New_Node->next = Start;
    }
    LastManStanding(&(Cur), step);  // Cur is at the last node
    Node *Res = LastManStanding(&Start, step);
    printf("%d", Res->value);

    return 0;
}
