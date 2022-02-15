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

## p32 约束-概述

概述

1. 概念:约束是作用于表中字段上的规则，用于限制存储在表中的数据
2. 目的：保证数据库中的数据的正确，有效性和完整性。

3. 分类

![image-20220214145920777](https://s2.loli.net/2022/02/14/dMPuI5psGqDrzwQ.png)

注意：约束是作用于表中的字段上的，可以在创建表/修改表的时候添加约束。

## p33-约束-演示

![image-20220214150449452](https://s2.loli.net/2022/02/14/z5WH3fJeALEQVKR.png)

```sql
-- 约束演示
create database ithm;
show databases ;
use ithm;
create  table user(
    id int primary key auto_increment comment '主键',-- 主键并且自动增长
    name varchar(10)  not null unique comment '姓名',
    age int check( age > 0 && age <= 120) comment '年龄',
    status char(1) default '1' comment  '状态',
    gender char(1) comment '性别'
)comment  '用户表';

-- 插入数据
insert into user(name, age, status,gender)  values ('Tom1',19,'1','男'),('Tom2',25,'0','男');
insert into user(name, age, status,gender)  values ('Tom3',12,'1','男'); -- 重复插入不成功，主键也自增
```

## p34 约束-外键约束

约束-外键约束

概念：外键用来让两张表之间建立连接，从而保证数据的一致性和完整性。

![image-20220214152113700](https://s2.loli.net/2022/02/14/FTNLXo5sCy7rb3j.png)

有外键的称为子表，

注意：目前上述两张表，在数据库层面，并未建立外键关联，所以是无法保证数据的一致性和完整性的。

语法

```sql
1.添加外键
create table 表名(
    字段名	数据类型
    ...
    [comment] [外键名称]foreign key(外键字段名) references 主表(主表列名)
);
alter table 表名 add constraint 外键名称 foreign key(外键字段名) references 主表(主表列名)


2.删除外键
alter table 表名 drop foreign key 外键名称;
```

演示

```sql
-- 约束（外键）
-- 准备数据
create table dept(
    id int auto_increment  primary key comment 'ID',
    name varchar(50) not null comment '部门名称'
)comment '部门表';

insert into dept (id, name)
values (1,'研发部'),(2,'市场部'),(3,'财务部'),(4,'销售部'),(5,'总经办');

create table emp(
    id int auto_increment primary key comment 'ID',
    name varchar(50) not null comment '姓名',
    age int comment '年龄',
    job varchar(20) comment '职位',
    salary int comment '薪资',
    entrydate date comment '入职时间',
    manager int comment '直属领导ID',
    dept_id int comment  '部门ID'
)comment '员工表';

insert into emp (id, name, age, job, salary, entrydate, manager, dept_id)
values (1,'金庸',66,'总裁',20000,'2010-01-01',null,5),(2,'金庸',66,'总裁',20000,'2009-01-01',1,1),
(3,'金f庸',66,'总裁',20000,'2011-01-01',2,1),(4,'金gd庸',66,'总裁',20000,'2001-01-09',2,1);

-- 添加外键
alter table emp add constraint fk_emp_dept_id foreign key(dept_id) references dept(id);

-- 删除外键
alter table emp drop foreign key fk_emp_dept_id;
```

emp表：

![](https://s2.loli.net/2022/02/14/zMi9SHZYGjpLQwE.png)

dept表

![image-20220214155524663](https://s2.loli.net/2022/02/14/2elJ7TKfp6iUXtL.png)

添加外键之后

![image-20220214155615638](https://s2.loli.net/2022/02/14/YUfLNlaMH7tZhw4.png)

## p35 约束-外键删除更新行为

外键约束

- 删除/更新行为

![image-20220214154403758](https://s2.loli.net/2022/02/14/Di8Y45eINLoqEAX.png)

语法

```sql
alter table 表名 add constraint 外键名称 foreign key(外键字段名) references 主表名(主表字段名) on update 【cascade】 on delete 【cascade】;
```

演示

```sql
-- 外键的删除和更新行为

-- 先删除以上的外键，删除外键
alter table emp drop foreign key fk_emp_dept_id;

-- 增加约束cascade行为，一起变化
alter table emp add constraint fk_emp_dept_id foreign key(dept_id) references dept(id) on update cascade on delete  cascade ;
```

将研发部改为6后，此时dept表为

![image-20220214155814124](https://s2.loli.net/2022/02/14/xNqB1lvXbjr9U8S.png)

emp表为：

![image-20220214155903822](https://s2.loli.net/2022/02/14/d3oKmy1JSrnteF9.png)

## p36 约束-小结

1. 非空约束 ：`not null`
2. 唯一约束：`unique`
3. 主键约束：`primary key`（自增，`auto_increment`)
4. 默认约束：`default`
5. 检查约束：`check`
6. 外键约束：`foreign key`

## p37 多表查询-多表关系介绍

多表关系；多表查询概述；内连接；外连接；自连接；子查询；多表查询案例；

表结构之间的练习，基本上分为三种：一对多（多对一）、多对多、一对一；

- 一对多（多对一）

（1）案列：部门与员工的关系

（2）关系：一个部门对应多个员工，一个员工对应一个部门

（3)实现：在多的一方建立外键，指向一的一方的主键

![image-20220214161053788](https://s2.loli.net/2022/02/14/FrMznwIGck3CTUq.png)

- 多对多

（1）案例：学生和课程的关系

（2）关系：一个学生可以选修多门课程，一门课程也可以供多个学生选择

（3）实现：建立第三张中间表，中间表中至少包含两个外键，分别关联两方主键

![image-20220214161242166](https://s2.loli.net/2022/02/14/pmnRGXTlLHuOCoY.png)



```sql
-- 多对多
create table student(
    id int auto_increment primary key comment '主键ID',
    name varchar(10) comment '姓名',
    no varchar(10) comment '学号'
)comment '学生表';

insert into student values (null,'dai','20000'),(null,'fs','2023244'),(null,'fasgsg','115312532'),
                           (null,'fag','245235626');

create table course(
    id int auto_increment primary key comment '主键ID',
    name varchar(10) comment '课程名称'
)comment '课程表';

insert into course values (null,'java'),(null,'php'),(null,'mysql'),(null,'hadoop');

create table student_course(
    id int auto_increment primary key comment '主键',
    studentID int not null comment '学生ID',
    courseID int not null comment '课程ID',
    constraint fk_couresid foreign key (courseID) references course(id),
    constraint fk_studentid foreign key (studentID) references student(id)
)comment '学生课程中间表';

insert into student_course
values (null,1,1),(null,1,2),(null,1,3),(null,2,2),(null,2,3),(null,3,4);
```

![image-20220214162539144](https://s2.loli.net/2022/02/14/nHILor1RyZ4w8M9.png)

- 一对一

案列：用户与用户详情的关系

关系：一对一关系，多用于单表拆分，将一张表的基础字段放在一张表中，其他详情字段放在另一张表中，以提升操作效率。

**实现**：**在任意一方加入外键，关联另外一方的主键，并且设置外键为唯一的(`unique`)**

![image-20220214162907401](https://s2.loli.net/2022/02/14/Ao4VSMi6Gyf39aW.png)

拆分为以下：

![image-20220214163009444](https://s2.loli.net/2022/02/14/HoaRidJfI4X7vCy.png)

演示

```sql
-- 一对一
create table tb_user(
    id int auto_increment primary key comment '主键ID',
    name varchar(10) comment '姓名',
    age int comment '年龄',
    gender char(1) comment '1:男，2:女',
    phone char(11) comment '手机号'
)comment '用户基本信息表';

create table tb_user_edu(
    id int auto_increment primary key comment '主键ID',
    degree varchar(20) comment '学历',
    major varchar(50) comment '专业',
    primaryschool varchar(50) comment '小学',
    middleschool varchar(50) comment '中学',
    university varchar(50) comment '大学',
    userid int unique comment '用户ID', -- 外键
    constraint fk_userid foreign key (userid) references tb_user(id) -- 添加外键关联tb_user的主键
)comment '用户教育信息表';

insert into tb_user values (null,'tb','45','1','2432352525'),
                           (null,'gs',43,'2','324252552'),
                           (null,'gag',25,'1','34252365'),
                           (null,'gag',20,'2','245263763');

insert into tb_user_edu values (null,'本科','fs','fsfsgsg','fsfsfsf','fsgfsg',1),
                               (null,'硕士','fs','gsgs','fsfsgsgsfsf','fsgdgfsg',2),
                               (null,'博士','fs','fsfsgsg','fsfsfssff','fsgfsgsg',3),
                               (null,'本科','fs','fsfsgsg','fsfsfsfcd','fsgfsgbf',4);
```

## p38 多表查询-概述

多表查询概述

- 概述：指从多张表中查询数据
- 笛卡尔积：笛卡尔积是指在数学中，两个集合A集合和B集合的所有组合情况（**多表查询，要消除笛卡尔积**）

```sql
-- 多表查询 笛卡尔积
select * from emp,dept where emp.dept_id = dept.id;
```

- 多表查询分类

  - 连接查询

  1. 内连接：相当于**查A,B交集**部分数据

  2. 外连接

     （1）左外连接：查询**左表**所有数据，以及两种表交集部分数据

     （2）右外连接：查询**右表**左右数据，以及两种表交集部分数据

  3. 自连接：当前表与自身连接查询，自连接必需使用表别名

  - 子查询

  

## p39 多表查询-内连接

连接查询 - 内连接

**内连接查询的是两张表的交集部分**

内连接查询语法

- 隐式内连接

```sql
select 字段列表 from 表1，表2 where 条件...;
```

- 显示内连接

```sql
select 字段列表 from 表1[inner] join 表2 on 连接条件...;
```

演示：

```sql
-- 内连接
-- 1. 查询每个员工的姓名，及关联部门的名称(隐式内连接实现）
select emp.name, dept.name from emp ,dept where emp.dept_id = dept.id;

select e.name,d.name from emp e ,dept d where e.dept_id = d.id;

-- 2.查询每个员工的姓名，及关联部门的名称(显式内连接实现）
select emp.name,dept.name from emp inner join dept on emp.dept_id = dept.id;
```

## p40 多表查询-外连接

外连接

（1）左外连接：查询**左表**所有数据，以及两种表交集部分数据

```sql
select 字段列表 from 表1 left [outer] join 表2 on 条件...;
```

相当于查询表1（左表）的所有数据 包含表1和表2交集部分的数据

（2）右外连接：查询**右表**左右数据，以及两种表交集部分数据

```sql
select 字段列表 from 表1 right [outer] join 表2 on 条件...;
```

相当于查询表2（右表）的所有数据 包含表1和表2交集部分的数据

案例演示

```sql
-- 1. 查询emp表中的所有数据，和对应的部门信息，左外连接查询
select e.* ,d.name from emp e left outer join dept d on e.dept_id = d.id;

-- 2. 查询dept表中的所有数据，和对应的员工信息（右外连接）
select dept.* ,emp.* from emp right outer join dept on emp.dept_id = dept.id;

-- 3. 查询dept表中的所有数据，和对应的员工信息（左外连接）
select dept.*, emp.* from dept left outer join emp on dept.id = emp.dept_id;
```

## p41 -多表查询-自连接

自连接查询语法

```sql
select 字段列表 from 表A 别名1 join 表A 别名2 on 条件...;
```

**自连接查询，可以是内连接查询也可以是外连接查询**

![image-20220214173435647](https://s2.loli.net/2022/02/14/1RsVcG7HtAvPIdJ.png)

```sql
-- 自连接
-- 1.查询员工 及其所属领导的名字
select a.name,b.name from emp a,emp b where a.manager = b.id;

-- 2. 查询所有员工emp 及其领导名字emp,如果员工没有领导，也要查询出来(外连接，内连接只能查查出交集部分）
select a.name ,b.name from  emp a left outer join emp b on a.manager = b.id;
```

上述第三行代码结果：![image-20220214173537752](https://s2.loli.net/2022/02/14/AvCQzde9PkEtqZl.png)

第6行代码结果为：![image-20220214173609304](https://s2.loli.net/2022/02/14/54EL81sFnSfmIN3.png)

## p42 -多表查询-联合查询union

联合查询-`union`,`union all`

对于union查询，就是把多次查询的结果合并起来，形成一个新的查询结果集。

语法：

```sql
select 字段列表 from 表A ...
union [all]
select 字段列表 from 表B ...;
```

演示示例

```sql
select  * from emp where salary< 50000
union all
select * from emp where age > 56;
```

第一行结果

![image-20220214221433158](https://s2.loli.net/2022/02/14/TQlVyWbYcAnprwD.png)

第3行结果

![image-20220214221500676](https://s2.loli.net/2022/02/14/RwN1kl9Tqjy2K4u.png)

加了`union all`之后联结的结果

![image-20220214221549142](https://s2.loli.net/2022/02/14/LYbXQuv7yg2SZAP.png)

合并后去重去掉关键字all:

```sql
select  * from emp where salary< 50000
union 
select * from emp where age > 56;
```

结果为：

![image-20220214221730666](https://s2.loli.net/2022/02/14/miCRPnTrzdLaAvu.png)

注意：

- **对于联合查询的多张表的列数必须保持一致，字段类型也需要保持一致。**
- **union all 会将全部的数据直接合并在一起，union会对合并之后的数据去重。**

## p43 多表查询-子查询

- 概念：SQL语句中嵌套select语句，称为嵌套查询，又称子查询。

```sql
select * from t1 where column1 = (select column1 from t2);
```

子查询外部语句可以是`insert / update / delete /select` 的任何一个

- 根据子查询的结果不同，分为：

1. 标量子查询（子查询结果为单个值）
2. 列子查询（子查询结果为一列）
3. 行子查询（子查询结果为一行）
4. 表子查询（子查询结果为多行多列）

- 根据子查询位置，分为：`where`之后，`from`之后，`select`之后；

## P44 多表查询-标量子查询

子查询-标量子查询

子查询结果为单个值（数字、字符串、日期）

常用操作符`=、<>、>、>=、<、<=`；

实例演示

```sql
-- 标量子查询
-- ·1.查询研发部的所有员工信息
-- a.查询研发部部门ID
-- b.根据研发部部门id
select * from emp where dept_id = (select id from dept where name = '研发部');

-- 2.查询在庸 入职之后的员工信息
-- a.查询 庸 的入职日期
select entrydate from emp where name = '庸';

-- b.查询指定入职日期之后的入职员工信息
select * from emp where entrydate > (select entrydate from emp where name = '庸');
```

## p45 多表查询-列子查询

列子查询：子查询结果为一列；

常用的操作符：`in、not in 、any、some、all`

![image-20220214223840561](https://s2.loli.net/2022/02/14/ObchVaCFfrA3I7y.png)

```sql
-- 列子查询（查询结果为1列）
-- 1.查询 研发部和总经办的所有员工信息
-- a.查询 研发部和总经办的部门id
select id from dept where name in('研发部' , '总经办'); -- 1 -- 5

-- b.根据部门id查询员工信息
select  * from emp where dept_id in ( 1,5);

-- c. 整体
select  * from emp where dept_id in (select id from dept where name in('研发部' , '总经办'));

-- 2.查询比财务部所有人工资都高的员工信息
-- a.查询财务部所有人员工资
select salary from emp where dept_id = (select id from  dept where name = '财务部');

-- b.比财务部所有人员都高

select * from emp where salary >all (select salary from emp where dept_id = (select id from  dept where name = '财务部'));

-- 3.查询比研发部其中任意一人工资高的员工
select * from emp where salary > any (select salary from emp where dept_id = (select id from  dept where name = '研发部'));
```

## p46 多表查询-行子查询

行子查询（子查询结果为一行，可以是多列）

常用操作符为：`=、<>、in、not in `;

演示：

```sql
-- 行子查询
-- 1.查询和金f庸薪资及其直属领导相同的员工信息
-- a.查询金f庸的薪资及其直属领导
select salary,manager from emp where name = '金f庸'; -- 20000 2
-- b.查询和金f庸薪资及其直属领导相同的员工信息
select *from emp where salary = 20000 and manager = 2;
select * from emp where (salary,manager) = (20000,2);

-- c.整体
select * from emp where (salary,manager) = (select salary,manager from emp where name = '金f庸');
```

## p47 多表查询-表子查询

表子查询（子查询结果为多行多列）

常用操作符：`in`

演示：

```sql
-- 表子查询
-- 1.查询和’金f庸'，‘金庸’职位和薪资相同的员工信息
-- a.查询’金f庸'，‘金庸’职位和薪资
select job , salary from emp where name in ('金f庸','金庸');

-- b .查询相同的员工信息
select * from emp where (job,salary) in (select job , salary from emp where name in ('金f庸','金庸') );

-- 2.查询入职日期是 2009-01-01之后的员工信息，及其部门信息
-- a.查询入职日期是2009-01-01之后员工表
select  * from emp where entrydate > '2009-01-01';

-- b.查询这部分员工，对应的部门信息
select e.* ,d.* from (select  * from emp where entrydate > '2009-01-01') e left join dept d on e.dept_id = d.id;
```

## p48 多表查询-练习1

## p49多表查询-练习2

## p50多表查询-小结

1. 多表关系

> 一对多：在多的一方设置外键，关联一的一方的主键；
>
> 多对多：建立中间表，中间表包含两个外键，关联两张表的主键；
>
> 一对一：用于表结构拆分，在其中任何一方设置外键（unique)，关联另一方的主键；

2. 多表查询

> **内连接**：相当于**查A,B交集**部分数据
>
> - 隐式：`select ...from 表A，表B where 条件...`
> - 显示：`select ...from 表A inner join 表B on 条件... `
>
> **外连接**
>
> （1）左外连接：查询**左表**所有数据，以及两种表交集部分数据
>
> ```sql
> select ...from 表A left join 表B on 条件...
> ```
>
> （2）右外连接：查询**右表**左右数据，以及两种表交集部分数据
>
> ```sql
> select ...from 表A right join 表B on 条件...
> ```
>
> **自连接**：当前表与自身连接查询，自连接必需使用表别名
>
> ```sql
> select 字段列表 from 表A 别名1 join 表A 别名2 on 条件...;
> ```
>
> **子查询**:标量子查询、列子查询、行子查询、表子查询；

## p51事务-简介

事务简介、事务操作、事务四大特性、并发事务问题、事务隔离级别；

**事务简介**

**事务**：是一组操作的集合，它是一个不可分割的工作单位，事务回吧所有的操作作为一个整体一起向系统提交或撤销操作请求，即这些操作要么**同时成功**，要么**同时失败**；

![image-20220214233840564](https://s2.loli.net/2022/02/14/8QaKd12HyOzlbPF.png)

回滚事务：将之前减少的数据恢复回去

**默认的MySQL的事务是自动提交的，也就是说，当执行一条DML语句，MySQL会立即隐式的提交事务；**

## p52事务-操作演示

事务操作

方式1：

- 查看/设置事务提交方式

```sql
select @@autocommit; -- 查看事务提交方式，1 自动提交，0 手动提交
set @@autocommit = 0;
```

- 提交事务

```sql
commit
```

- 回滚事务

```sql
rollback
```

方式2：

- 开启事务



```sql
start transaction 或者 begin
```

- 提交事务

```sql
commit
```

- 回滚事务

```sql
rollback
```

```sql
create table account(
    id int auto_increment primary key comment '主键ID',
    name varchar(10) comment '姓名',
    money int comment '余额'
)comment '账户表';
insert into account values (null,'张三',2000),(null,'李四',2000);

-- 恢复数据
update account set money = 2000 where name = '张三' or name = '李四';


-- 方式1：手动提交设置为0
select @@autocommit;

set @@autocommit = 0; -- 设置为手动执行

-- 转账操作（张三给李四转账1000）
-- 1.查询张三账户余额
select * from account where name = '张三';

-- 2.将张三账户余额减少1000
update account set money = money - 1000 where name ='张三';

抛出异常...

-- 3.将李四账户的余额+1000
update account set money = money + 1000 where name ='李四';

-- 提交事务
commit ;

-- 回滚事务
rollback ;


-- 方式2
-- 转账操作（张三给李四转账1000）

-- 开启事务
start transaction ;

-- 1.查询张三账户余额
select * from account where name = '张三';

-- 2.将张三账户余额减少1000
update account set money = money - 1000 where name ='张三';

抛出异常...

-- 3.将李四账户的余额+1000
update account set money = money + 1000 where name ='李四';

-- 提交事务
commit ;

-- 回滚事务
rollback ;
```

## p53 事务-四大特性ACID

事务四大特性

![image-20220215000807130](https://s2.loli.net/2022/02/15/4wctBWdOxZpGMPn.png)

注意理解掌握

## P54 事务-并发事务问题

并发事务问题：A事务和B事务同时操作某个数据库或者某一张表时出现的问题。

![image-20220215001303560](https://s2.loli.net/2022/02/15/cdzRgI2U4KlCkhi.png)

- 脏读

![image-20220215001439215](https://s2.loli.net/2022/02/15/CX9IT6wLNfFSBEK.png)

B事务读取到A还没有提交的数据

- 不可重复读

![image-20220215001648300](https://s2.loli.net/2022/02/15/ESoHWBdpkFUNQRX.png)

事务A执行1操作之后，事务B提交update更新操作，然后事务A执行3操作，两次读到数据不一致

- 幻读

![image-20220215002010804](https://s2.loli.net/2022/02/15/rwLPapQxS1Bkvgt.png)

事务A执行1操作查询id为1的数据，发现没有；然后并发事务B插入id =1 的数据提交到数据库；然后事务A插入id= 1的数据，此时主键重复（冲突），不能插入；但是再次查询select时，发现还是没有数据。



## p55 事务-并发事务演示及隔离级别

事务隔离级别

![image-20220215002610739](https://s2.loli.net/2022/02/15/WtX6UYsi1dNrVnQ.png)

读未提交（`read uncommitted`)、读已提交(`read committed`)、重复读(`repeatable read`)、串行化(`serializable`)；

```sql
-- 查看事务隔离级别
select @@transaction_isolation;

-- 设置事务隔离级别
set [session | global] transaction isolation level {read uncommited | read commited |repeatable read|serializable}
```

- `read uncommited`隔离级别

  查询原始数据，并开启事务A；

```sql
-- 事务A
mysql> use ithm
Database changed
mysql> set session transaction isolation level read uncommitted;
Query OK, 0 rows affected (0.00 sec)

mysql> select * from account;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | 张三 |  2000 |
|  2 | 李四 |  2000 |
+----+------+-------+
2 rows in set (0.01 sec)

mysql> start transaction;
Query OK, 0 rows affected (0.00 sec)
```

开启事务B；

```sql
-- B事务
mysql> use ithm;
Database changed
mysql> start transaction;
Query OK, 0 rows affected (0.00 sec)
```

然后B执行update操作，A在查询：

```sql
-- B事务
mysql> update account set money = money - 1000 where name = '张三';
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0
```

```sql
-- A事务
mysql> select * from account;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | 张三 |  2000 |
|  2 | 李四 |  2000 |
+----+------+-------+
2 rows in set (0.00 sec)

-- 中间B执行update操作

mysql> select * from account;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | 张三 |  1000 |
|  2 | 李四 |  2000 |
+----+------+-------+
2 rows in set (0.00 sec)
```

以上发生了脏读：B事务执行了一个更新操作，还没有提交，然而事务A读取到了事务B还没有提交的数据。

此时B事务执行`commit`操作

```sql
-- B事务
commit ;
```

A事务再执行查询，数据没有发生变化。

```sql
-- A事务
mysql> select * from account;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | 张三 |  1000 |
|  2 | 李四 |  2000 |
+----+------+-------+
2 rows in set (0.01 sec)
```

- `read commited`解决脏读问题

  设置事务A的隔离级别为`read commited`

  ```sql
  -- 事务A
  mysql> set session transaction isolation level read committed;
  Query OK, 0 rows affected (0.00 sec)
  mysql> start transaction;
  Query OK, 0 rows affected (0.00 sec)
  mysql> select * from account;
  +----+------+-------+
  | id | name | money |
  +----+------+-------+
  |  1 | 张三 |  1000 |
  |  2 | 李四 |  2000 |
  +----+------+-------+
  2 rows in set (0.00 sec)
  ```

  事务B 开启事务，再次执行修改张三余额的指令

  ```sql
  -- 事务B
  mysql> start transaction;
  Query OK, 0 rows affected (0.00 sec)
  
  mysql> update account set money = money - 1000 where name = '张三';
  Query OK, 1 row affected (0.01 sec)
  Rows matched: 1  Changed: 1  Warnings: 0
  ```

  此时事务A再次查询，没有发生变化

  ```sql
  -- 事务A
  mysql> select * from account;
  +----+------+-------+
  | id | name | money |
  +----+------+-------+
  |  1 | 张三 |  1000 |
  |  2 | 李四 |  2000 |
  +----+------+-------+
  2 rows in set (0.00 sec)
  ```

  然后，将事务B提交

```sql
-- 事务B
mysql> commit;
Query OK, 0 rows affected (0.01 sec)
```

此时，再次事务A再次查询，现在张三余额才发生减少，因此`read commit `可以避免脏读问题发生

```sql
-- 事务A
mysql> select * from account;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | 张三 |     0 |
|  2 | 李四 |  2000 |
+----+------+-------+
2 rows in set (0.01 sec)
```

- `read commit `不可重复读问题

开启事务A

```sql
-- 事务A
mysql> start transaction;
Query OK, 0 rows affected (0.00 sec)
```

开启事务B

```sql
-- 事务B
mysql> start transaction;
Query OK, 0 rows affected (0.00 sec)
```

然后事务A查询余额

```sql
-- 事务A
mysql> select * from account;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | 张三 |     0 |
|  2 | 李四 |  2000 |
+----+------+-------+
2 rows in set (0.00 sec)
```

事务B ，对张三余额增加1000

```sql
-- 事务B
mysql> update account set money = money + 1000 where name = '张三';
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0
```

事务A再次查询余额，余额没有发生变化

```sql
-- 事务A
mysql> select * from account;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | 张三 |     0 |
|  2 | 李四 |  2000 |
+----+------+-------+
2 rows in set (0.00 sec)
```

事务B提交

```sql
-- 事务B
mysql> commit;
Query OK, 0 rows affected (0.00 sec)
```

事务A再次查询余额，可以查询到增加了1000；

```sql
-- 事务A
mysql> select * from account;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | 张三 |  1000 |
|  2 | 李四 |  2000 |
+----+------+-------+
2 rows in set (0.01 sec)
```

事务A中查询第一次和第二次数据一样，第二次和第三次数据不一样，同一个SQL在一个事务中查到的数据不一样，发生不可重复读问题；

- `repeatable read`

  事务A设置为`repeatable read` 并且开启事务

```sql
-- 事务A
mysql> set session transaction isolation level repeatable read;
Query OK, 0 rows affected (0.00 sec)

mysql> start transaction;
Query OK, 0 rows affected (0.00 sec)
```

开启事务B

```sql
-- 事务B
mysql> start transaction;
Query OK, 0 rows affected (0.00 sec)
```

事务A查询余额

```sql
-- 事务A
mysql> select * from account;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | 张三 |  2000 |
|  2 | 李四 |  2000 |
+----+------+-------+
2 rows in set (0.00 sec)
```

事务B执行更新操作,并且提交

```sql
-- 事务B
mysql> update account set money = money - 1000 where name = '张三';
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> commit;
Query OK, 0 rows affected (0.01 sec)
```

事务A，查询余额，结果一样没有发生变化（可重复读）；

```sql
-- 事务A
mysql> select * from account;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | 张三 |  2000 |
|  2 | 李四 |  2000 |
+----+------+-------+
2 rows in set (0.01 sec)
```

事务A提交之后，并且查询余额，发生变化；

```sql
-- 事务A
mysql> commit;
Query OK, 0 rows affected (0.00 sec)

mysql> select * from account;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | 张三 |  1000 |
|  2 | 李四 |  2000 |
+----+------+-------+
2 rows in set (0.00 sec)
```

`repeatable read`解决了不可重复读问题。

- `repeatable read`幻读问题

事务A开启

```sql
-- 事务A
mysql> start transaction;
Query OK, 0 rows affected (0.00 sec)
```

事务B开启

```sql
-- 事务B
mysql> start transaction;
Query OK, 0 rows affected (0.00 sec)
```

事务A查询数据（id为3）

```sql
-- 事务A
mysql> select * from account where id = 3;
Empty set (0.00 sec)

```

事务B插入id=3的数据，并且提交

```sql
-- 事务B
mysql> insert into account(id,name,money) values (3,'王五',2000);
Query OK, 1 row affected (0.01 sec)

mysql> commit;
Query OK, 0 rows affected (0.01 sec)
```

事务A再次插入id为3的数据，发生主键冲突；

```sql
-- 事务A
mysql>  insert into account(id,name,money) values (3,'大岛王五',2000);
ERROR 1062 (23000): Duplicate entry '3' for key 'account.PRIMARY'
```

事务A再次查询主键为3的数据，还是没有数据

```sql
-- 事务A
mysql> select * from account where id = 3;
Empty set (0.00 sec)
```

因此`repeatable read`会发生幻读的现象。

最后事务A提交

```sql
-- 事务A
mysql> commit;
Query OK, 0 rows affected (0.00 sec)
```

- `serializable`解决幻读问题

事务A，设置事务，并开启

```sql
-- 事务A
mysql> set session transaction isolation level serializable;
Query OK, 0 rows affected (0.00 sec)

mysql> start transaction;
Query OK, 0 rows affected (0.00 sec)

```

开启事务B

```sql
-- 事务B
mysql> start transaction;
Query OK, 0 rows affected (0.00 sec)
```

事务A查询数据

```sql
-- 事务A
mysql> select * from account;
+----+------+-------+
| id | name | money |
+----+------+-------+
|  1 | 张三 |  1000 |
|  2 | 李四 |  2000 |
|  3 | 王五 |  2000 |
+----+------+-------+
3 rows in set (0.00 sec)
```

事务A查询id为4的数据，发现没有

```sql
-- 事务A
mysql> select * from account where id = 4;
Empty set (0.00 sec)
```

事务B插入id为4的数据

```sql
-- 事务B
 mysql> insert into account(id,name,money) values (4,'王五儿',2000);
 此时光标一直闪，阻塞,因为事务A在操作，就要等待事务A操作完成之后才能操作
```

![image-20220215014933330](https://s2.loli.net/2022/02/15/KlxXRbwEO1TZ86g.png)

然后事务A插入id为4的数据，并且提交

```sql
-- 事务A
mysql> insert into account(id,name,money) values (4,'王五儿',2000);
Query OK, 1 row affected (0.01 sec)

mysql> commit;
Query OK, 0 rows affected (0.01 sec)
```

此时事务B中提示，主键冲突

```sql
-- 事务B
mysql> insert into account(id,name,money) values (4,'王五儿',2000);
ERROR 1062 (23000): Duplicate entry '4' for key 'account.PRIMARY'
```

最后事务B提交

```sql
mysql> commit;
Query OK, 0 rows affected (0.00 sec)
```

`因此serializable`解决幻读问题，每次只允许一个事务操作，只有当A事务完成之后事务B才能操作，但是性能最差。

注意：**事务隔离级别越高，数据越安全，但是性能越低。**

## p56 事务-小结

1. 事务简介

**事务**：是一组操作的集合，它是一个不可分割的工作单位，事务会把所有的操作作为一个整体一起向系统提交或撤销操作请求，即这些操作要么**同时成功**，要么**同时失败**；

2. 事务操作

```sql
start transaction; -- 开启事务
commit/ rollback; -- 提交/回滚事务
```

3. 事务四大特性

> 原子性，一致性，隔离性，持久性

4. 并发事务问题

> 脏读，不可重复读，幻读

5. 事务的隔离级别

> 读未提交（`read uncommitted`)、读已提交(`read committed`)、重复读(`repeatable read`)、串行化(`serializable`)；

## p57 基础篇总结

1. MySQL概述

2. SQL语句（DDL,DML,DQL,DCL),软件开发（DDL,DML,DQL)
3. 函数
4. 约束（主键约束、非空约束、默认约束、唯一约束，外键约束）
5. 多表查询（多表关系等）
6. 事务（事务概念、四大特性、并发事务问题、事务隔离级别）

