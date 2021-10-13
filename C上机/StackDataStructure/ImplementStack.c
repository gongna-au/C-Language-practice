#include "ImplementStack.h"
#include <stdio.h>
#include <stdlib.h>

// There are two ways to implement a stack: 
// Using array
// Using linked list
// Implementing Stack using Arrays

struct StackStruct {
    int top;
    int capacity;
    int* array;
};

typedef struct StackStruct  Stack;




// function to create a stack of given capacity. 
// It initializes size of  stack as 0
 Stack * CreateStack(unsigned capacity){
    Stack * stack =(Stack *)malloc(sizeof(Stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(int *)malloc((stack->capacity)*sizeof(int));
 }