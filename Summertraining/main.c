#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include<mysql/mysql.h>
#pragma comment(lib，"libmysql.lib")
#define DATABASE    "MyDatabase"
#define TABLE       "user"

/**
 * @brief   基于MySQL的学生信息查询系统
 * @author  龚娜
 * @data    2021/07/06
*/
 

void finish_with_error(MYSQL *con);
//精确查询用户信息
int GetValue(MYSQL *con, const char* table, const char* ColumnName, const char* id, char* buf);
//插入用户信息
int InsertValue(MYSQL *con, const char* table, const char* ColumnName, const char* id, char* buf);
//更新用户信息
int UpdataValue(MYSQL *con, const char* table, const char* ColumnName, const char* id, char* buf);
//删除用户信息
int DeleteValue(MYSQL *con, const char* table, const char* ColumnName, const char* id, char* buf);
//模糊查找用户信息
int GetValueReturnAllInFo(MYSQL *con, const char* table, const char* id, char* buf);






 

//定义数据库操作的宏，也可以不定义留着后面直接写进代码

#define SELECT_QUERY "select* from user  where studentId=%d"

int main(int argc,char*argv[])//char**argv相当于char*argv[]
{
    MYSQL mysql,*sock;//定义数据库连接的句柄，它被用于几乎所有的MySQL函数

    MYSQL_RES* res;//查询结果集，结构类型

    MYSQL_FIELD* fd;//包含字段信息的结构

    MYSQL_ROW row;//存放一行查询结果的字符串数组

    char qbuf[160];//存放查询sql语句字符串

     
    printf("*********欢迎使用学生信息查询系统!***********\n");

    if(argc!=2){//检查输入参数

        fprintf(stderr,"usage:mysql_select\n");

    exit(1);

    }

    mysql_init(&mysql);
    //mysql成功连接的MySQL变量--实参

    if(!(sock=mysql_real_connect(&mysql,"localhost","gongna2","123456","MyDatabase",0,NULL,0))){
        fprintf(stderr,"Couldn't connect to engine!\n%s\n\n",mysql_error(&mysql));
        perror("");
        exit(1);

    }

    sprintf(qbuf,SELECT_QUERY,atoi(argv[1]));

    if(mysql_query(sock,qbuf)){
        fprintf(stderr,"Query failed(%s)\n",mysql_error(sock));
        exit(1);

    }

    if(!(res=mysql_store_result(sock))){
        fprintf(stderr,"Couldn't get result from %s\n",mysql_error(sock));
        exit(1);

    }//将从数据库中查到的数据存储在客户端


    printf("returned:%d\n",mysql_num_fields(res));

    while(row=mysql_fetch_row(res)){
        printf("what you input is %d\nThe query result is:\nThe id is:%s\nThe studentId is:%s\nThe gender is:%s\nThe name is:%s\nThe age is:%s\nThe classId is:%s\n",atoi(argv[1]),(((row[0]==NULL)&&(!strlen(row[0])))?"NULL":row[0]),row[1],row[2],row[3],row[4],row[5]);
        puts("Query Success!\n");

    }//将mysql_store_result存储的数据读取出来。

    mysql_free_result(res);
    //结果集用完后，调用mysql_free_result函数释放结果集，以防内存泄露

    mysql_close(sock);
    //不再查询Mysql数据库时，调用mysql_close函数关闭数据库连接

    exit(0);

}







