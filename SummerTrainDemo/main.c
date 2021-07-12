#include <stdio.h>
#include "color.h"
#include "mysql.h"
#include<string.h>





int  Addrecord();
int  ListAllRecord();
int ModifyrecordByName();
int ModifyrecordByPhone();
int Deleterecord();
int Searchrecord();
void finish_with_error();
//函数声明

//联系人的结构体
struct person{
    char name[30];
    char company[30];
    char telephoneNumber[30];
    char emailAddress[30];
    char remarks[30];

};








/**
 * @brief   基于MySQL的通讯录
 * @author  龚娜
 * @data    2021/07/12
*/
//主函数
int main(){

        //利用宏定义函数
        SET_BACKGROUND_COLOR(BACKGROUND_WHITE);
        SET_FRONT_COLOR(FRONT_BLUE);
        
        //设置默认的表
        char*ptable=NULL;
        char tablename[100]="ContactPerson";
        ptable=tablename;
        char buf[1000];


        //初始化并连接数据库
        MYSQL *con = NULL;
        MYSQL mysql;
        int flag=1;
        //buf是缓冲区
        con=mysql_real_connect(&mysql,"localhost","gongna2","123456","MyDatabase3",0,NULL,0);
        if (con==NULL){
            printf("MySQL init fail.\n");
            fprintf(stderr,"%s\n",mysql_error(con));
            return -1;
        }
        printf("远程数据库连接成功！\n");
        
        
        
        
/*
//功能选择
do{ 


    printf("\n--------------------------------欢迎使用联系人功能------------------------------\n\n");
    printf("\t\t\t\t\t菜单\t\t\t\t\t\t\n\n");
    printf("\t\t1.新建联系人   \t2.查看联系人   \t3.修改联系人  \n\t\t4.查找联系人 \t5.删除联系人\t6.关闭退出");
        
        switch(getchar()){
            case '1':{

                printf("\t\t请输入新建联系人的信息：\n");
                struct person contactPersonNew;
                //初始化结构体变量
                memset(&contactPersonNew,0,sizeof(struct person));
                Addrecord(con,ptable,contactPersonNew);
            break;
            }
            
            case '2': 

                ListAllRecord(con,ptable,buf);
            break;
            
            case '3':{
                int temp;
                //先清空输入缓冲区
                fflush(stdin);
                printf("\n\t\t请问你要修改谁的信息?\n");
                printf("\n\t\t根据姓名修改Or根据电话号码修改?\n\t\t根据姓名修改->1\t\t根据电话修改->2\n");
                scanf("%d",&temp);
                switch (temp)
                {
                case 1:{
                    char contactPersonInfo[30];
                    printf("\n\t\t请输入要修改的联系人的姓名\n");
                    scanf("%s",contactPersonInfo);
                    struct person contactPersonModify;
                    //初始化结构体
                    memset(&contactPersonModify,0,sizeof(struct person));
                    //获取结构体的值
                    printf("\n\t\t输入公司地址：");
                    scanf("%s",contactPersonModify.company);
                    printf("\n\t\t输入Email地址：");
                    scanf("%s",contactPersonModify.emailAddress);
                    printf("\n\t\t输入电话号码：");
                    scanf("%s",contactPersonModify.telephoneNumber);
                    printf("\n\t\t输入备注:");
                    scanf("%s",contactPersonModify.remarks);

                    ModifyrecordByName(con,ptable,contactPersonModify,contactPersonInfo);
                    break;
                }
                case 2:{
                    char contactPersonInfo[30];
                    printf("\n\t\t请输入要修改的联系人的电话号码\n");
                    scanf("%s",contactPersonInfo);
                    struct person contactPersonModify;
                    //初始化结构体
                    memset(&contactPersonModify,0,sizeof(struct person));
                    //获取结构体的值
                    printf("\n\t\t输入联系人昵称：");
                    scanf("%s",contactPersonModify.name);
                    printf("\n\t\t输入公司地址：");
                    scanf("%s",contactPersonModify.company);
                    printf("\n\t\t输入Email地址");
                    scanf("%s",contactPersonModify.emailAddress);
                    printf("\n\t\t输入备注:");
                    scanf("%s",contactPersonModify.remarks);

                    ModifyrecordByPhone(con,ptable,contactPersonModify,contactPersonInfo);
                    break;
                }
                default:
                    break;
                }
            break; 
            }
            
            case '4':{ 
                struct person contactPersonForSearch;
                //结构体的初始化
                memset(&contactPersonForSearch,0,sizeof(struct person));
                //获取结构体的值
                    printf("\n\t\t输入联系人昵称：");
                    scanf("%s",contactPersonForSearch.name);
                    printf("\n\t\t输入公司地址：");
                    scanf("%s",contactPersonForSearch.company);
                    printf("\n\t\t输入Email地址");
                    scanf("%s",contactPersonForSearch.emailAddress);
                    printf("\n\t\t输入备注:");
                    scanf("%s",contactPersonForSearch.remarks);





                Searchrecord(con,ptable,contactPersonForSearch,buf);
            break;
            }
            case '5':{
                char name[30];
                printf("\t\t请输入你要删除的联系人的姓名:\n");
                scanf("%s",name);
                Deleterecord(con,ptable,name);
            break;
            }
            case '6': 
                exit(0);
            break;

            
            default:
           
                printf("\t\t是否继续？\n  Yes->1  No->2");
                scanf("%d",&flag);
               
                printf("\t\t请选择你要使用的功能\n");
                getchar();

        }

}while(flag==1);


    




        
*/
    return 0;
}



//功能函数
//新建联系人功能
/**
 * 往数据库中插入用户信息
 * @param con 成功连接的MySQL变量
 * @param table 需要更新的表
 * @param contactPerson 联系人的信息
 * @return 成功返回0，失败则返回-1
*/
int  Addrecord(MYSQL *con, const char* table, struct person contactPerson ){
    char sql[10000];
    //先在数据库中查找要新建的联系人的人名是否存在
    //若存在则给出提示信息


    //构造完整sql语句
    if(contactPerson.name!=NULL){
        sprintf(sql, "insert into %s (Name,Company,TelephoneNumber,EmailAddress,Remarks) VALUES (%s,%s,%s,%s,%s);", table,contactPerson.name,contactPerson.company,contactPerson.telephoneNumber,contactPerson.emailAddress,contactPerson.remarks);
    }
    if(mysql_query(con,sql)){
        finish_with_error(con);
        return -1;
    }
    return 0;
    
}



//查看联系人功能
/**
 * 从数据库返回所有的用户信息
 * @param con 成功连接的MySQL变量
 * @param table 需要查询的表
 * @param id 用户id
 * @param buf 存放查询结果的缓冲区
 * @return 成功返回0，失败则返回-1
*/
int  ListAllRecord(MYSQL *con, const char* table, char* buf){
    char sql[10000];
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    //构造完整sql语句
    sprintf(sql, "select * from %s;",  table);
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
        
        printf("\n--------------------------------查询结果---------------------------------\n\n");
        printf("\t\tId:%s   \tName:%s   \tCompany:%s\n\t\tTelephoneNumber:%s    \tEmailAddress:%s   \tRemarks:%s\n",row[0],row[1],row[2],row[3],row[4],row[5]);
    }
    mysql_free_result(result);

    return 0;


}



//修改联系人功能
int ModifyrecordByName(MYSQL *con, const char* table, struct person contactPerson, char*contactPersonInfo){

    char sql[10000];
    MYSQL_RES *result = NULL;
 
    MYSQL_ROW row; 
    int tag=0;
   
    
    //先判断用户输入的信息是什么信息
    //根据姓名查询
    sprintf(sql, "select * from %s where Name=%11s;", table,contactPersonInfo);
    //查询
    if(mysql_query(con,sql)){
        finish_with_error(con);
        return -1;
    }
    
    //获取并存储查询结果
    result = mysql_store_result(con);
    if(NULL == result){
        tag=0;
    }else{
        tag=1;
    }


   
    //查询结束
    //没有查找到联系人
    if(~tag){
        printf("\n对不起，找不到该用户!\n");
    }
    //查询成功返回结果

    //根据姓名查到这个人
    if(tag){
        //根据用户输入的信息插入数据
       
        if(contactPerson.company!=NULL){
            
            //构造完整sql语句并执行
            sprintf(sql, "update %s set Company=%s where Name=%11s;", table,contactPerson.company,contactPersonInfo);
            if(mysql_query(con,sql)){
                finish_with_error(con);
                return -1;
            }
        }
            
    

        if(contactPerson.emailAddress!=NULL){
           
            //构造完整sql语句并执行
            sprintf(sql, "update %s set EmailAddress=%s where Name=%11s;", table,contactPerson.emailAddress,contactPersonInfo);
            if(mysql_query(con,sql)){
                finish_with_error(con);
                return -1;
            }
        }
        if(contactPerson.telephoneNumber!=NULL){
           
            //构造完整sql语句并执行
            sprintf(sql, "update %s set TelephoneNumber=%s where Name=%11s;", table,contactPerson.telephoneNumber,contactPersonInfo);
            if(mysql_query(con,sql)){
                finish_with_error(con);
                return -1;
            }
        }
        if(contactPerson.remarks!=NULL){
            //构造完整sql语句并执行
            sprintf(sql, "update %s set Remarks=%s where Name=%11s;", table,contactPerson.remarks,contactPersonInfo);
            if(mysql_query(con,sql)){
                finish_with_error(con);
                return -1;
            }
        }

        


    }
    mysql_free_result(result);
    return 0;


}



int  ModifyrecordByPhone(MYSQL *con, const char* table, struct person contactPerson, char*contactPersonInfo){

    char sql[10000];
    
    MYSQL_RES *result = NULL;
    MYSQL_ROW row; 
    
    int tag=0;
    
    //先判断用户输入的信息是什么信息
    //根据电话号码查询
    sprintf(sql, "select * from %s where TelephoneNumber=%11s;", table,contactPersonInfo);
    //查询
    if(mysql_query(con,sql)){
        finish_with_error(con);
        return -1;
    }
    //获取并存储查询结果
    result = mysql_store_result(con);
    if(NULL == result){
        tag=0;
    }else{
        tag=1;
    }


    //查询结束
    //没有查找到联系人
    if(~tag){
        printf("\n对不起，找不到该用户!\n");
    }
    //查询成功返回结果
    if(tag){
    //根据用户输入的信息插入数据
        if(contactPerson.name!=NULL){
            //构造完整sql语句并执行
            sprintf(sql, "update %s set Name=%s where TelephoneNumber=%11s;", table,contactPerson.name,contactPersonInfo);
            
            if(mysql_query(con,sql)){
                finish_with_error(con);
                return -1;
            }
        }
        if(contactPerson.company!=NULL){
             
            //构造完整sql语句并执行
            sprintf(sql, "update %s set Company=%s where TelephoneNumber=%11s;", table,contactPerson.company,contactPersonInfo);
                
            if(mysql_query(con,sql)){
                finish_with_error(con);
                return -1;
            }
        }
        if(contactPerson.emailAddress!=NULL){
            
            //构造完整sql语句并执行
            sprintf(sql, "update %s set EmailAddress=%s where TelephoneNumber=%11s;", table,contactPerson.emailAddress,contactPersonInfo);
            if(mysql_query(con,sql)){
                finish_with_error(con);
                return -1;
            }

        }
       
        if(contactPerson.remarks!=NULL){
            
            //构造完整sql语句并执行
            sprintf(sql, "update %s set Remarks=%s where TelephoneNumber=%11s;", table,contactPerson.remarks,contactPersonInfo);
            if(mysql_query(con,sql)){
                finish_with_error(con);
                return -1;
            }
        }
    }
    mysql_free_result(result);
    
    return 0;

}






//查找联系人功能
int Searchrecord(MYSQL *con, const char* table, struct person contactPerson, char* buf){
    char sql[10000];
    MYSQL_RES *result = NULL;
    MYSQL_ROW row;
    if(contactPerson.name!=NULL){ 
        //构造完整sql语句
        sprintf(sql, "select * from %s where Name like '%s%%'   ;",  table, contactPerson.name);
        //执行
        if(mysql_query(con,sql)){
            finish_with_error(con);
            return -1;
        }
        //获取并存储查询结果
        result = mysql_store_result(con);
        if(NULL == result){
            finish_with_error(con);
            return -1;
        }  
    }
    if((contactPerson.telephoneNumber!=NULL)){
        //构造完整sql语句
        sprintf(sql, "select * from %s where TelephoneNumber=%11s;",  table, contactPerson.telephoneNumber);
        //执行
        if(mysql_query(con,sql)){
            finish_with_error(con);
            return -1;
        }
        //获取并存储查询结果
        result = mysql_store_result(con);
        if(NULL == result){
            finish_with_error(con);
            return -1;
        }
    }
    //返回查询结果
        if(row = mysql_fetch_row(result)){
            printf("\n--------------------------------查询结果---------------------------------\n\n");
            printf("\t\tId:%s   \tName:%s   \tCompany:%s\n\t\tTelephoneNumber:%s    \tEmailAddress:%s   \tRemarks:%s\n",row[0],row[1],row[2],row[3],row[4],row[5]);
        }
        mysql_free_result(result);
        return 0;

}


//删除联系人功能
int  Deleterecord(MYSQL *con, const char* table, const char* name){
    char sql[10000]; 
    
    //构造完整sql语句
    sprintf(sql, "delete from %s where Name=%11s;", table, name);
    //执行
    if(mysql_query(con,sql))
    {
        finish_with_error(con);
        return -1;
    }

    return 0;

    
}



//错误处理功能函数
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






