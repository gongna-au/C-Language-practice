#include<iostream>
#include<string>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100
typedef int Status;
using namespace std;


typedef struct
{
    int w;
    int parent;
    int lchild,rchild;
}HTNode,*HuffmanTree;

//从数组中挑选可以选择的权值
void Select(HuffmanTree H,int i,int &s1,int &s2)
{
    int n = 1;
    int j = 1;
    int z;
    while(j <= 2)
    {
        n = 1;
        while(H[n].parent != 0)
        {
            n++;
        }
        z = n;
        while(n<i)
        {
            n = n+1;
            if(H[n].parent == 0){
                if(H[z].w > H[n].w){
                    z = n;
                }
            }
        }
        if(j == 1){
            s1 = z;
            H[s1].parent = 1;
            j++;
        }else{
        s2 = z;
        j++;
        }

    } 
}


void createmanTree(HuffmanTree &H,int n)
{
    if(n<=1){
        return ;
    }
    //赫夫曼共有这么多结点
    int m = 2*(n-1)+1; 
    H = new HTNode[m+1];

    int i;
    for(i = 1;i<=m;i++){
        H[i].parent = 0;
        H[i].lchild = 0;
        H[i].rchild = 0;
    }
    i = 1;
    while(i<=n){
        cin>>H[i].w;
        i++;
    }
    int j = n;
    int s1,s2;
    for(i = n+1;i<=m;++i){
        Select(H,i-1,s1,s2);
        H[s1].parent = i;
        H[s2].parent = i;

        H[i].lchild = s1;
        H[i].rchild = s2;
        H[i].w = H[s1].w+H[s2].w;
    }

}


void bianma(HuffmanTree H,int n)
{
    char c[n][n+1];
    char ch[n];
    int i = 1;
    int j,f,k = 0;
    int z,m;
    for(i = 1;i<=n;++i){
        j = i;
        f = H[i].parent;

        k = 0;
        while(f != 0){
            if(H[f].lchild == j){
                ch[k] = '0';
                k++;
            }else{
                ch[k] = '1';
                k++;
            }
            j = f;
            f = H[f].parent;


        }
            ch[k] = '\0';

            z = strlen(ch);

        int u = 0;
        for( m = z-1;m>=0;m--){
            c[i-1][u] = ch[m];
            u++;

        }
        c[i-1][u] = '\0';

    }
        
        i = 0;

        while(i<=7){
            j = 0;
            cout<<"第"<<i+1<<"个字符的编码是  :";
            while(c[i][j] != '\0'){
                cout<<c[i][j];
                j++;
            }
            i++;
            cout<<endl;
        }
}


