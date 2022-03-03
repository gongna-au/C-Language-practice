#include <map>  
  
#include <string>  
  
#include <iostream> 
using namespace std;


int PrintArray(int* w, int n){
    int *p=w; 
    for( p=w;p<(w+n);p++){
        cout<<*p<<" ";
    }         
    cout<<endl;
    return 0;
}

int  DeleteSameItem(int* w, int n){
    int flag[n];
    int tag=0;

    for (int i=0;i<n;i++){
        flag[i]=0;
    }
    for (int i=0;i<n-2;i++){
       for ( int j=i+1;j<n-1;j++){
           if (w[i]==w[j] && flag[j]==0){
               flag[j]=1;
            
           }
       }  
   }

   for (int i=0;i<n-tag;) {
       if (flag[i]==1){
           tag++;
           w[i]=w[i+tag];
           flag[i]=flag[i+tag];

       }else{
           i++;
       }

   }
   PrintArray(w,n-tag);
   return 0;

}


int InputArrayValue(int* w,int n){
    int *p=w; 
    cout<<"Please input your array:";
    for( int i=0;i<n;i++){
        cin>>*(w+i);
    }
    cout<<"The array you input are :";
    for( p=w;p<(w+n);p++)
        cout<<*p<<" ";  
    cout<<endl;
    return 0;
}

int main()  {
   int length;
    cout<<"Please input the array length:";
    cin>>length; 

   int array[length];
   int* ptrArray=array;
   InputArrayValue(ptrArray,length);
   DeleteSameItem(ptrArray,7);
   
}  

