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








    //成功连接数据库的变量
    MYSQL *con = NULL;
    char id[20] = {0};//ID是学生编号
    char buf[1000] = {0};//buf是缓冲区
    int columnType;
    int searchMethodType;
    con=mysql_real_connect(&mysql,"localhost","gongna2","123456","MyDatabase",0,NULL,0);
    if (con==NULL){
        printf("MySQL init fail.\n");
        fprintf(stderr,"%s\n",mysql_error(con));
        return -1;
    }
    printf("远程数据库登录成功！\n");

    printf("请选择查询方法类型\n1-->精确查找:\n2-->模糊查找");
    scanf("%d", &searchMethodType);



    switch(searchMethodType){ 

        case 1:

            printf("请选择需要查询的用户信息:\n");
    
            printf("--->1)studentId学生学号; 2)gender学生性别; 3)name学生姓名;4)age学生年龄;5)classId学生班级\n");
            scanf("%d", &columnType);
    
            printf("请输入要查询的学生的编号:");
            //接收用户输入
            scanf("%s", id);
            switch(columnType){
                case 1:
            /* 查询学生学号并打印结果 */
                    if(-1 != GetValue(con, TABLE, "studentId", id, buf)){
                        printf("--->编号为%s的学生信息查询成功，studentId为:%s\n", id, buf);
                    }
                    else{
                        printf("--->编号为%s的学生信息查询失败!\n", id);
                        return -1;
                    }
                    break;

                case 2:
            /* 查询学生性别并打印结果 */
                    if(-1 != GetValue(con, TABLE, "gender", id, buf)){
                        printf("--->编号为%s的学生信息查询成功，gender为:%s\n", id, buf);
                    }
                    else{
                        printf("--->编号为%s的学生信息查询失败!\n", id);
                        return -1;
                    }
                    break;
                
                case 3:
            /* 查询学生姓名并打印结果 */
                    if(-1 != GetValue(con, TABLE, "name", id, buf)){
                        printf("--->编号为%s的学生信息查询成功，name为:%s\n", id, buf);
                    }
                    else{
                        printf("--->编号为%s的学生信息查询失败!\n", id);
                        return -1;
                    }
                    break;
                case 4:
            /* 查询学生年龄并打印结果 */
                    if(-1 != GetValue(con, TABLE, "age", id, buf)){
                        printf("--->编号为%s的学生信息查询成功，age为:%s\n", id, buf);
                    }
                    else{
                        printf("--->编号为%s的学生信息查询失败!\n", id);
                        return -1;
                    }
                    break;
                case 5:
            /* 查询学生班级并打印结果 */
                    if(-1 != GetValue(con, TABLE, "classId", id, buf)){
                        printf("--->编号为%s的学生信息查询成功，classId为:%s\n", id, buf);
                    }
                    else{
                        printf("--->编号为%s的学生信息查询失败!\n", id);
                        return -1;
                    }

                    break;
                default:
                    /* 输入错误 */
                    printf("选项错误，系统退出!\n");
                    mysql_close(con);
                    return -1;


            }
        break;




        case 2:
            printf("请输入要查询的学生的编号:");
            //接收用户输入
            scanf("%s", id);
            if(-1 != GetValueReturnAllInFo(con, TABLE, id, buf)){
                printf("--->编号为%s的学生信息查询成功，studentId为:%s\n", id, buf);
            }
            else{
                printf("--->编号为%s的学生信息查询失败!\n", id);
                return -1;
            }

        break;

    }


    return 0;//.为了兼容大部分的编译器加入此行

}



/** 
 * 语句执行出错处理
 * @param con 需要处理的MYSQL变量
 * @return -1;
*/

void finish_with_error(MYSQL *con)
{
    fprintf(stderr,"%s\n",mysql_error(con));
    mysql_close(con);
}







/**
 * 从数据库中模糊查询用户信息
 * @param con 成功连接的MySQL变量
 * @param table 需要查询的表
 * @param id 用户id
 * @param buf 存放查询结果的缓冲区
 * @return 成功返回0，失败则返回-1
*/
int GetValueReturnAllInFo(MYSQL *con, const char* table,const char* id, char* buf){
    char sql[100];
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    //构造完整sql语句
    sprintf(sql, "select * from %s where id=%11s;",  table, id);

    //查询
    if(mysql_query(con,sql)){
        finish_with_error(con);
        return -1;
    }
    //获取并存储查询结果
    result = mysql_store_result(con);
    if(NULL == result)
    {
        finish_with_error(con);
        return -1;
    }

    if(row = mysql_fetch_row(result)){
        for(int i=0;;i++){ 
            if(row[i] != NULL){
                strcpy(buf, row[i]);
                break;
            }
        
            else{
                strcpy(buf, "NULL");
                continue;
            }
        }
    }
    
    mysql_free_result(result);

    return 0;

}

/**
 * 从数据库中精确查询用户信息
 * @param con 成功连接的MySQL变量
 * @param table 需要查询的表
 * @param id 用户id
 * @param buf 存放查询结果的缓冲区
 * @param ColumnName 查询的列名
 * @return 成功返回0，失败则返回-1
*/
int GetValue(MYSQL *con, const char* table, const char* ColumnName, const char* id, char* buf)
{
    char sql[100];
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;

    //构造完整sql语句
    sprintf(sql, "select %s from %s where id=%11s;", ColumnName, table, id);
    //查询
    if(mysql_query(con,sql))
    {
        finish_with_error(con);
        return -1;
    }
    //获取并存储查询结果
    result = mysql_store_result(con);
    if(NULL == result)
    {
        finish_with_error(con);
        return -1;
    }
    //根据行查询数据
    if(row = mysql_fetch_row(result))
    {
        for(int i=0;;i++){ 
            if(row[i] != NULL){
                strcpy(buf, row[i]);
                break;
            }
        
            else{
                strcpy(buf, "NULL");
                continue;
            }
        }
    }
    mysql_free_result(result);

    return 0;
}



/**
 * 往数据库中插入用户信息
 * @param con 成功连接的MySQL变量
 * @param table 需要更新的表
 * @param id 用户id
 * @param buf 存放待更新数据的缓冲区
 * @param ColumnName 查询的列名
 * @return 成功返回0，失败则返回-1
*/
int InsertValue(MYSQL *con, const char* table, const char* ColumnName, const char* id, char* buf)
{
    char sql[100]; 
    
    //构造完整sql语句
    sprintf(sql, "insert into %s set %s=%s where id=%11s;", table, ColumnName, buf, id);
    //执行
    if(mysql_query(con,sql))
    {
        finish_with_error(con);
        return -1;
    }

    return 0;
}
/**
 * 从数据库中更新用户信息
 * @param con 成功连接的MySQL变量
 * @param table 需要更新的表
 * @param id 用户id
 * @param buf 存放待更新数据的缓冲区
 * @param ColumnName 查询的列名
 * @return 成功返回0，失败则返回-1
*/
int UpdataValue(MYSQL *con, const char* table, const char* ColumnName , const char* id, char* buf)
{
    char sql[100]; 
    
    //构造完整sql语句
    sprintf(sql, "update %s set %s=%s where id=%11s;", table, ColumnName , buf, id);
    //执行
    if(mysql_query(con,sql))
    {
        finish_with_error(con);
        return -1;
    }

    return 0;
}


/**
 * 从数据库中删除用户信息
 * @param con 成功连接的MySQL变量
 * @param table 需要删除信息的表
 * @param id 用户id
 * @param buf 存放删除结果的缓冲区
 * @param ColumnName 查询的列名
 * @return 成功返回0，失败则返回-1
*/
int DeleteValue(MYSQL *con, const char* table, const char* ColumnName , const char* id, char* buf){
    char sql[100]; 
    
    //构造完整sql语句
    sprintf(sql, "delete %s set %s=%s where id=%11s;", table, ColumnName , buf, id);
    //执行
    if(mysql_query(con,sql))
    {
        finish_with_error(con);
        return -1;
    }

    return 0;

}







