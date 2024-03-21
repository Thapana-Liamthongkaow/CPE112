//66070503416 Thapana Liamthongkaow
//Lab 7: AVL Tree
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
}Node;

int height(Node *node);
int max(int a, int b);
int get_balance(Node* node);
Node* newnode(int val);
Node* right_rotate(Node* node);
Node* left_rotate(Node* node);
Node* insert(Node* node, int val);
Node* delete(Node* noed, int val);
Node* minvaluenode(Node* node);
void preorder(Node* node);


int main(){
    Node* root = NULL;
    int val;
    char choice[10];
    while(1){
        scanf("%s",choice);
        if(strcmp(choice, "INSERT")==0){
            while(scanf("%d",&val)==1){
                root = insert(root, val);
            }
        }
        else if(strcmp(choice, "DELETE")==0){
            while(scanf("%d",&val)==1){
                root = delete(root, val);
            }
        }
        else if(strcmp(choice, "PRINT")==0){
            if(root == NULL){
                printf("Tree is empty.\n");
            }
            else{
                preorder(root);
                printf("\n");
            }
        }
        else if(strcmp(choice, "EXIT")==0){
            free(root);
            return 0;
        }
        else{
            printf("Invalid command.\n");
        }
    }
}

int height(Node *node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}

int max(int a, int b){
    return (a>b)? a:b;
}

int get_balance(Node* node){
    if(node == NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node* newnode(int val){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* right_rotate(Node* root){
    Node* newroot = root->left;
    Node* rightsubtree = newroot->right;

    newroot->right = root;
    root->left = rightsubtree;

    root->height = max(height(root->left), height(root->right)) + 1;
    newroot->height = max(height(newroot->left), height(newroot->right)) + 1;
    
    return newroot;
}

Node* left_rotate(Node* root){
    Node* newroot = root->right;
    Node* leftsubtree = newroot->left;

    newroot->left = root;
    root->right = leftsubtree;

    root->height = max(height(root->left), height(root->right)) + 1;
    newroot->height = max(height(newroot->left), height(newroot->right)) + 1;
    
    return newroot;
}

Node* insert(Node* node, int val){
    if(node == NULL){
        return newnode(val);
    }

    if(val < node->data){
        node->left = insert(node->left, val);
    }
    else if(val > node->data){
        node->right = insert(node->right, val);
    }
    else{
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = get_balance(node);

    if(balance>1 && val<node->left->data){ //LL
        return right_rotate(node);
    }
    if(balance<-1 && val>node->right->data){ //RR
        return left_rotate(node);
    }
    if(balance>1 && val>node->left->data){  //LR
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    if(balance<-1 && val<node->right->data){  //RL
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

Node* delete(Node* root, int val){
    if(root == NULL){
        printf("Node not found.\n");
        return root;
    }
    if(val < root->data){
        root->left = delete(root->left, val);
    }
    else if(val > root->data){
        root->right = delete(root->right, val);
    }
    else{
        if((root->left == NULL) || (root->right == NULL)){
            Node* temp = root->left ? root->left : root->right;

            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            else{
                *root = *temp;
                free(temp);
            }
        }
        else{
            Node *temp = minvaluenode(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }

    if(root == NULL){
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = get_balance(root);
    
    if(balance>1 && get_balance(root->left)>=0){
        return right_rotate(root);
    }
    if(balance>1 && get_balance(root->left)<0){
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance<-1 && get_balance(root->right)<=0){
        return left_rotate(root);
    }
    if(balance<-1 && get_balance(root->right)>0){
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    return root;
}

Node* minvaluenode(Node* node){
    Node* current = node;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

void preorder(Node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}