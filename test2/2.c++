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

void showValues1 (int elem[][3], int m)
{
   for(int i=0;i<m;i++){
       for(int j=0;j<3;j++){
           cout<<elem[i][j]<<" ";
          
       }
    }
    cout << endl;
}
void showValues2 (int **elem, int m,int n)
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
    
    cout<<"Please input m:"<<endl;
    cin>>m;
    cout<<"Please input n:"<<endl;
    cin>>n;
    int* *array=new int*[m];
    for( i=0;i<n;i++){
        array[i] = new int[n];
    }
    
    int (*elem)[3]=new int[m][3];
    
    for(i=0;i<m;i++){
       for(j=0;j<n;j++){
           //cin>>temp;
           array[i][j]=i-j;
       }
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

    //showValues1(elem,m);
    showValues2(array,m,n);
    
    

}


