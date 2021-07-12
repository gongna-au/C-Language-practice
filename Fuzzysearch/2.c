#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
  char str[] = "hello welcome to china\0"; //源字符串
  printf("input a string:\n");
  char str2[20];              //要查找的字符串
  fgets(str2, 19, stdin);
  char *res;
  res = memchr(str, str2[0], strlen(str));  //根据要查找的字符串第一个字符，切割源字符串
  if (res == NULL)
  {
    printf("find nothing...\n");
    return 0;
  }
 
  int n;
  while (1)
  {
    n = memcmp(res, str2, strlen(str2) - 1); //比较
    if (n != 0)
    {
      if (strlen(res) <= strlen(str2))  //切割出的字符串小于要查找字符串的长度
      {
        printf("find nothing...\n");
        return 0;
      }
      else
      {
       //根据要查找的第一个字符继续切割
        res = memchr(res + 1, str2[0], strlen(res));
        if (res == NULL)
        {
          printf("find nothing...\n");
          return 0;
        }
 
      }
    }
    else
    { //如果n = 0，找到
      printf("%s is found..\n", str2);
      return 0;
    }
  }
}