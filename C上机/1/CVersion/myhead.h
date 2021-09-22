#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<malloc.h>
#include<string.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENTSIZE 10
#define TRUE 1
#define FALSE 0


typedef struct SqList{
    //数据
    int *elem;
    //线性表的元素的个数
    int length;
    //线性表的动态内存分配的数组容量
    int capacity;
    //约定的增补空间
    int incrementsize;
   
}SqList;

//定义指向线性表的指针

//typedef SqList *pSqList;




//创建空表createNullList 
void InitSqList (SqList* L){
    L->elem=(int *)malloc(sizeof(int)*L->capacity);
    L->length=0;
    L->capacity=LIST_INIT_SIZE;
    L->incrementsize=LISTINCREMENTSIZE;

}

//删除线性表 
//线性表已经存在 销毁线性表
void DestorySqList (SqList* L){
    
    if (L->elem){
        //释放线性表占据的所有的存储空间
       // free(L);
    }
    L->capacity=0;
	L->length=0;
}

// ClearList 把已经存在的线性表重置为空表
void ClearListSqList (SqList* L){
    memset(L->elem,0,L->length*sizeof(int));
    L->length=0;
   
}

// ListEmpty 若为空表则返回True 非空返回False
int  ListEmpty (SqList L){
   if (L.length==0){
       return TRUE;
   }
   return FALSE;
}


// ListLength 返回线性表中元素的个数
int  ListLength (SqList L){
    return L.length;
}

void ErrorMessage(char str[20])
{
   
	printf("%s\n",str);
	exit(1);
}

// GetElem 用e返回第i个元素的值
int GetElem(SqList L,int i,int e){
    char a[20]="i的值不合法"; 
    if ((i<1) || (i>L.length))
	{
		ErrorMessage(a);
		return 0;
	} 

    
        //用头指针代表整个结构的地址
        e=L.elem[i-1];
        return e;
   

}

//  LocateElemInSqList 定位某个元素在线性表里面的位序
int LocateElemInSqList(SqList L,int e){
    int i;
    int *p=L.elem;
    for(i=1;i<L.length;i++){
        if(p[i]==e){

            break;
        }
    }
    if (i<L.length){
        return i;
    }else{
        return 0;
    }
   
}
//PriorElem cur_e为线性表的元素，用pre_e得到这个元素的前驱，操作失败pre_e无定义
int PriorElem(SqList L, int cur_e, int *pre_e){
    int i;
    for ( i=0;i<L.length;i++){
        
        if (cur_e == L.elem[i]){
            *pre_e=L.elem[i-1];
            break;

        }

    }
    if (i<L.length){
        return *pre_e;
    }
    return 0;
    

}

// NextElem cur_e为线性表的元素不是最后一个，用next_e得到这个元素的后继，操作失败next_e无定义
int NextElem(SqList L, int cur_e,int* next_e){
    int i;
    for ( i=0;i<L.length;i++){
        
        if (cur_e==L.elem[i]){
            *next_e=L.elem[i-1];
            break;

        }

    } 
    if (i<L.length){
        return *next_e;
    }
    return 0;
    

}

void increment(SqList *L){
    int i;
    int * newspace = (int*)malloc(sizeof(int)*(L->capacity + L->incrementsize));
    if(newspace == NULL)
    {
        printf("Out Of Memory!\n");  
       
    }
    memcpy(newspace, L->elem, sizeof(int)*L->capacity); 
    //free(L->elem);
    L->elem = newspace;
    L->capacity=L->capacity+L->incrementsize;
    
}

// ListInsert 在第i个元素之间插入新的元素e,L的长度增加1
int ListInsert(SqList* L,int i,int e){
    //检查是否还有剩余的空间
    if((i<1)||(i>L->length)){
        printf("输入不合法！\n");
    }
    //判断序列表的长度是否大于容量
    if (L->length >=L->capacity){
        increment(L);
    }
    int *p=&(L->elem[i-1]);
    for (int j=L->length-1;j>=i;j--){
        //把第i个之后的元素都往后面移动
        L->elem[j]=L->elem[j-1];
    }

    L->elem[i-1]=e;
    L->length=L->length+1;
}


int ListDelete(SqList* L,int i,int e){
    if ((i<1) || (i>L->length)){
        printf("输入不合法！\n");
        return 0;
    }

    e=L->elem[i];
    for (int j=L->length-1;j>i;j--){
        //把第i个之后的元素都往前面移动,第i个元素不动
        L->elem[j-1]=L->elem[j];
    }
    L->length=L->length-1;
    return e;

}

void ListTraverse(SqList L){
    for (int i=0;i<L.length;i++){
        printf("%-4d",L.elem[i]);
    }
    printf("\n");
}

