CREATE DATABASE MyDatabase;
use  `MyDatabase`;


-- 用户信息表(user)
create table `user`(
   `id`         int not null    AUTO_INCREMENT comment "id",       
   `studentId`  varchar(20)     null comment "学号",
   `gender`     varchar(30)     null comment "性别",
   `name`       varchar(20)     null comment "姓名",
   `age`        int             null comment "年龄",
   `classId`    int             null comment "班级ID",
  
-- 添加约束
primary key (`id`),
FULLTEXT (`studentId`) WITH PARSER ngram

) ENGINE=InnoDB DEFAULT CHARSET=UTF8MB4;

 INSERT INTO user(studentId,gender,name,age,classId) VALUES(2020213701,'女','Jenny',21,1);  
 INSERT INTO user(studentId,gender,name,age,classId) VALUES(2020213702,'女','Andrew',17,1);  
 INSERT INTO user(studentId,gender,name,age,classId) VALUES(2020213703,'女','Gavin',8,1);  
 INSERT INTO user(studentId,gender,name,age,classId) VALUES(2020213704,'男','Duncan',6,1);  
 INSERT INTO user(studentId,gender,name,age,classId) VALUES(2020213705,'男','Emma',4,1);  
 INSERT INTO user(studentId,gender,name,age,classId) VALUES(2020213706,'男', 'Alex',15,1);  
 INSERT INTO user(studentId,gender,name,age,classId) VALUES(2020213707,'男','Adrian',9,1);  



