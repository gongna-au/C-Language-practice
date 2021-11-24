#include<stdio.h>
int e = 0;
int main()
{ 
 int a = 0;
 int b = 0;
 char c='0';
 static int d = 0; 
 printf("变量a的地址是：%d\n变量b的地址是：%d\n变量c的地址是：%d\n", &a, &b, &c); 
 printf("静态变量d的地址是：%d\n", &d);
 printf("全局变量e的地址是：%d\n", &e);
}