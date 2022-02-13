# 黑马MySql学习


![image-20220213092011226](https://s2.loli.net/2022/02/13/hc9DBmNTZdGQyAj.png)

## p02数据库相关概念

SQL(Structrued Query language):操作关系型数据库的编程语言，定义了==一套操作关系型数据库统一标准==；

主流的关系型数据库管理系统：Qracle,MySql;SQL server

## p03MySql下载安装

官网下载安装；

这里遇到一个问题，服务器未安装，---》这里要安装一个MYSQL Server 8.28-X64 

还有一个问题net start mysql80 发生系统错误 5-----》这里cmd打开要用管理员权限

客户端连接

```SQL
net start mysql80
mysql自带客户端命令启动
mysql [-h 127.0.0.1] [-p 3306] -u root -p
```



## p04-数据模型

- 关系型数据库（RDBMS)

概念：建立在关系模型的基础上，由多张相互连接的==二维表==组成的数据库

| id   | name | job  | dept_id |
| ---- | ---- | ---- | ------- |
| 1    | JY   | zong | 2       |
| 2    | xx   | xx   | 1       |
| 3    | xx   | xx   | 3       |

特点：

1. 使用表存储数据，格式统一，便于维护
2. 使用SQL语言操作，标准统一，使用方便

-   数据模型

客户端-----》DBMS-----》数据库（表）

## p05通用语法及分类

SQL

- SQL通用语法

1. 单行或多行，分号结尾
2. 空格 缩进
3. 不区分大小写，关键字用大写
4. 注释

> - 单行注释 --注释内容或#注释内容
> - 多行注释 /* */

SQL分类

DDL:数据定义语言，用来定义数据库对象（数据库，表，字段）

DML：数据操作语言，用来对数据库表中的数据进行增删改

DQL：数据查询语言，用来查询数据库中表的记录

DCL：数据控制语言，用来创建数据库用户、控制数据库的访问权限

## p06DDL数据库操作

```sql
查询所有数据库：show databases;
查询当前数据库：select database();
创建
create database [if not exists]数据库名 [default charset 字符集][collate 排序规则];


mysql> create database itcast;
Query OK, 1 row affected (0.01 sec)

mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| itcast             |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
5 rows in set (0.01 sec)

mysql> create database itheima default charset utf8mb4;
Query OK, 1 row affected (0.01 sec)

mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| itcast             |
| itheima            |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
6 rows in set (0.00 sec)

删除 
drop database [if exists]数据库名;

mysql> drop database itcast;
Query OK, 0 rows affected (0.01 sec)

mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| itheima            |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
5 rows in set (0.00 sec)

使用
use 数据库名;

mysql> use itheima;
Database changed
mysql> select database;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '' at line 1
mysql> select database();
+------------+
| database() |
+------------+
| itheima    |
+------------+
1 row in set (0.00 sec)
```

## p07 DDL 创建&查询

```sql
查询当前数据库所有表
show tables;

show tables;
Empty set (0.00 sec)

mysql> use sys;
Database changed
mysql> show tables;
+-----------------------------------------------+
| Tables_in_sys                                 |
+-----------------------------------------------+
| host_summary                                  |
| host_summary_by_file_io                       |
| host_summary_by_file_io_type                  |
| host_summary_by_stages                        |
| host_summary_by_statement_latency             |
-------------------------------------------------

查询表结构
DESC 表名；

查询指定表的建表语句
show create table 表名

```

DDL-表操作---创建

```sql
create table 表名(
	字段1 字段1类型[comment 注释],
    字段2 字段2类型[comment 注释],
    字段3 字段3类型[comment 注释],
	....
    最后一个不加分号
)

create table tb_user(
    id int comment '编号',
    name varchar(50) comment '姓名',
    age  int comment '年龄',
    gender varchar(1) comment '性别'
) comment '用户表';


mysql> create table tb_user(
    ->     id int comment '编号',
    ->     name varchar(50) comment '姓名',
    ->     age  int comment '年龄',
    ->     gender varchar(1) comment '性别'
    -> ) comment '用户表';
Query OK, 0 rows affected (0.03 sec)

mysql> show tables;
+-------------------+
| Tables_in_itheima |
+-------------------+
| tb_user           |
+-------------------+
1 row in set (0.01 sec)



mysql> desc tb_user;
+--------+-------------+------+-----+---------+-------+
| Field  | Type        | Null | Key | Default | Extra |
+--------+-------------+------+-----+---------+-------+
| id     | int         | YES  |     | NULL    |       |
| name   | varchar(50) | YES  |     | NULL    |       |
| age    | int         | YES  |     | NULL    |       |
| gender | varchar(1)  | YES  |     | NULL    |       |
+--------+-------------+------+-----+---------+-------+
4 rows in set (0.00 sec)

mysql> show create table tb_user;
+---------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Table   | Create Table                                                                                                                                                                                                                                                                                      |
+---------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| tb_user | CREATE TABLE `tb_user` (
  `id` int DEFAULT NULL COMMENT '编号',
  `name` varchar(50) DEFAULT NULL COMMENT '姓名',
  `age` int DEFAULT NULL COMMENT '年龄',
  `gender` varchar(1) DEFAULT NULL COMMENT '性别'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='用户表' |
+---------+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
1 row in set (0.01 sec)
```

| id   | name     | age  | gender |
| ---- | -------- | ---- | ------ |
| 1    | 令狐冲   | 28   | 男     |
| 2    | 风清扬   | 68   | 男     |
| 3    | 东方不败 | 32   | 男     |

## p08 DDL 数据类型及案例

数据类型

主要分为三类：数值类型、字符串类型、日期时间类型；

![image-20220213110112571](https://s2.loli.net/2022/02/13/DNqkb4iIXWCfrwA.png)

```sql
age TINYINT UNSIGNED
score double(4,1) 最长为4位，1为小数位数；
```

![image-20220213110455360](https://s2.loli.net/2022/02/13/tEahqmTYCkfyocI.png)

```sql
char(10) 10为能存储的最大长度 10个字符， 小于10，空格补齐
varchar(10)
差异：char 性能好，varchar 性能差一点

用户名 username varchar(50);
性别gender char(1);
```

![image-20220213110903919](https://s2.loli.net/2022/02/13/ea7fUPCJnlKAjiY.png)

```sql
birthday date
```

案例分析

![image-20220213111020505](https://s2.loli.net/2022/02/13/KZJzS6nTdmhVk5t.png)

```sql
create table emp(
	id int comment '编号',
    workno varchar(10) comment '员工工号',
    name varchar(10) comment '员工姓名',
    gender char(1) comment '性别',
    age TINYINT UNSIGNED comment '年龄',
    idcard char(18) comment '身份证号',
    entrydate date comment '入职时间'
) comment '员工表';


mysql> create table emp(
    -> 	   id int comment '编号',
    ->     workno varchar(10) comment '员工工号',
    ->     name varchar(10) comment '员工姓名',
    ->     gender char(1) comment '性别',
    ->     age TINYINT UNSIGNED comment '年龄',
    ->     idcard char(18) comment '身份证号',
    ->     entrydate date comment '入职时间'
    -> ) comment '员工表';
Query OK, 0 rows affected (0.02 sec)

mysql> desc emp;
+-----------+------------------+------+-----+---------+-------+
| Field     | Type             | Null | Key | Default | Extra |
+-----------+------------------+------+-----+---------+-------+
| id        | int              | YES  |     | NULL    |       |
| workno    | varchar(10)      | YES  |     | NULL    |       |
| name      | varchar(10)      | YES  |     | NULL    |       |
| gender    | char(1)          | YES  |     | NULL    |       |
| age       | tinyint unsigned | YES  |     | NULL    |       |
| idcard    | char(18)         | YES  |     | NULL    |       |
| entrydate | date             | YES  |     | NULL    |       |
+-----------+------------------+------+-----+---------+-------+
7 rows in set (0.01 sec)
```



## p09 DDL -表操作-修改&删除

DDL -表操作-修改

表中添加字段，修改表中字段，删除表中字段，修改表名

```sql
添加字段
alter table 表名 add 字段名 类型（长度） [comment 注释] [约束];

案例：为emp表增加新的字段“昵称”为nickname， 类型为varchar(20);
alter table emp add nickname varchar(20) comment '昵称';

mysql> alter table emp add nickname varchar(20) comment '昵称';
Query OK, 0 rows affected (0.01 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> desc emp;
+-----------+------------------+------+-----+---------+-------+
| Field     | Type             | Null | Key | Default | Extra |
+-----------+------------------+------+-----+---------+-------+
| id        | int              | YES  |     | NULL    |       |
| workno    | varchar(10)      | YES  |     | NULL    |       |
| name      | varchar(10)      | YES  |     | NULL    |       |
| gender    | char(1)          | YES  |     | NULL    |       |
| age       | tinyint unsigned | YES  |     | NULL    |       |
| idcard    | char(18)         | YES  |     | NULL    |       |
| entrydate | date             | YES  |     | NULL    |       |
| nickname  | varchar(20)      | YES  |     | NULL    |       |
+-----------+------------------+------+-----+---------+-------+
8 rows in set (0.01 sec)
```

修改数据类型

```sql
alter table 表名 modify 字段名 新的数据类型（长度）;

```

修改字段名和字段类型

```sql
alter table 表名 change 旧字段名 新字段名 类型（长度） [comment 注释][约束];

例子：将emp表中的nickname字段修改为username,类型为varchar(30)；
alter table emp change nickname username varchar(30) comment '用户名';

mysql> alter table emp change nickname username varchar(30) comment '用户名';
Query OK, 0 rows affected (0.01 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> desc emp;
+-----------+------------------+------+-----+---------+-------+
| Field     | Type             | Null | Key | Default | Extra |
+-----------+------------------+------+-----+---------+-------+
| id        | int              | YES  |     | NULL    |       |
| workno    | varchar(10)      | YES  |     | NULL    |       |
| name      | varchar(10)      | YES  |     | NULL    |       |
| gender    | char(1)          | YES  |     | NULL    |       |
| age       | tinyint unsigned | YES  |     | NULL    |       |
| idcard    | char(18)         | YES  |     | NULL    |       |
| entrydate | date             | YES  |     | NULL    |       |
| username  | varchar(30)      | YES  |     | NULL    |       |
+-----------+------------------+------+-----+---------+-------+
8 rows in set (0.00 sec)
```

DDL-表操作-修改

```sql
删除字段
alter table 表名 drop 字段名;

例子：将emp表中的字段username删除
alter table emp drop username;

mysql> alter table emp drop username;
Query OK, 0 rows affected (0.03 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> desc emp;
+-----------+------------------+------+-----+---------+-------+
| Field     | Type             | Null | Key | Default | Extra |
+-----------+------------------+------+-----+---------+-------+
| id        | int              | YES  |     | NULL    |       |
| workno    | varchar(10)      | YES  |     | NULL    |       |
| name      | varchar(10)      | YES  |     | NULL    |       |
| gender    | char(1)          | YES  |     | NULL    |       |
| age       | tinyint unsigned | YES  |     | NULL    |       |
| idcard    | char(18)         | YES  |     | NULL    |       |
| entrydate | date             | YES  |     | NULL    |       |
+-----------+------------------+------+-----+---------+-------+
7 rows in set (0.01 sec)
```

修改表名

```sql
alter table 表名 rename to 新表名;

例子：将emp表的表名修改为employee；
alter table emp rename to employee;

mysql> alter table emp rename to employee;
Query OK, 0 rows affected (0.01 sec)

mysql> desc emp;
ERROR 1146 (42S02): Table 'itheima.emp' doesn't exist
mysql> show tables;
+-------------------+
| Tables_in_itheima |
+-------------------+
| employee          |
| tb_user           |
+-------------------+
2 rows in set (0.00 sec)
```

DDL -表操作-删除

```sql
删除表
drop table [if exists] 表名;
删除指定表，并重新创建该表
truncate table 表名;

mysql> drop table if exists tb_user;
Query OK, 0 rows affected (0.02 sec)

mysql> show tables;
+-------------------+
| Tables_in_itheima |
+-------------------+
| employee          |
+-------------------+
1 row in set (0.01 sec)

mysql> truncate table employee;
Query OK, 0 rows affected (0.02 sec)

mysql> show tables;
+-------------------+
| Tables_in_itheima |
+-------------------+
| employee          |
+-------------------+
1 row in set (0.00 sec)

truncate table 将表中的数据全部删除，然后重新创建一张全新的表格。
```

## p10 DDL 语句总结

1. DDL-数据库操作

```sql
show tables;
create database 数据库名;
use 数据库名;
select DATABASE();  查看当前数据库
drop database 数据库名称；
```

2. DDL -表操作

```sql
show tables;
create  table 表名(字段 字段类型，字段，字段类型);
desc 表名;  //查看当前表结构
show create table 表名;
alter table 表名 add /modify /change/drop/rename to...;
drop table 表名;
```

## p11 SQL-图像化工具DataGrip

MySQL 图像化界面

sqlyog; navicat;datagip

dataGRIP安装与破解

后续破解

## p12 DML-插入

DML：数据操作语言，用来对数据库表中的==数据==进行增删改

- 添加数据 （INSERT)
- 修改数据 （UPDATE)
- 删除数据 （DELETE)

DML-添加数据

```sql
1.给指定字段添加数据
insert into 表名(字段1 ,字段2,...) values(值1,值2,...)

2.给全部字段添加数据
insert into 表名 values(值1，值2,...)

3.批量添加数据
insert into 表名(字段1,字段2,...) values(值1,值2,...),(值1,值2,...)；
insert into 表名 values(值1,值2,...),(值1,值2,...),(值1,值2,...);

注意：
(1)插入数据时，指定字段顺序与值一一对应
(2)字符串和日期数据应该包含在引号中
(3)插入的数据大小，应该在字段的规定范围内

案列：

mysql> insert into employee (id, workno, name, gender, age, idcard, entrydate) values (1,'1','itcast','男',10,'123456789012345678','2000-01-01');
Query OK, 1 row affected (0.01 sec)

mysql> select * from employee;
+------+--------+--------+--------+------+--------------------+------------+
| id   | workno | name   | gender | age  | idcard             | entrydate  |
+------+--------+--------+--------+------+--------------------+------------+
|    1 | 1      | itcast | 男     |   10 | 123456789012345678 | 2000-01-01 |
+------+--------+--------+--------+------+--------------------+------------+
1 rows in set (0.00 sec)
```

## p13 DML-更新和删除

DML-修改数据

```sql
update 表名 set 字段名1 = 值1 ,字段名2 = 值2,...[where 条件];
注意：修改语句的条件可以有，也可以没有，如果没有条件，则会修改整张表的所有数据

-- 修改id为1的数据，将name修改为itheima
update employee set name = 'itheime' where id = 1;

-- 修改id为1的数据，将name修改为 小昭，gender修改为女
update employee set name = '小昭',gender = '女' where id = 1;

-- 将所有员工的入职日期修改为2008-01-01;
update employee set entrydate = '2008-01-01';
```

DML-删除数据

```sql
delete from 表名 [where 条件]
注意：
(1)delete语句条件可以有，也可以没有，如果没有条件，则会删除整张表的所有数据。
(2)delete语句不能删除某一个字段的值（可以使用update）;


-- 删除gender为女的员工
delete from employee where gender = '女';

-- 删除所有员工
delete from employee
```

## p14DML 小结

1. 添加数据

```sql
insert into 表名(字段1 ,字段2,...) values(值1,值2,...)
```

2. 修改数据

```sql
update 表名 set 字段名1 = 值1 ,字段名2 = 值2,...[where 条件];
```

3. 删除数据

```sql
delete from 表名 [where 条件]
```

## p15 DQL-基础查询

DQL：数据查询语言，用来**查询**数据库中表的记录

查询关键字：==SELECT==

DQL-语法

```sql
select 
	字段列表
from
	表名列表
where
	条件列表
group by
	分组字段列表
having
	分组后条件列表
order by
	排序字段列表
limit
	分页参数
```

- 基本查询
- 条件查询（where)
- 聚合函数（count,max,min,avg,sum）
- 分组查询（group by)
- 排序查询（order by)
- 分页查询（limit)

DQL-基本查询

```sql
1.查询多个字段
select 字段1，字段2，字段3...from 表名;
select * from 表名;

2.设置别名
select 字段1 [as 别名1],字段2 [as 别名2]... from 表名;

3.去除重复记录
select distinct 字段列表 from 表名;
```

```sql
insert into emp(id, workno, name, gender, age, idcard, workaddress, entrydate)
values (1,'1','柳岩','女',20,'123456789012345678','北京','2000-01-01'),
       (2,'2','张无忌','男',29,'123456789012345678','北京','2009-09-01'),
       (3,'3','韦一笑','男',21,'123456789012345678','北京','2008-01-01'),
       (4,'4','柳岩','女',22,'123456789012345678','北京','2000-01-01'),
       (5,'5','柳而岩','女',23,'123456789012345678','北京','2000-09-01');
       
insert into emp (id, workno, name, gender, age, idcard, workaddress, entrydate)
values (7,'7','aff岩','女',28,null,'上海','2008-09-01');


-- 基本查询
-- 1.查询指定字段 name,workno,age返回
select name,workno,age from emp;

柳岩,1,20
张无忌,2,29
韦一笑,3,21
柳岩,4,22
柳而岩,5,23

-- 2.查询所有字段返回
select id, workno, name, gender, age, idcard, workaddress, entrydate from emp;
select * from emp;

-- 3.查询所有员工工作地址，起别名
select workaddress as '工作地址' from emp;

-- 4.查询公司员工工作地址（不要重复）
select distinct workaddress as '工作地址' from emp;
```

## p16 DQL-条件查询

DQL-条件查询

1.语法

```sql
select 字段列表 from 表名 where 条件列表
```

2.条件（如下图）

![image-20220213160039507](https://s2.loli.net/2022/02/13/riGKOjaxM2ZtDlF.png)

```sql
-- 条件查询
-- 1.查询年龄等于21的员工
select * from emp where age=21;

-- 2.查询年龄小于40的员工
select * from emp where age < 40;

-- 3.查询年龄小于等于20
select * from  emp where age <=20;

-- 4.查询没有身份证号的员工
select * from emp where idcard is null ;

-- 5.查询有身份证号员工
select * from emp where idcard is not null ;

-- 6.查询年龄在15（含）到23(含）之间
select * from emp where age>=15 && age <= 23;
select * from emp where age>=15 and age <= 23;

select * from emp where age between 15 and 23;

-- 7.性别为女，年龄小于22岁
select * from emp where gender = '女' and  age < 22;

-- 8.查询年龄等于18 或20 或者23的员工信息
select * from emp where age = 18 or  age = 20 or age = 23;
select * from emp where age in (18,20,23);

-- 9.查询姓名为两个字的员工
select * from emp where name like '__';

-- 10.查询身份证号最后一位是8的员工;
select * from emp where idcard like '%8';
```

## p17 DQL-聚合函数

DQL-聚合函数

1. 介绍

将一==列==数据作为一个整体，进行纵向计算

2. 常见聚合函数

```sql
count 统计数量
max 最大值
min 最小值
avg 平均值
sum 求和
```

3. 语法

   ```sql
   select 聚合函数(字段列表) from 表名;
   
   注意：null值不参与所有聚合函数的运算
   ```

4. 案例

```sql
-- 聚合函数
-- 1.统计员工数量
select count(*) from emp; -- 7
select count(id) from emp; -- 7
select count(idcard) from emp; -- 6

-- 2.统计员工的平均年龄
select avg(age) from emp; -- 23.7143

-- 3.最大年龄
select max(age) from emp; -- 29

-- 4. 最小年龄
select min(age) from emp; -- 20

-- 5.统计北京地区员工的年龄之和
select * from  emp where workaddress ='北京';
select sum(age) from emp where workaddress = '北京';  -- 115
```

## p18 DQL-分组查询

DQL-分组查询

1. 语法

```sql
select 字段列表 from 表名 [where 条件] group by 分组字段 [having 分组后过滤条件];
```

2. where和having 区别

- 执行时间不同：where是分组之前进行过滤，不满足where条件，不参与分组；而having是分组之后对结果进行过滤.
- 判断条件不同：where不能对聚合函数进行判断，而having可以

3. 实现

```sql
-- 分组查询
-- 1，根据性别分组，统计男性员工和女性员工数量
select gender,count(*) from emp group by gender;
-- 女,5
-- 男,2

-- 2. 根据性别分组，统计男性和女性的平均年龄
select gender,avg(age) from emp group by gender;

-- 3. 查询年龄小于40的员工，并能够根据工作地址分组，获取员工数量大于等于3的工作地址;
select workaddress, count(*) address_count from emp where age < 40 group by workaddress having address_count >= 3;
-- address_count 为count(*) 起的别名;
-- 北京,5
```

注意事项：

- 执行顺序：where > 聚合函数 > having.
- 分组之后，查询的字段一般为==聚合函数==和==分组字段==，查询其他字段没有意义。

```sql
select  name ,gender,count(*) from emp group by gender;
柳岩,女,5
张无忌,男,2
这个name字段没有任何意义；
```

## p19 DQL-排序查询

DQL-排序查询

1. 语法

```sql
select 字段列表 from 表名 order by 字段1 排序方式1,字段2,排序方式2;
支持多字段排序
```

2. 排序方式

- ASC ：升序（默认）
- desc :降序

注意：如果是多字段排序，当第一个字段值相同时，才会根据第二个字段进行排序

3. 案例

```sql
-- 排序查询
-- 1.根据年龄对公司的员工升序
select  * from emp order by age asc;
select  * from emp order by  age desc ;

-- 2.根据入职时间，员工降序排序
select  * from emp order by entrydate desc ;

-- 3.根据年龄对公司员工升序排序，年龄相同，再按照入职时间进行降序排序
select * from emp order by age asc,entrydate desc ;
```

## p20 DQL-分页查询

DQL-分页查询

1. 语法

```sql
select 字段列表 from 表名 limit 起始索引，查询记录数;
```

注意事项：

- 起始索引从0开始，起始索引 =（查询页码 -1） * 每页显示记录数；
- 分页查询是数据库方言，不同的数据库有不同的实现，MySQL中是LIMIT；
- 如果查询的是第一页数据，起始索引可以省略，直接简写为limit10.

2. 实现

```sql
-- 分页查询
-- 1.查询第一页员工数据，每页展示5条记录,两个参数，第一页起始索引从0开始，每页5条记录，0可以省略
select * from emp limit 0, 5;
select * from emp limit 5;

-- 2.查询第2页员工数据，每页展示5条记录------》起始索引=（页码-1）*每页数目
select * from emp limit 5,5;
```

## p21 DQL- 案例练习

![image-20220213171545903](https://s2.loli.net/2022/02/13/Ks56Gzm187UxJug.png)

```sql
-- DQL练习
-- 1.查询年龄为20，21，22，23岁女性员工信息
select * from emp where age in (20,21,22,23) and gender = '女';

-- 2. 查询性别为男，并且年龄再20-40岁（含）以内的姓名为三个字的员工
select * from emp where age >= 20 && age <= 40 and gender = '男' and name like '___';

-- 3.统计员工表中，年龄小于60岁，男性员工和女性员工人数
select gender,count(*) from emp where age < 60 group by gender;

-- 4.查询所有年龄小于等于35岁员工的姓名和年龄，并对查询结果按年龄升序排序，如果年龄相同按入职时间降序排序
select name,age from emp where age <= 35 order by age asc,entrydate desc;

-- 5.查询性别为男，且年龄在20-40岁（含）以内的前5个员工信息，对查询的结果按年龄升序排序，如果年龄相同按入职时间降序排序 --- limit放在最后
select * from emp where gender = '男' and age between 20 and 40 order by age asc,entrydate desc limit 5;
```

## p22 DQL-执行顺序

![image-20220213214128461](https://s2.loli.net/2022/02/13/ySiFaz6tL3YTNnj.png)

```sql
select e.name,e.age from emp e where e.age > 15 order by age;

from 
where 
select
order by 
limit
```

## p23 DQL小结

1. DQL语句

```sql
select 
	字段列表--------->字段名[AS]别名
from
	表名
where
	条件列表---- 》 >、>=、<= 、like,between ...and / in / and /or;分组之前过滤
group by
	分组字段列表 
having
	分组后条件列表 -----》分组之后过滤
order by
	排序字段列表 -----》升序asc,降序desc;
limit
	分页参数-------》起始索引(从0开始)，每页展示记录数
```



## p24 DCL-用户管理

DCL(data control language)：数据控制语言，用来创建数据库用户、控制数据库的访问权限

DCL-管理用户

1. 查询用户

```sql
use mysql;
select * from user;
```

2. 创建用户

```sql
create user '用户名'@'主机名' identified by '密码';
```

3. 修改用户密码

```sql
alter user '用户名'@'主机名' identified with mysql_native_password by '新密码';
```

4. 删除用户

```sql
drop user '用户名'@'主机名';
```

注意：

- 主机名可以使用%通配；
- 这类SQL开发人员操作比较少，主要是DBA(数据库管理员)使用；

5. 实现

```sql
-- DCL管理用户
-- 创建用户ithm,只能在当前主机localhost访问，密码123456; 创建用户但是没有访问数据库的权限
create user 'ithm'@'localhost' identified by '123456';

-- 创建用户heima，可以在任意主机访问该数据库，密码123456;
create user  'heima'@'%' identified by '1234567';

-- 修改用户heima的访问密码为1234;
alter user 'heima'@'%' identified with mysql_native_password by '1234';

-- 删除ithm@localhost用户
drop user  'ithm'@'localhost';
```

## p25 DCL-权限控制

DCL-权限控制

![image-20220213221045059](https://s2.loli.net/2022/02/13/hpId7WEX5ingkta.png)

1. 查询权限

```sql
show grants for '用户名'@'主机名';
```

2. 授予权限

```sql
grants 权限列表 on 数据库名.表名 to '用户名'@'主机名';
```

3. 撤销权限

```sql
revoke 权限列表 on 数据库名.表名 from '用户名'@'主机名';
```

4. 实现

```sql
-- DCl权限控制
-- 查询权限
show grants for 'heima'@'%'; -- GRANT USAGE ON *.* TO `heima`@`%`

-- 授予权限
grant all on itheima.* to 'heima'@'%';

-- 撤销权限
revoke all on itheima.* from 'heima'@'%';
```

注意事项：

- 多个权限之间，使用逗号分隔；
- 授权时，数据库名和表名可以使用* 进行通配，代表所有；

## p26 DCL小结

1. 用户管理

```sql
创建用户
create user '用户名'@'主机名' identified by '密码';

修改用户密码
alter user '用户名'@'主机名' identified with mysql_native_password by '新密码';

删除用户
drop user '用户名'@'主机名';
```

2. 权限控制

```sql
查询权限
show grants for '用户名'@'主机名';

授予权限
grants 权限列表 on 数据库名.表名 to '用户名'@'主机名';

撤销权限
revoke 权限列表 on 数据库名.表名 from '用户名'@'主机名';
```

## p27 函数-字符串函数

函数 ：指的是一段可以直接被另一个程序调用的程序或者代码；

包括字符串函数、数值函数、日期函数、流程函数；

![image-20220213222827043](https://s2.loli.net/2022/02/13/idvVBLtKhUaXA9E.png)

```sql
-- 函数演示
-- concat
select  concat ('hello','MySQL');

-- lower
select  lower('HELLO');

-- upper
select  upper('hello');

-- lpad
select  lpad('01',5,'-'); -- ---01

-- rpad
select  rpad('01',5,'-'); -- 01---

-- trim
select trim("   hello mysql  "); -- hello mysql

-- substring
select substring('hello MySQL',1,5); -- hello
```

练习：由于业务去求变更，企业员工的工号，统一为5位数，目前不足5位数的全部在前面补0。比如：1号员工的工号为00001

```sql
update emp set workno = lpad(workno,5,'0');
```

## p28 函数-数值函数

![image-20220213223927449](https://s2.loli.net/2022/02/13/UPkV916S4w8LFmf.png)

```sql
-- 数值函数
-- ceil
select  ceil(0.6); -- 1
select ceil(1.1); -- 2

-- floor
select floor(1.1); -- 1
select floor(1.9); -- 1
-- mod
select mod(7,3); -- 1

-- rand
select rand();

-- round
select round(2.345,2); -- 2.35
```

练习:通过数据库的函数，生成一个六位数的随机验证码；

```sql
-- 练习:通过数据库的函数，生成一个六位数的随机验证码；
select round(1000000*rand(),0);  -- 0.066984 ----》66984

select rpad(round(1000000*rand(),0),6,'0'); -- 不够六位，右边补0;
```

## p29 函数-日期函数

![image-20220213225353389](https://s2.loli.net/2022/02/13/5fZudnlOXtAMKJx.png)

```sql
-- 日期函数
-- curdate
select  curdate();

-- curtime
select  curtime();

-- now
select now();

-- year
select year(now());

-- month
select month(now());
-- day
select day(now());

-- date_add
select date_add(now(),interval 7 month );

-- datediff
select datediff('2021-12-28','2021-12-09');
```

练习:查询所有员工入职天数，并根据入职签署倒叙排序；

```sql
select name,datediff(now(),entrydate)  as diff from emp order by  diff desc;
```

## p30 函数-流程函数

![image-20220213230310693](https://s2.loli.net/2022/02/13/NiehlaV8ju1Q9pO.png)

```sql
-- 流程控制函数
-- if
select if(true,'OK','Error');

-- ifnull
select ifnull('OK','Default'); -- OK;

select ifnull('','Default'); -- 返回空串

select ifnull(null,'Default'); -- Default;

-- case when then else end
-- 需求:查询emp表得到员工姓名和工作地址（北京--->首都，上海---->魔都，其他--》其他）
select
       name,
       (case workaddress when '北京' then '首都' when '上海' then '魔都' else '其他'end) as '工作地址'
from emp;
```

练习：统计学员成绩，大于等于85为优秀；大于等于60为及格；否则展示位不及格；

```sql
-- 案例
create table score(
    id int comment 'ID',
    name varchar(20) comment '姓名',
    math int comment '数学',
    english int comment '英语',
    chinese int comment '语文'
)comment '学员成绩表';
insert into score(id, name, math, english, chinese)
values (1,'Tom',67,88,95),(2,'Rose',23,66,90),(3,'Jack',56,98,76);


--
select
    id,
    name,
    (case when math >= 85 then '优秀' when math >= 60 then '及格' else '不及格' end) as '数学',
    (case when english >= 85 then '优秀' when english >= 60 then '及格' else '不及格' end) as '英语',
    (case when chinese >= 85 then '优秀' when chinese >= 60 then '及格' else '不及格' end) as '语文'
from score
```

![image-20220213232202840](https://s2.loli.net/2022/02/13/42JBZWACRQ3aVpz.png)

![image-20220213232225761](https://s2.loli.net/2022/02/13/VW2tpKRbfYydc79.png)

## p31 函数-小结

1. 字符串函数

```sql
concat ,lower,upper,lpad,rpad,trim,substring
```

2. 数值函数

```sql
ceil ,floor,mod,rand,round
```

3. 日期函数

```sql
curdate,curtime,now,year,month,day,date_add,datediff
```

4. 流程函数

```sql
if,ifnull,case[...]when ... then ... else... end;
```

