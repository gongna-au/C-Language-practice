#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


struct StackNode {
    int data;
    struct StackNode* next;
};

typedef struct StackNode  Stack;


Stack* NewNode(int data)
{
    Stack* stackNode =(Stack*) malloc(sizeof(struct StackNode ));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int IsEmpty( Stack* root)
{
    return !root;
}


void push( Stack** root, int data)
{
    Stack* stackNewNode=NewNode(data);
    stackNewNode->next=(*root);
    (* root)=stackNewNode;
    printf("%d is pushed to stack\n", data);  
}

int Pop(Stack** root ){
    if (IsEmpty(*root)){
        return INT_MIN;
    }
    int item =(*root)->data;
    Stack* temp=(*root);
    
    (*root)=(*root)->next;
    free(temp);
    return item;
}

int Peek( Stack* root)
{
    if (IsEmpty(root))
        return INT_MIN;
    return root->data;
}