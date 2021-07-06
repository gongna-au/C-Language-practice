#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include<mysql/mysql.h>
#pragma comment(lib，"libmysql.lib")

 

//定义数据库操作的宏，也可以不定义留着后面直接写进代码

#define SELECT_QUERY "select* from user  where studentId=%d"

int main(int argc,char*argv[])//char**argv相当于char*argv[]

{
    MYSQL mysql,*sock;//定义数据库连接的句柄，它被用于几乎所有的MySQL函数

    MYSQL_RES* res;//查询结果集，结构类型

    MYSQL_FIELD* fd;//包含字段信息的结构

    MYSQL_ROW row;//存放一行查询结果的字符串数组

    char qbuf[160];//存放查询sql语句字符串

    if(argc!=2){//检查输入参数

        fprintf(stderr,"usage:mysql_select\n");

    exit(1);

    }

    mysql_init(&mysql);

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

    return 0;//.为了兼容大部分的编译器加入此行

}















/*type UserModel struct {
	Id              int    `json:"id" gorm:"column:id;" binding:"required"`
	Account         string `json:"account" gorm:"column:account;" binding:"required"`
	AccountPassword string `json:"account_password" gorm:"column:account_password;" binding:"required"`
	NickName        string `json:"nickname" gorm:"column:nickname;" binding:"required"`
	Avatar          string `json:"avatar" gorm:"column:avatar;" binding:"required"`
	Energy          int    `json:"energy" gorm:"column:energy;" binding:"required"`
}

func (u *UserModel) TableName() string {
	return "tbl_user"
}

func (u *UserModel) Create() error {
	return DB.Self.Create(u).Error
}

func (u *UserModel) Update() error {
	return DB.Self.Save(u).Error
}

func GetUserByAccount(account string ) (*UserModel, error) {
	u := &UserModel{}
	d := DB.Self.Table("tbl_user").Where("account = ?", account).First(u)
	return u, d.Error
}

func GetUserByAccountAndPassword(account string , accountPassword string) (*UserModel, error) {
	u := &UserModel{}
	d := DB.Self.Table("tbl_user").Where("account = ? AND account_password = ?", account, accountPassword).First(u)
	return u, d.Error
}

func GetUserById(uid int) (*UserModel, error) {
	u := &UserModel{}
	d := DB.Self.Table("tbl_user").Where("id = ?", uid).First(u)
	return u, d.Error
}*/
