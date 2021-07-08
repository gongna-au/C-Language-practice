
use  `MyDatabase2`


-- 学生信息表(student)
create table `student`(
       
   `studentId`         varchar(20)     not null    comment "学生学号",
   `studentName`       varchar(20)     null        comment "学生姓名",
   `studentSex`        varchar(20)     not null    comment "学生性别",
   `studentAge`        int             null        comment "学生年龄",
   `studentTel`        varchar(255)    null        comment "学生电话",
  
-- 添加约束
primary key (`studentId`)

);




-- 作者信息表(author)
create table `authorTable`(
       
   `authorId`        int             not null      comment "作者ID",
   `authorName`      varchar(20)     null          comment "作者名称",
   `authorCity`      varchar(20)     null          comment "作者城市",
   
  
-- 添加约束
primary key (`authorId`)
);





-- 出版社信息表(press)
create table `press`(
       
   `pressId`       int            AUTO_INCREMENT   comment "出版社ID",
   `pressName`     varchar(20)     null            comment "出版社名称",
   `pressMark`     varchar(20)     null            comment "出版社备注",
   
  
-- 添加约束
primary key (`pressId`)
);







-- 图书类别信息表(bookType)
create table `bookType`(
       
   `bookTypeId`       int        AUTO_INCREMENT    comment "图书类别ID",
   `bookName`     varchar(40)     null             comment "图书名称",
   `bookMark`     varchar(50)     null             comment "图书备注",
   
  
-- 添加约束
primary key (`bookTypeId`)

);





-- 图书信息表(book)
create table `book`(
       
   `bookId`         int not null    AUTO_INCREMENT comment "图书ID",
   `bookName`       varchar(20)     null           comment "图书名称",
   `authorId`       int             not null       comment "作者ID",
   `bookTypeId`     int             null           comment "图书类别ID",
   `bookPrices`     float           null           comment "图书价格",
   `pressId`        int             null           comment "出版社ID",
   
  
-- 添加约束
primary key (`bookId`),
FOREIGN KEY (`bookTypeId`)   REFERENCES bookType(`bookTypeId`),
FOREIGN KEY (`authorId`)     REFERENCES authorTable(`authorId`),
FOREIGN KEY (`pressId`)      REFERENCES press(`pressId`)


);



-- 借书信息表(Borrowbook)
create table `Borrowbook`(
   `borrowId`       int             AUTO_INCREMENT    comment "借书ID",
   `studentId`      varchar(20)     not  null         comment "学生学号",
   `bookId`         int             not null          comment "图书ID",
   `authorId`       int             not null          comment "作者ID",
   `borrowTime`     date            not null          comment "借书时间",
  
-- 添加约束
primary key (`borrowId`),
FOREIGN KEY (`studentId`)   REFERENCES student(`studentId`),
FOREIGN KEY (`bookId`)      REFERENCES book(`bookId`)
);


/*

--查询语句join on
--使用join查询借书的人的姓名和电话以及借书时间并根据借书时间排序
--一个人可以借多本书
SELECT student.studentName, student.studentTel, Borrowbook.borrowTime
FROM student
INNER JOIN Borrowbook
ON Borrowbook.studentId = student.studentId
ORDER BY Borrowbook.borrowTime

--查询语句left join
--使用left join 查询每个学生的借书情况:借书时间和借书人姓名，可能有些学生没有借书

SELECT   Borrowbook.borrowId ,student.studentName,Borrowbook.borrowTime
FROM student
LEFT JOIN  Borrowbook
ON Borrowbook.studentId = student.studentId
ORDER BY Borrowbook.borrowTime

--查询语句union
--使用union 查询我们数据库里所有的人，并把他们放在一列
--不管是学生还是作者,检查他们的类型都是Varchar(20),符合要求所以可以查询
--查询结果 重复的人名将不会出现
--适用场景：当同一个人或事以不同的角色出现在多张表里，或者说是来自不同表的几列，他们都具有相同的属性
--比如说都是"人"，我们需要把这种属性单独列出来一列进行研究，
--值得注意的是：这来自不同表的几列之间重复的数据将不会出现

SELECT  student.studentName FROM student
UNION
SELECT author.authorName FROM author


--查询语句union all
--使用union 查询我们数据库里所有的人，并把他们放在一列，要求重复的人名不再出现
--查询结果重复的人名不会再次出现
--适用场景，当同一个人或事以不同的角色出现在多张表里，或者说是来自不同表的几列，他们都具有相同的属性
--比如说都是"人"，我们需要把这种属性单独列出来一列进行研究
--并且已经确定重复出现的数据就是同一个数据，只不过出现在了不同的列，这时用union all将不会筛选掉重复的数据
--没有指定排序方式时，新建表的排序就是按照扫描的顺序进行排序
SELECT  student.studentName FROM student
UNION
SELECT author.authorName FROM author





--插入语句   select into
--使用select into 语句可以创建表的备份文件，或者选取一个表的数据插入到同一个数据库下的另外一个表
--把学生表所有的列都插入到借书表
--情况1：选取所有列插入到同一个数据库下的另外一个表
SELECT *
INTO Borrowbook  
FROM student


--插入语句   select into
--使用select into 语句可以创建表的备份文件，或者选取一个表的数据插入到同一个数据库下的另外一个表
--把学生表的所有列都插入到另外一个数据库的学生表里
--情况2：选取所有列插入到另外一个数据库下的另外一个表
SELECT *
INTO student IN 'MyDatabase2'
FROM student


--插入语句  select into 
--使用select into 语句可以创建表的备份文件，或者选取一个表的数据插入到同一个数据库下的另外一个表
--把学生表的学生姓名列和学生电话列都插入到同一个数据库的借书表里
--情况3：选取特定列插入到同一个数据库下的另外一个表
SELECT student.studentName,student.studentTel
INTO Borrowbook
FROM student


--约束语句 constraints-not null
--适用场景 某个表里只能加入特定数据类型的数据
--not null
--意味着，如果不向某个字段添加数据，就无法往表里插入一条数据
not null


--约束语句 constraints--unique
--适用场景:某一列的数据的每一行都是独一无二的
--unique
--意味着当要准备插入的新数据与原来的重复时，就无法插入这条新数据
unique


--约束语句 constraints--primary key
--适用场景:每个表都需要一个主键来唯一标识每一条数据
--并且每个表只能有一个主键。
primary key

--约束语句 constraints--foreign key
--适用场景:表与表之间的关系，可以根据一个表查询到另外一个表时
--一个表里的foreign key 指向的一定是另外一个表的primary key
--一个表可以有多个foreign key 具体看业务需要：也就是你希望通过哪个表查到哪个表的哪个信息。
foreign key


--约束语句 constraints--check
--适用场景:对某一列的数据有约束，或对某个表有约束，具体表现还是在约束表的某一列
--情况1：对一列进行约束
check


--约束语句 constraints-- constraint check
--适用场景:对某几列的数据有约束，或对某个表有约束，具体表现还是在约束表的那几列
--情况1：对几列进行约束
constraint check


--约束语句 constraints-- default
--适用场景:当给某个字段不添加值时，字段的把默认的值添加到字段中
default


--创建索引语句--create index
--适用场景:我不读取整个表，但是我可以很快的查找到数据
--用户无法看到索引，但是可以加快查找
--更新有索引的表往往比没有索引的表慢，因为索引本身也需要更新。
--在学生表以学生姓名作为索引创建一个索引（给它起名为nameIndex）
--student.studentName这一列就是要索引的列
--创建结果:新建的索引可以使用建立索引那一列重复的值
--允许重复的索引值
--可以是多个列建立索引
--可以对索引排序
CREATE INDEX nameIndex
ON student (student.studentName)


--创建索引语句--create unique index
--适用场景:我不读取整个表，但是我可以很快的查找到数据
--用户无法看到索引，但是可以加快查找
--更新有索引的表往往比没有索引的表慢，因为索引本身也需要更新。
--在学生表以学生姓名作为索引创建一个索引（给它起名为nameIndex）
--student.studentName这一列就是要索引的列
--创建结果:新建的索引可以使用建立索引那一列重复的值
--不允许重复的索引值
--可以是多个列建立索引
--可以对索引排序CREATE  UNIQUE INDEX nameIndex ON student (student.studentName desc)
CREATE  UNIQUE INDEX nameIndex
ON student (student.studentName)


--自增语句Auto-increment 
--适用场景：给主键以Auto-increment 约束
--使得往表里每添加一条数据，自动的给约束那一列的值加上某个数值
--默认地，AUTO_INCREMENT 的开始值是 1，每条新记录递增 1。
--修改默认值要AUTO_INCREMENT=要修改的起始值


--创建视图
--更新视图
--删除视图
--给学生创建一个视图命名为studentView用来查看学生姓名为=安妮的人
CREATE VIEW studentView AS
SELECT student.studentName
FROM student
WHERE student.studentName='安妮'


CREATE OR REPLACE VIEW student AS
SELECT  student.studentName,studentAge
FROM student 
WHERE 

--视图总是显示最近的数据。每当用户查询视图时，数据库引擎通过使用 SQL 语句来重建数据
--可以从某个查询内部、某个存储过程内部，或者从另一个视图内部来使用视图。
--通过向视图添加函数、join 等等，我们可以向用户精确地提交我们希望提交的数据。


*/













