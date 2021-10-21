#include "Radixhead.h"  // 采用线性表的顺序存储结构

void InputElement(SqList &L) { 
    //输入集合元素到线性表L中
    printf("Please input Total number of students");
    int i, num;
    ElemType e;
    printf("num  = ");
    scanf("%d", &num);
    printf("elem = ");
    for(i = 1; i <= num; i++){
        printf("Please input %d student's  studentID:");
        scanf("%s", &e.no);
        printf("Please input %d student's  name:");
        scanf("%s", &e.name);
        printf("Please input %d student's  grade:");
        scanf("%d", &e.grade);
        ListInsert_Sq(L, i, e); 
    }
}

//求并集
void Union(SqList La, SqList Lb, SqList &Lc){
// 算法2.1的修改：将线性表La和Lb合并成新的线性表Lc，算法执行结束后，线性表La和Lb不变
    int i, j = 0;
    ElemType e;

    for (i = 1; i <= ListLength_Sq(La); i++){
        GetElem_Sq(La, i, e);  //取集合A中的元素
        j++;
        ListInsert_Sq(Lc, j, e); //插入到集合C中
    }
    for (i = 1; i <= ListLength_Sq(Lb); i++){
        GetElem_Sq(Lb, i, e);  //取集合B中的元素
        if (LocateElem_Sq(Lc, e))  //在集合C中存在该元素
            continue;
        j++;
        ListInsert_Sq(Lc, j, e); //插入到集合C中
    }
} 

//求交集
void Inter(SqList La, SqList Lb, SqList &Lc){   
    int i, j = 0;
    ElemType e;

    for (i = 1; i <= ListLength_Sq(La); i++){
        GetElem_Sq(La, i, e);  //取集合A中的元素
        if (LocateElem_Sq(Lb, e))  {
        //在集合B中存在该元素
            j++;
            ListInsert_Sq(Lc, j, e); //插入到集合C中
        }
    }
}

//求差集
void Sub(SqList La, SqList Lb, SqList &Lc){
    int i, j = 0;
    ElemType e;

    for (i = 1; i <= ListLength_Sq(La); i++){
        GetElem_Sq(La, i, e);  //取集合A中的元素
        if (!LocateElem_Sq(Lb, e))  {
    //在集合B中不存在该元素
            j++;
            ListInsert_Sq(Lc, j, e); //插入到集合C中
        }
    }
}

void main()
{
SqList La, Lb, Lc, Ld, Le, Lf;

printf("************* Input A ***************\n");
InitList_Sq(La);
InputElement(La);

printf("************* Input B ***************\n");
InitList_Sq(Lb);
InputElement(Lb);

InitList_Sq(Lc); // 集合C（A并B）
Union(La,Lb,Lc);

InitList_Sq(Ld); // 集合D（A交B）
Inter(La,Lb,Ld);

InitList_Sq(Le); // 集合E（A-B）
Sub(La,Lb,Le);

InitList_Sq(Lf); // 集合F（B-A）
Sub(Lb,La,Lf);

printf("\n************* Result ****************\n");
printf("A = {"); // 输出集合A


}


