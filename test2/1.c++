#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define SqlistInitSize 100
#define SqlistIncrement 10
typedef int ElemType;
typedef int Boolean;
struct SqList{
    ElemType* elem;
    int length;
    int listsize;
    int incrementsize;
};
void InitList_Sq(SqList & L){
   L.elem= new ElemType[SqlistInitSize];
   L.length=0;
   L.listsize=SqlistInitSize;
   L.incrementsize=SqlistIncrement;
}
void DestroyList_Sq(SqList &L){
   free(L.elem);
   L.listsize = 0;
   L.length = 0;
}
void ClearList_Sq(SqList &L){ 
   L.length=0;

}

void showValues (int** elem, int m,int n)
{
   for(int i=0;i<m;i++){
       for(int j=0;j<n;j++){
           cout<<elem[i][j]<<" ";
          
       }
    }
    cout << endl;
}
int main(){
    int n,m ,i,j,temp;
    int array[3]={1,2,3};
    cout<<"Please input m:"<<endl;
    cin>>m;
    cout<<"Please input n:"<<endl;
    cin>>n;
    int* *elem=new int* [m];
    for(i=0;i<m;i++){
        elem[i]=new int [n];
    }

    for(i=0;i<m;i++){
       for(j=0;j<n;j++){
           //cin>>temp;
           elem[i][j]=i+j;
       }
    }
    for(i=0;i<m;i++){
       for(j=0;j<n;j++){
           cout<<elem[i][j]<<" ";
          
       }
       cout<<endl;
       
    }

    showValues(elem,m,n);
    

}


