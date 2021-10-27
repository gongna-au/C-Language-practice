#include "bag.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
   
    int W[6]={1,8,4,3,5,2};
    int T=10;
    int N=6;

}
void knapsack(int W[],int T,int n ){
    Stack* stack = CreateStack(10);
    int  k=0;
    do{
        while(T>0 && k<n){
            if(T-W[k]>=0){
                push(stack,k);
                T-=W[k];
            }
            k++;
        }
        if(T==0){
            
        }
        int item=Pop(stack);
        T+=W[k];
        k++;
    }while(!IsEmpty(stack) || (k<n));

}