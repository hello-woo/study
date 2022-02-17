

# MySQL进阶学习

## p01进阶-课程介绍

存储引擎、索引、SQL优化、视图/存储过程/触发器、锁、InnoDB引擎、MySQL管理

## p02 存储引擎-MySQL体系结构

存储引擎-----》MySQL体系结构、存储引擎简介、存储引擎特点、存储引擎选择

MySQL体系结构：

![image-20220215022622726](https://s2.loli.net/2022/02/15/1TtDoOzulM3PZRB.png)

![image-20220215022722835](https://s2.loli.net/2022/02/15/KrBLX4COgnDTbPQ.png)


连接层:接收客户端的连接，连接处理、认证授权，校验用户名和密码，校验客户端所具有的权限。

引擎层：**索引在引擎层实现，不同的存储引擎，索引的结构不同**。InnoDB是MySQL5.5之后默认的引擎。

## p03 存储引擎-简介

存储引擎简介

存储引擎就是存储数据、建立索引、更新/查询数据等技术的实现方式。**存储引擎是基于表的，而不是基于库的**，所以存储引擎也可被称为表类型。

```sql
show create table account;

CREATE TABLE `account` (
  `id` int NOT NULL AUTO_INCREMENT COMMENT '主键ID',
  `name` varchar(10) DEFAULT NULL COMMENT '姓名',
  `money` int DEFAULT NULL COMMENT '余额',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='账户表'
```

1. 在创建表时，指定存储引擎

```sql
create table 表名(
	字段1 字段1类型[comment 注释],
    字段2 字段2类型[comment 注释],
    字段3 字段3类型[comment 注释],
	....
    最后一个不加分号
)engine = innodb[comment 表注释];
```

2. 查看当前数据库支持的存储引擎

```sql
show engines;
```

![image-20220215024634458](https://s2.loli.net/2022/02/15/zPEWjQxapuvOr91.png)

InnoDB:支持事务、行级锁、支持外键；

## p04 存储引擎-InnoDB介绍

- InnoDB

1. 介绍

InnoDB是一种兼顾可靠性和高性能的通用存储引擎，InnoDB是MySQL5.5之后默认的引擎。

2. 特点

（1）DML(数据操作语言，用来对数据库表中的==数据==进行增删改)操作遵循ACID模型，支持**事务**；

（2）**行级锁**，提高并发访问性能；

（3）支持**外键**`foreign key`约束，保证数据的完整性和正确性

3. 磁盘文件

xxx.ibd：xxx代表表名，innoDB引擎的每张表都会对应这样一个表空间文件，**存储该表的表结构（frm、sdi)、数据和索引**。

参数：innodb_file_per_table

4. 逻辑存储结构

![image-20220215030052564](https://s2.loli.net/2022/02/15/JXMUoIuSaT3biOG.png)

## p05 存储引擎-MyISAM和Memory

- MyISAM

1. 介绍

MyISAM是MySQL早期默认的存储引擎

2. 特点

（1）不支持事务，不支持外键

（2）支持表锁，不支持行锁

（3）访问速度快

3. 文件

```sql
tb_book.MYD -- 数据
tb_book.MYI -- 索引
tb_book_448.sdi  -- 表结构信息
```

- Memory

1. 介绍

Memory引擎的表数据时存储在内存中的，由于收到硬件问题、或者断电问题的影响，只能将这些表作为临时表或缓存使用。

2. 特点

（1）内存存放，访问速度较快

（2）hash索引（默认）

3. 文件

```sql
xxx.sdi -- 存储表结构信息
```

- 存储引擎特点

![image-20220215031212296](https://s2.loli.net/2022/02/15/2WCt3npQsrJSFvx.png)

## p06 存储引擎-选择

存储引擎选择

![image-20220215031430195](https://s2.loli.net/2022/02/15/HC15PoZcbRlghxn.png)

## p07 存储引擎-小结

1. 体系结构

> 连接层、服务层、引擎层、服务层

2. 存储引擎简介

```sql
show engines;

create table 表名(
	字段1 字段1类型[comment 注释],
    字段2 字段2类型[comment 注释],
    字段3 字段3类型[comment 注释],
	....
    最后一个不加分号
)engine = innodb[comment 表注释];
```

3. 存储引擎特点

InnoDB和MyISAM区别

（1）InnoDB支持事务，外键，MyISAM不支持

（2）InnoDB支持行级锁，MyISAM支持表锁

4. 存储引擎应用

> InnoDB：存储业务系统对于事物、数据完整性要求比较高的核心数据。
>
> MyISAM：存储业务系统的非核心事务。

## p08 MySQL安装(Linux版本)

略

```sql
mysql> set global validate_password.policy = 0;
Query OK, 0 rows affected (0.01 sec)

mysql> set global validate_password.length = 4;
Query OK, 0 rows affected (0.00 sec)

mysql> alter user 'root'@'localhost' identified by '1234';
Query OK, 0 rows affected (0.08 sec)

mysql> create user 'root'@'%' identified with mysql_native_password by '1234';
Query OK, 0 rows affected (0.01 sec)

mysql> grant all on *.* to 'root'@'%';
Query OK, 0 rows affected (0.02 sec)
```

注意开放3306端口

## p09 索引-概述

1. 介绍

**索引（index）**是帮助MySQL**高效获取数据**的**数据结构（有序）**。在数据之外。数据库系统还维护着满足特定查找算法的数据结构，这些数据结构以某种方式引用（指向）数据，这样就可以这些数据结构上实现高级查找算法，这种数据结构叫做索引。

2. 演示

![image-20220215154732496](https://s2.loli.net/2022/02/15/oPzJaQl47S6dxBF.png)

左边没有索引时，会从上到下逐个查找，右边查找时，只用查找3次。

3. 索引的优缺点

- 优点

（1）**提高数据检索的效率**，降低数据库的IO成本

（2）**通过索引列对数据进行排序**，降低数据排序的成本，降低CPU的消耗。

- 缺点

（1）索引列占用空间

（2）索引大大提高了查询效率，同时降低更新表的速度，如对标进行insert、update、delete时，效率降低。

## p10 索引-结构-介绍

索引结构

MySQL的索引是在存储引擎层实现的，不同的存储引擎有不同的结构，主要包含以下几种：

![image-20220215155356384](https://s2.loli.net/2022/02/15/skDi1IdYTQW2ec4.png)

![image-20220215155456004](https://s2.loli.net/2022/02/15/RzmTErd4XqSV8cK.png)

平常所说的索引，如果没有特别说明，都是指B+树结构组织的索引

## p11索引-结构-Btree

- 二叉树

![image-20220215155847535](https://s2.loli.net/2022/02/15/ZXIGwoqzgyT5RUm.png)

- B-Tree(多路平衡查找树)

以一颗最大度数（max-degree)为5(5阶) 的B-tree为例（每个节点最多存储4个key，5个指针）

树的度数：一个节点的子节点个数

![image-20220215160233146](https://s2.loli.net/2022/02/15/Tof3xB5gusI9Vpn.png)

数据结构动态演示网址：http://www.cs.usfca.edu/~galles/visualization/Algorithms.html

## p12索引-结构-B+树

- B+Tree

此时最大度数（max_degree)为4（4阶）的b+tree为例

![image-20220215161412502](https://s2.loli.net/2022/02/15/ufwkdGm1gYIQ3tV.png)

相对于B-Tree区别如下：

（1）所有的数据都会出现在叶子节点，并且叶子节点形成一个单向链表

（2）**非叶子节点的数据用来索引，叶子节点用来存放数据**

MySQL索引数据结构对经典的B+Tree进行了优化。在原来B+Tree的基础上，**增加一个指向相邻子节点的链表指针**，就形成了带有顺序的B+tree，提高区间访问的性能。

![image-20220215162208281](https://s2.loli.net/2022/02/15/DpO4jdVfHilexry.png)

## p13索引-结构 -hash

- hash

哈希索引就是采用一定的hash算法，将建值换算成新的hash值，映射到对应的槽位上面，然后存储在hash表中。

![image-20220215162616153](https://s2.loli.net/2022/02/15/oqFRUwde8VgnGWK.png)

如果两个（多个）键值，映射到同一个槽位上，产生hash冲突（hash碰撞），可以通过链表来解决。

- hash索引的特点

1. Hash索引**只能用于对等比较**（=，in)，**不支持范围查询**（between、>、<...）
2. **无法利用索引完成排序操作**。
3. **查询效率高**，通常只需要一次检索就可以，效率高于B+Tree索引

- 存储引擎支持

MySQL中，支持hash索引的是**Memory引擎**，而InnoDB中具有**自适应hash功能**，hash索引是存储引擎根据B+Tree索引在指定条件下自动构建的。

## p14索引-结构-思考题

为什么InnoDB存储引擎选择使用B+Tree索引结构？

（1）相对于二叉树、层级更少，搜索效率高。

（2）对于B树，无论叶子节点还是非叶子节点，都会保存数据，这样导致一页中存储的键值减少，指针也减少，要同样保存大量数据，只能增加树的高度，导致性能降低。

（3）相对于哈希索引，b+树支持范围查询以及排序操作。

## p15索引-分类

索引分类：

![image-20220215163903875](https://s2.loli.net/2022/02/15/Yts8mrRvQ1F2ENu.png)



在InnoDB存储引擎中，根据索引的存储形式，可以分为以下两种**聚集索引和二级索引**

![image-20220215164116487](https://s2.loli.net/2022/02/15/hPgOlaVRBY63rje.png)

二级索引也被称为辅助索引（非聚集索引）

聚集索引下面挂的是一行数据，而非聚集索引挂的是对应的主键

**聚集索引选取规则**：

（1）如果存在主键，主键索引就是聚集索引

（2）如果不存在主键，将使用第一个唯一（unique)索引作为聚集索引

（3）如果表没有主键，或没有合适的唯一索引，则InnoDB会自动生成一个rowid作为隐藏的聚集索引。

![image-20220215164711320](https://s2.loli.net/2022/02/15/uAsWn3LP2v7TONj.png)

聚集索引叶子节点存的的是一行的数据，二级索引叶子节点存的的对应的id；

执行以下SQL语句

```sql
select * from user where name = 'Arm';
```

执行过程，首先根据`name='Arm'`走二级索引，找到Arm对应的id，然后根据id值聚集索引找到对应的行数据。

从二级索引到聚集索引的过程称为**回表查询**。

![image-20220215165245691](https://s2.loli.net/2022/02/15/AwKmWkoxZYhJqNv.png)

## p16索引-思考题

1. 以下SQL语句，那个执行效率高？为什么

```sql
select * from user where id = 10;

select * from user where name = 'Arm';
其中id为主键，name字段创建对应的索引
```

根据id查询为聚集索引，一次扫描；根据name字段查，先二级索引，在回表查询聚集索引，因此第一条效率高。

2. InnoDB主键索引的B+Tree高度为多高？

一页为16k。

![image-20220215170521365](https://s2.loli.net/2022/02/15/QLlRS92TFZNhzxI.png)

## p17索引-语法

- 创建索引

```sql
create [unique|fulltext] index index_name on table_name(index_col_name,...);
```

- 查看索引

```sql
show index from table_name;
```

- 删除索引

```sql
drop index index_name on table_name;
```

案例需求

![image-20220215172158963](https://s2.loli.net/2022/02/15/EP5lpeBRYAyLfq1.png)

```sql
-- 创建数据库
create database itcast;
use itcast;

-- 创建表格
create table tb_user(
    id int auto_increment primary key comment 'id',
    name varchar(10) comment '姓名',
    email varchar(20) comment '邮箱',
    profession varchar(20) comment '专业',
    age int comment '年龄',
    gender char(1) comment '1为男，2为女',
    status int comment '状态',
    createtime date comment '创建时间'
)comment '学生表';

-- 添加字段
alter table tb_user add phone varchar(11) comment '手机号码';

-- 插入数据
insert into tb_user(id, name, email, profession, age, gender, status, createtime,phone) values
(null,'吕布','12131414@134.com','软件',19,'1',6,'2001-02-02','121314');

```

最开始索引`show index from tb_user` 为primary 主键索引

```sql
-- 1.为name创建索引
create index idx_user_name on tb_user(name);

-- 2.为phone创建唯一索引
create unique index idx_user_phone on tb_user(phone);

-- 3.为profession、age、status创建联合索引
create index idx_user_pro_age_sta on tb_user(profession,age,status);

-- 4.为email创建索引
create  index idx_user_email on tb_user(email);

-- 5.删除索引
drop index idx_user_email on tb_user;

show index on tb_user;
```

## p18索引-性能分析-查看执行频次

SQL性能分析

- SQL执行频率

以增/删/查/改为主？`show global status like ...`

```sql
show [session|global] status like ...

mysql> show global status like 'Com_______';
+---------------+-------+
| Variable_name | Value |
+---------------+-------+
| Com_binlog    | 0     |
| Com_commit    | 0     |
| Com_delete    | 0     |
| Com_import    | 0     |
| Com_insert    | 6     |
| Com_repair    | 0     |
| Com_revoke    | 0     |
| Com_select    | 663   |
| Com_signal    | 0     |
| Com_update    | 0     |
| Com_xa_end    | 0     |
+---------------+-------+
11 rows in set (0.00 sec)

mysql> select * from tb_user;
+----+--------+------------------+------------+------+--------+--------+------------+--------+
| id | name   | email            | profession | age  | gender | status | createtime | phone  |
+----+--------+------------------+------------+------+--------+--------+------------+--------+
|  1 | 吕布   | 12131414@134.com | 软件       |   19 | 1      |      6 | 2001-02-02 | 121314 |
+----+--------+------------------+------------+------+--------+--------+------------+--------+
1 row in set (0.00 sec)

mysql> show global status like 'Com_______';
+---------------+-------+
| Variable_name | Value |
+---------------+-------+
| Com_binlog    | 0     |
| Com_commit    | 0     |
| Com_delete    | 0     |
| Com_import    | 0     |
| Com_insert    | 6     |
| Com_repair    | 0     |
| Com_revoke    | 0     |
| Com_select    | 664   |
| Com_signal    | 0     |
| Com_update    | 0     |
| Com_xa_end    | 0     |
+---------------+-------+
11 rows in set (0.00 sec)
```

## p19索引-性能分析-慢查询日志

- 慢查询日志

**慢查询日志记录了所有执行时间操作指定参数**（`long_query_time`,单位：秒，默认10秒）的所有SQL语句的日志。

MySQL的慢查询日志默认没有开启，需要在MySQL的配置文件（`/etc/my.cnf`)中配置如下信息。

```sql
# 开启慢查询日志开关
slow_query_log = 1
# 设置慢查询日志时间为2秒，SQL语句执行时间超过2秒，就被视为慢查询，记录慢查询日志
long_query_time = 2;
```

配置完毕后，通过以下指令重新启动MySQL服务器进行测试，查看慢日志文件中记录的信息 `var/lib/mysql/xxx-slow.log`

```sql
mysql> show variables like 'slow_query_log';
+----------------+-------+
| Variable_name  | Value |
+----------------+-------+
| slow_query_log | OFF   |
+----------------+-------+
1 row in set (0.00 sec)

mysql> show variables like 'slow_query%';
+---------------------+----------------------------------------+
| Variable_name       | Value                                  |
+---------------------+----------------------------------------+
| slow_query_log      | OFF                                    |
| slow_query_log_file | /var/lib/mysql/VM-4-14-ubuntu-slow.log |
+---------------------+----------------------------------------+
2 rows in set (0.00 sec)

mysql> set global slow_query_log='ON'; 
Query OK, 0 rows affected (0.02 sec)

mysql> show variables like 'slow_query_log';
+----------------+-------+
| Variable_name  | Value |
+----------------+-------+
| slow_query_log | ON    |
+----------------+-------+
1 row in set (0.01 sec)
```

此时`/var/lib/mysql`/中会生成一个`VM-4-14-ubuntu-slow.log`的文件

里面内容为

```sql
/usr/sbin/mysqld, Version: 8.0.27-0ubuntu0.20.04.1 ((Ubuntu)). started with:
Tcp port: 3306  Unix socket: /var/run/mysqld/mysqld.sock
Time                 Id Command    Argument
/usr/sbin/mysqld, Version: 8.0.27-0ubuntu0.20.04.1 ((Ubuntu)). started with:
Tcp port: 3306  Unix socket: /var/run/mysqld/mysqld.sock
Time                 Id Command    Argument
```

如果为慢查询操作，后续会被记录在这张表里面

## p20索引-性能分析-show profiles

SQL性能分析

- profile详情

`show profiles`可以在SQL优化时了解时间消耗。通过`have_profiling`参数，能够看到当前MySQL是否支持profile操作。

```sql
select @@have_profiling;

mysql> select @@have_profiling;
+------------------+
| @@have_profiling |
+------------------+
| YES              |
+------------------+
1 row in set, 1 warning (0.00 sec)
```

默认是关闭的，通过set语句在seesion/global级别开启profiling.

```sql
set profiling = 1;


mysql> select @@have_profiling;
+------------------+
| @@have_profiling |
+------------------+
| YES              |
+------------------+
1 row in set, 1 warning (0.00 sec)

mysql> select @@profiling;
+-------------+
| @@profiling |
+-------------+
|           0 |
+-------------+
1 row in set, 1 warning (0.00 sec)

mysql> set profiling = 1;
Query OK, 0 rows affected, 1 warning (0.00 sec)

mysql> select @@profiling;
+-------------+
| @@profiling |
+-------------+
|           1 |
+-------------+
1 row in set, 1 warning (0.00 sec)
```

执行一系列业务SQL的操作，然后通过如下指令查看指令的执行耗时；

```sql
# 查看每一条SQL的耗时基本情况
show profiles;

# 查看指定query_id的SQL语句各阶段的耗时情况；
show profile for query query_id;

#查看指定query_id的SQL语句的CPU的使用情况;
show profile cpu for query query_id;
```

```sql
mysql> select @@profiling;
+-------------+
| @@profiling |
+-------------+
|           1 |
+-------------+
1 row in set, 1 warning (0.00 sec)

mysql> select * from tb_user;
+----+--------+------------------+------------+------+--------+--------+------------+--------+
| id | name   | email            | profession | age  | gender | status | createtime | phone  |
+----+--------+------------------+------------+------+--------+--------+------------+--------+
|  1 | 吕布   | 12131414@134.com | 软件       |   19 | 1      |      6 | 2001-02-02 | 121314 |
+----+--------+------------------+------------+------+--------+--------+------------+--------+
1 row in set (0.00 sec)

mysql> select * from tb_user where name = '吕布';
+----+--------+------------------+------------+------+--------+--------+------------+--------+
| id | name   | email            | profession | age  | gender | status | createtime | phone  |
+----+--------+------------------+------------+------+--------+--------+------------+--------+
|  1 | 吕布   | 12131414@134.com | 软件       |   19 | 1      |      6 | 2001-02-02 | 121314 |
+----+--------+------------------+------------+------+--------+--------+------------+--------+
1 row in set (0.00 sec)

mysql> show profiles;
+----------+------------+---------------------------------------------+
| Query_ID | Duration   | Query                                       |
+----------+------------+---------------------------------------------+
|        1 | 0.00015425 | select @@profiling                          |
|        2 | 0.00025175 | select * from tb_user                       |
|        3 | 0.00037775 | select * from tb_user where name = '吕布'   |
+----------+------------+---------------------------------------------+
3 rows in set, 1 warning (0.00 sec)


mysql> show profile for query 3;
+--------------------------------+----------+
| Status                         | Duration |
+--------------------------------+----------+
| starting                       | 0.000073 |
| Executing hook on transaction  | 0.000005 |
| starting                       | 0.000008 |
| checking permissions           | 0.000007 |
| Opening tables                 | 0.000040 |
| init                           | 0.000005 |
| System lock                    | 0.000008 |
| optimizing                     | 0.000011 |
| statistics                     | 0.000105 |
| preparing                      | 0.000017 |
| executing                      | 0.000038 |
| end                            | 0.000004 |
| query end                      | 0.000004 |
| waiting for handler commit     | 0.000008 |
| closing tables                 | 0.000009 |
| freeing items                  | 0.000016 |
| cleaning up                    | 0.000022 |
+--------------------------------+----------+
17 rows in set, 1 warning (0.00 sec)
```



## p21索引-性能分析-explain

- explain 执行计划

explain或者desc命令获取MySQL如何执行select语句，包括在select语句执行过程中表如何连接和连接的顺序。

语法：

```sql
#直接在select语句之前加上关键字explain/desc
explain select 字段列表 from 表名 where 条件
```

![image-20220215195128778](https://s2.loli.net/2022/02/15/wJTaD2Pkzeuql7L.png)

explain执行计划中各个字段的含义

1. `id`：select查询的序列号，表示查询中执行select子句或者是操作表的顺序（id相同，从上到下执行，id不同，值越大，越先执行）。

```sql
-- id值相同
select s.*,c.* from student s,course c,student_course sc where s.id = sc.studentID and c.id = sc.courseID;

explain select s.*,c.* from student s,course c,student_course sc where s.id = sc.studentID and c.id = sc.courseID;
```

![image-20220215200039340](https://s2.loli.net/2022/02/15/zYvi7wOPRJQM15q.png)

```sql
-- id值不同
-- 查询选修mysql课程的学生;(子查询)

select id from course where name = 'mysql';

select studentID from student_course where courseID =(select id from course where name = 'mysql');

select s.* from student s where s.id in (select studentID from student_course where courseID =(select id from course where name = 'mysql'));


-- explain
explain select s.* from student s where s.id in (select studentID from student_course where courseID =(select id from course where name = 'mysql'));
```

![image-20220215201242117](https://s2.loli.net/2022/02/15/23kH7xfCrqvaj4i.png)

执行顺序 `course --- > student_course----->subquery2 ---->student`;

2. `select type`

`select`类型，常见的取值有simple(简单表，即不使用表连接或者子查询)、`primary`（主查询，即外层的查询）、union（union中的第二个或者后面的查询语句）、subquery(select/where之后包含了子查询)等。

3. **`type`（重要）**

表示连接的类型，性能由好到差的连接类型为`null、system、const、eq_ref、range、index、all`\

根据主键或者唯一索引查询时为const；非唯一性索引是ref；

4. **`possible_key`**

显示可能应用在这张表上的索引，一个或多个。

5. **`key`：**实际使用的索引，如果为NULL，则没有使用索引
6. **`key_len`**：索引中使用的字节数，该值为索引字段的最大可能长度，并非实际使用长度，在不损失精确性的前提下，长度越短越好。
7. `rows`:`MySQL`认为必须执行查询的行数，在`innodb`引擎表中，是一个估计值，可能不准确。
8. `filtered`：返回结果的行数占需读取行数的百分比，`filtered`的值越大越好。

## p22索引-使用规则-验证索引效率

对比使用和不使用索引的耗时，说明创建索引耗时短。

## p23索引-使用规则-最左前缀法则

- 最左前缀法则

如果索引了多列（联合索引），要遵守最左前缀法则。最左前缀法则是指查询从索引的**最左列开始**（存在不一定放在第一个），并且**不跳过索引中的列**。如果跳跃某一列，**索引将部分失效（后面的字段索引失效）**

- 范围查询

联合索引中，出现范围查询（>,<)，**范围查询右侧的列索引失效**

```sql
explain select * from tb_user where profession = '软件' and age > 30 ans status = '0';

explain select * from tb_user where profession = '软件' and age >= 30 ans status = '0';

采用age>30 status 没有走索引，但是age>=30 走索引；
```

## p24索引-使用规则-索引失效情况

- 索引使用

1. **索引列运算：不要在索引列上进行运算操作，**索引将失效。

例如phone字段建立了索引。

```sql
explain select * from tb_user where phone = '12345678910';

explain select * from tb_user where substring(phone,10,2) = '10';
第三行type为null,全表扫描。
```

2. **字符串不加引号**

字符串类型字段使用时，不加引号，索引将失效。

```sql
explain select * from tb_user where phone = 12345678910;
实际使用的type为null,没有走索引
```

3. **模糊查询**：如果仅仅尾部模糊匹配，索引不会失效。如果时头部模糊匹配，索引失效。

```sql
explain select *from tb_user where profession = '软件%'; -- key 为idx_user_pro_age_sta

explain select *from tb_user where profession = '%工程'; -- key 为NULL;
```



## p25索引-使用规则-索引失效情况2

4. **or连接的条件**

用or分隔开的条件，如果or前的条件中的列由索引，而后面的列中没有索引，那么涉及的索引都不会被用到。

```sql
explain select * from tb_user where id = 10 or age = 23;

explain select * from tb_user where phone = '121212121' or age =23;
```

由于age 没有建立索引，所以即使id,phone由索引，索引也会失效。所以需要针对age也要建立索引。

5. **数据分布影响**

如果MySQL评估使用索引比全表更慢，则不使用索引。

表中满足条件多，走全表扫描，少走索引。

## p26索引-使用规则-SQL提示

- SQL提示

SQL提示，在SQL语句中加入一些人为的提示来达到优化操作的目的。

`use index`:

```sql
explain select *from tb_user use index (id_user_pro) where profession = '软件工程';
```

`ignore index`

```sql
explain select *from tb_user ignore index(id_user_pro) where profession = '软件工程';
```

`force index`

```sql
explain select *from tb_user force index(id_user_pro) where profession = '软件工程';
```



## p27索引-使用规则-覆盖索引&回表查询

- **覆盖索引**

尽量使用覆盖索引（查询使用了索引，并且需要返回的列，在该索引中已经全部能够找到）减少select *。

explain中`extra`字段

> `using index condition`：查找使用了索引，但是需要回表查询数据
>
> `using where;using index`:查找使用了索引，但是需要的数据都在索引列中能找到，所以不需要回表查询数据。

实例：

```sql
select * from tb_user where id =2 ;-- 主键索引（聚集索引
```

![image-20220215215137026](https://s2.loli.net/2022/02/15/TqUQJ28kYtWpRhs.png)

```sql
select id ,name from tb_user where name = 'Arm'; -- 辅助索引（二级索引）
```

![image-20220215215351434](https://s2.loli.net/2022/02/15/8LbjzINlkFKmV3C.png)

```sql
select id,name,gender from tb_user where name = 'Arm'; -- 二级索引---回表查询--->聚集索引
```

![image-20220215215610973](https://s2.loli.net/2022/02/15/j9eaFByZvQwlY4o.png)

思考题：

一张表，有四个字段（`id,username,password,status`)，由于数据量大，需要对以下SQL语句进行优化，该如何进行才是最优方案。

```sql
select id ,username,password from tb_user where username = 'itcast';
```

对于username和password建立联合索引，此时为二级索引，对应叶子节点数据为id，不需要回表查询，直接覆盖索引。



## p28索引-使用规则-前缀索引

- 前缀索引

当字段类型为字符串（varchar,text）时，有时需要索引很长的字符串，让索引变得很大，查询时，浪费大量磁盘IO，影响查询效率。此时可以只将字符串的一部分前缀，建立索引，大大节约索引空间，提高索引效率。

1. 语法

```sql
create index idx_xxxx on table_name(column(n)); -- 前n个字符
```

2. 前缀长度

可以根据索引的选择性来决定，选择性指不重复的索引值（基数）和数据表的记录总数的比值，索引选择性越高则查询效率越高，唯一索引的选择性是1，这是最好的索引选择性，性能也是最好的。

```sql
select count(distinct email) / count(*) from tb_user;
select count(distinct substring(email,1,5)) / count(*) from tb_user;
```

实现

```sql
create index idx_email_5 on tb_user(email(5));
```

![image-20220215222413434](https://s2.loli.net/2022/02/15/Cc9DzfoQZ3qRI4r.png)

## p29索引-使用规则-单列&联合索引

- 单列索引和联合索引

单列索引：一个索引只包含一个列

联合索引：一个索引包含多个列。

业务场景中，如果存在多个查询条件，考虑针对查询字段建立索引时，**建议建立联合索引，而非单列索引**。

以下idx_user_phone和idx_user_name都有单列索引，但是走的是phone的单列索引。

![image-20220215223118449](https://s2.loli.net/2022/02/15/YWCLAb5x1lvgFPr.png)

![image-20220215223240524](https://s2.loli.net/2022/02/15/YnproG3v6thmWyM.png)

## p30索引-设计原则

索引设计原则

![image-20220215223523221](https://s2.loli.net/2022/02/15/NVXZH3oEQhfwyI6.png)

## p31索引-小结

1. 索引概述

> 索引是高效获取数据的数据结构

2. 索引结构

> B+Tree :数据都在叶子节点（双向链表）
>
> Hash：Memory存储引擎，检索性能高，hash冲突，不能范围查询以及索引的排序

3. 索引分类

> **主键索引、唯一索引**、常规索引、全文索引
>
> 聚集索引、二级索引

4. 索引语法

```sql
-- 创建索引
create [unique|fulltext] index index_name on table_name(index_col_name,...);

-- 查询索引
show index from xxx;

-- 删除索引
drop index index_name on table_name;
```

5. SQL性能分析

> **执行频次、慢查询日志、profile、explain**

6. 索引使用

> **联合索引**：最左前缀原则(最左边的索引必须存在)
>
> **索引失效**：索引函数运算、字符串不加引号、like模糊匹配前面加%、or连接索引一个有一个没有、如果全表更快会直接走全表扫描，不走索引。
>
> **SQL提示**
>
> **覆盖索引**
>
> **前缀索引**
>
> **单列索引/联合索引**

7. 索引设计原则

> 表
>
> 字段
>
> 索引

## p32 SQL优化-插入数据

SQL优化：插入数据、主键优化、order by 优化、group by 优化、limit优化、count 优化、update优化。

插入数据优化

- insert优化

```sql
insert into tb_user values(1,'tom');
insert into tb_user values(2,'cat');
insert into tb_user values(3,'herry');
...
```

1. 批量插入

```sql
insert into tb_user values (1,'tom'),(2,'cat')...;
```

2. 手动提交事务

MySQL事务提交默认是自动提交的，insert 自动提交事务，频繁事务开启与提交

```sql
start transaction;
insert into tb_user values (1,'tom'),(2,'cat')...;
...
commit;
```

3. 主键顺序插入

```sql
-- 主键乱序插入
8 1 9 21 88 2 4 15 89 5 7 3
-- 主键顺序插入
1 2 3 4 5 6 7 8 9 15 21 88 89
```

- 大批量插入数据

insert插入性能较低，使用MySQL提供的load指令进行插入，操作如下：

![image-20220216095100524](https://s2.loli.net/2022/02/16/eDNPwum9rfpWECF.png)

```sql
# 客户端连接服务器时，加上参数 --local-infile
mysql --local-infile -u root -p

# 设置全局参数local-infile 为1，开启从本地加载文件导入数据的开关
set global local-infile = 1;

# 执行load指令将准备好的数据，加载到表结构中
load data local infile '/root/sql.log' into table 表名(tb_user） fields terminated by ',' lines terminated by '\n';
```

主键顺序插入性能高于乱序插入

## p33SQL优化-主键优化

主键优化

- 数据组织方式

在InnoDB存储引擎中，表数据都是根据**主键顺序组织存放**的，这种存储方式的表称为**索引组织表**(index organized table IOT)

主键索引是聚集索引，叶子节点存放的是行数据（存在page页中），一页16k，详细可看InnoDB介绍

- 页分裂

页可以为空，也可以填充一半，也可以填充100%。每个页包含2到N行数据（如果一行数据过大，会行溢出），根据主键排列

主键顺序插入

![image-20220216100809822](https://s2.loli.net/2022/02/16/hwl7CS1kt3YUcBm.png)

主键乱序插入

当插入主键为50数据，叶子节点是有序的，不能插入在最后面

![image-20220216100903345](https://s2.loli.net/2022/02/16/B9JmLoGAdnjtR8e.png)

应该插入在第一页里面，但是空间不够

![image-20220216101047069](https://s2.loli.net/2022/02/16/yMYKLiHSBQRpOfT.png)

需要开辟一个新的数据页，找到第一页50%的位置，将后两个数据移动到新的数据页，然后插入数据50，最后重新设置链表指针。

![image-20220216101340913](https://s2.loli.net/2022/02/16/Tt7nQsazgxBkpVU.png)

主键乱序插入的情况下，会发生页分裂。

- 页合并

![image-20220216102024450](https://s2.loli.net/2022/02/16/rGBQb5dpilm3Y6T.png)

将第三页合并到第二页中

![image-20220216102119987](https://s2.loli.net/2022/02/16/vHKSUuB2pDMmAto.png)

然后插入数据20到3号页

![image-20220216102649581](https://s2.loli.net/2022/02/16/yLNCGMjxVXP782U.png)

`merge_threshold`：合并页的阈值，可以自己设置，在创建表或者创建索引时指定。

- **主键设计原则**

1. 满足业务需求的情况下，尽量降低主键的长度。

因为二级索引中叶子节点挂的数据的主键，增大磁盘空间，搜索耗费大量的磁盘IO

2. 插入数据时，尽量选择**顺序插入**，选择使用`auto_increment`自增主键

3. 尽量不要使用uuid做主键或者是其他自然主键，如身份证号

因为是无序的，乱序插入，可能存在页分裂情况，身份证号也比较占用磁盘空间，耗费大量磁盘IO

4. 业务操作时，避免对主键修改

## p34 SQL优化-order by优化

order by优化

1. `using filesort`:通过表的索引或全表扫描，读取满足条件的数据行，然后在排序缓冲区sort buffer中完成排序操作，所有不是通过索引直接返回排序结果的排序都叫filesort排序。
2. `using index`：通过有序索引顺序扫描直接返回有序数据，这种情况即为using index,不需要额外排序，操作效率高。

尽量优化为using index。

```sql
mysql> show index from tb_user;
+---------+------------+---------------+--------------+-------------+-----------+-------------+----------+--------+------+------------+---------+---------------+---------+------------+
| Table   | Non_unique | Key_name      | Seq_in_index | Column_name | Collation | Cardinality | Sub_part | Packed | Null | Index_type | Comment | Index_comment | Visible | Expression |
+---------+------------+---------------+--------------+-------------+-----------+-------------+----------+--------+------+------------+---------+---------------+---------+------------+
| tb_user |          0 | PRIMARY       |            1 | id          | A         |           1 |     NULL |   NULL |      | BTREE      |         |               | YES     | NULL       |
| tb_user |          1 | idx_user_name |            1 | name        | A         |           1 |     NULL |   NULL | YES  | BTREE      |         |               | YES     | NULL       |
+---------+------------+---------------+--------------+-------------+-----------+-------------+----------+--------+------+------------+---------+---------------+---------+------------+
2 rows in set (0.00 sec)

mysql> explain select id,age,phone from tb_user order by age;
+----+-------------+---------+------------+------+---------------+------+---------+------+------+----------+----------------+
| id | select_type | table   | partitions | type | possible_keys | key  | key_len | ref  | rows | filtered | Extra          |
+----+-------------+---------+------------+------+---------------+------+---------+------+------+----------+----------------+
|  1 | SIMPLE      | tb_user | NULL       | ALL  | NULL          | NULL | NULL    | NULL |    1 |   100.00 | Using filesort |
+----+-------------+---------+------------+------+---------------+------+---------+------+------+----------+----------------+
1 row in set, 1 warning (0.01 sec)
```

此时age没有建立索引，Extra中显示使用`using filesort`

```sql
-- 创建age、phone的联合索引
mysql> create index idx_user_age_phone on tb_user(age,phone);
Query OK, 0 rows affected (0.06 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> show index from tb_user;
+---------+------------+--------------------+--------------+-------------+-----------+-------------+----------+--------+------+------------+---------+---------------+---------+------------+
| Table   | Non_unique | Key_name           | Seq_in_index | Column_name | Collation | Cardinality | Sub_part | Packed | Null | Index_type | Comment | Index_comment | Visible | Expression |
+---------+------------+--------------------+--------------+-------------+-----------+-------------+----------+--------+------+------------+---------+---------------+---------+------------+
| tb_user |          0 | PRIMARY            |            1 | id          | A         |           1 |     NULL |   NULL |      | BTREE      |         |               | YES     | NULL       |
| tb_user |          1 | idx_user_name      |            1 | name        | A         |           1 |     NULL |   NULL | YES  | BTREE      |         |               | YES     | NULL       |
| tb_user |          1 | idx_user_age_phone |            1 | age         | A         |           1 |     NULL |   NULL | YES  | BTREE      |         |               | YES     | NULL       |
| tb_user |          1 | idx_user_age_phone |            2 | phone       | A         |           1 |     NULL |   NULL | YES  | BTREE      |         |               | YES     | NULL       |
+---------+------------+--------------------+--------------+-------------+-----------+-------------+----------+--------+------+------------+---------+---------------+---------+------------+
4 rows in set (0.01 sec)

mysql> explain select id,age,phone from tb_user order by age;
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-------------+
| id | select_type | table   | partitions | type  | possible_keys | key                | key_len | ref  | rows | filtered | Extra       |
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-------------+
|  1 | SIMPLE      | tb_user | NULL       | index | NULL          | idx_user_age_phone | 52      | NULL |    1 |   100.00 | Using index |
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-------------+
1 row in set, 1 warning (0.00 sec)

mysql> explain select id,age,phone from tb_user order by age,phone;
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-------------+
| id | select_type | table   | partitions | type  | possible_keys | key                | key_len | ref  | rows | filtered | Extra       |
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-------------+
|  1 | SIMPLE      | tb_user | NULL       | index | NULL          | idx_user_age_phone | 52      | NULL |    1 |   100.00 | Using index |
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-------------+
1 row in set, 1 warning (0.00 sec)
-- 以上using index，说明走了索引

mysql> explain select id,age,phone from tb_user order by age,phone;
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-------------+
| id | select_type | table   | partitions | type  | possible_keys | key                | key_len | ref  | rows | filtered | Extra       |
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-------------+
|  1 | SIMPLE      | tb_user | NULL       | index | NULL          | idx_user_age_phone | 52      | NULL |    1 |   100.00 | Using index |
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-------------+
1 row in set, 1 warning (0.00 sec)

mysql> explain select id,age,phone from tb_user order by age desc ,phone desc;
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+----------------------------------+
| id | select_type | table   | partitions | type  | possible_keys | key                | key_len | ref  | rows | filtered | Extra                            |
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+----------------------------------+
|  1 | SIMPLE      | tb_user | NULL       | index | NULL          | idx_user_age_phone | 52      | NULL |    1 |   100.00 | Backward index scan; Using index |
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+----------------------------------+
1 row in set, 1 warning (0.01 sec)
-- 反向索引，（倒叙查询）,走了索引

mysql> explain select id,age,phone from tb_user order by phone,age;
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-----------------------------+
| id | select_type | table   | partitions | type  | possible_keys | key                | key_len | ref  | rows | filtered | Extra                       |
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-----------------------------+
|  1 | SIMPLE      | tb_user | NULL       | index | NULL          | idx_user_age_phone | 52      | NULL |    1 |   100.00 | Using index; Using filesort |
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-----------------------------+
1 row in set, 1 warning (0.00 sec)
-- 因为创建联合索引时age在前，phone在后，此时phone在前，违背最左前缀原则，出现了using filesort

mysql> explain select id,age,phone from tb_user order by age asc,phone desc;
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-----------------------------+
| id | select_type | table   | partitions | type  | possible_keys | key                | key_len | ref  | rows | filtered | Extra                       |
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-----------------------------+
|  1 | SIMPLE      | tb_user | NULL       | index | NULL          | idx_user_age_phone | 52      | NULL |    1 |   100.00 | Using index; Using filesort |
+----+-------------+---------+------------+-------+---------------+--------------------+---------+------+------+----------+-----------------------------+
1 row in set, 1 warning (0.00 sec)
-- age升序，phone 降序，此时出现using filesort,创建索引时，默认是升序的

-- show index中Collation为A为升序，D为降序

-- 创建phone 降序的索引
mysql> create index idx_user_age_phone_ad on tb_user(age asc,phone desc);
Query OK, 0 rows affected (0.06 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> show index from tb_user;
+---------+------------+-----------------------+--------------+-------------+-----------+-------------+----------+--------+------+------------+---------+---------------+---------+------------+
| Table   | Non_unique | Key_name              | Seq_in_index | Column_name | Collation | Cardinality | Sub_part | Packed | Null | Index_type | Comment | Index_comment | Visible | Expression |
+---------+------------+-----------------------+--------------+-------------+-----------+-------------+----------+--------+------+------------+---------+---------------+---------+------------+
| tb_user |          0 | PRIMARY               |            1 | id          | A         |           1 |     NULL |   NULL |      | BTREE      |         |               | YES     | NULL       |
| tb_user |          1 | idx_user_name         |            1 | name        | A         |           1 |     NULL |   NULL | YES  | BTREE      |         |               | YES     | NULL       |
| tb_user |          1 | idx_user_age_phone    |            1 | age         | A         |           1 |     NULL |   NULL | YES  | BTREE      |         |               | YES     | NULL       |
| tb_user |          1 | idx_user_age_phone    |            2 | phone       | A         |           1 |     NULL |   NULL | YES  | BTREE      |         |               | YES     | NULL       |
| tb_user |          1 | idx_user_age_phone_ad |            1 | age         | A         |           1 |     NULL |   NULL | YES  | BTREE      |         |               | YES     | NULL       |
| tb_user |          1 | idx_user_age_phone_ad |            2 | phone       | D         |           1 |     NULL |   NULL | YES  | BTREE      |         |               | YES     | NULL       |
+---------+------------+-----------------------+--------------+-------------+-----------+-------------+----------+--------+------+------------+---------+---------------+---------+------------+
6 rows in set (0.00 sec)

mysql> explain select id,age,phone from tb_user order by age asc,phone desc;
+----+-------------+---------+------------+-------+---------------+-----------------------+---------+------+------+----------+-------------+
| id | select_type | table   | partitions | type  | possible_keys | key                   | key_len | ref  | rows | filtered | Extra       |
+----+-------------+---------+------------+-------+---------------+-----------------------+---------+------+------+----------+-------------+
|  1 | SIMPLE      | tb_user | NULL       | index | NULL          | idx_user_age_phone_ad | 52      | NULL |    1 |   100.00 | Using index |
+----+-------------+---------+------------+-------+---------------+-----------------------+---------+------+------+----------+-------------+
1 row in set, 1 warning (0.00 sec)
-- 此时没有using filesort
```

此时索引结构如下

![image-20220216111619552](https://s2.loli.net/2022/02/16/3hq6mXdRKwjxfg4.png)

因为使用了此时使用了覆盖索引，前面查询的是id，age和phone，直接是二级索引，不用回表查询，因此是using index

如果是`explain select *  from tb_user order by age asc,phone desc`,这里会回表查询，仍然是using filesort

```sql
mysql> explain select *  from tb_user order by age asc,phone desc;
+----+-------------+---------+------------+------+---------------+------+---------+------+------+----------+----------------+
| id | select_type | table   | partitions | type | possible_keys | key  | key_len | ref  | rows | filtered | Extra          |
+----+-------------+---------+------------+------+---------------+------+---------+------+------+----------+----------------+
|  1 | SIMPLE      | tb_user | NULL       | ALL  | NULL          | NULL | NULL    | NULL |    1 |   100.00 | Using filesort |
+----+-------------+---------+------------+------+---------------+------+---------+------+------+----------+----------------+
1 row in set, 1 warning (0.00 sec)

mysql> show variables like 'sort_buffer_size';
+------------------+--------+
| Variable_name    | Value  |
+------------------+--------+
| sort_buffer_size | 262144 |
+------------------+--------+
1 row in set (0.01 sec)
-- 排序缓冲区默认大小为256K，如果排序缓冲区满了，会在磁盘文件中进行排序，性能比较低，可以增大
```

order by优化原则：

![image-20220216112348120](https://s2.loli.net/2022/02/16/94Xa6jGFi7qUWh8.png)

## p35 SQL优化-group by优化

group by优化

- 在分组操作时，通过索引提高效率
- 分组操作时，索引使用要满足最左前缀法则。

```sql
#删除掉目前的联合索引idx_user_pro_age_sta
drop index id_user_pro_age_sta on tb_user;

#执行分组操作，根据profession字段分组
explain select profession,count(*) from tb_user group by profession;

#创建索引
create index idx_user_pro_age_sta on tb_user(profession,age,status);

#执行分组操作，根据profession字段分组
explain select profession,count(*) from tb_user group by profession;

#执行分组操作，根据profession字段分组
explain select profession,count(*) from tb_user group by profession,age;
```

演示·

```sql
-- 先删除所有的索引
mysql> explain select profession,count(*)  from tb_user group by profession;
+----+-------------+---------+------------+------+---------------+------+---------+------+------+----------+-----------------+
| id | select_type | table   | partitions | type | possible_keys | key  | key_len | ref  | rows | filtered | Extra           |
+----+-------------+---------+------------+------+---------------+------+---------+------+------+----------+-----------------+
|  1 | SIMPLE      | tb_user | NULL       | ALL  | NULL          | NULL | NULL    | NULL |    1 |   100.00 | Using temporary |
+----+-------------+---------+------------+------+---------------+------+---------+------+------+----------+-----------------+
1 row in set, 1 warning (0.00 sec)
-- using temporary 临时效率不高

-- 创建索引
mysql> create index idx_user_pro_age_sta on tb_user(profession,age,status);
Query OK, 0 rows affected (0.06 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> explain select profession,count(*)  from tb_user group by profession;
+----+-------------+---------+------------+-------+----------------------+----------------------+---------+------+------+----------+-------------+
| id | select_type | table   | partitions | type  | possible_keys        | key                  | key_len | ref  | rows | filtered | Extra       |
+----+-------------+---------+------------+-------+----------------------+----------------------+---------+------+------+----------+-------------+
|  1 | SIMPLE      | tb_user | NULL       | index | idx_user_pro_age_sta | idx_user_pro_age_sta | 93      | NULL |    1 |   100.00 | Using index |
+----+-------------+---------+------------+-------+----------------------+----------------------+---------+------+------+----------+-------------+
1 row in set, 1 warning (0.00 sec)

mysql> explain select age,count(*)  from tb_user group by age;
+----+-------------+---------+------------+-------+----------------------+----------------------+---------+------+------+----------+------------------------------+
| id | select_type | table   | partitions | type  | possible_keys        | key                  | key_len | ref  | rows | filtered | Extra                        |
+----+-------------+---------+------------+-------+----------------------+----------------------+---------+------+------+----------+------------------------------+
|  1 | SIMPLE      | tb_user | NULL       | index | idx_user_pro_age_sta | idx_user_pro_age_sta | 93      | NULL |    1 |   100.00 | Using index; Using temporary |
+----+-------------+---------+------------+-------+----------------------+----------------------+---------+------+------+----------+------------------------------+
1 row in set, 1 warning (0.00 sec)
-- 以上根据age排序不满足最左前缀法则，出现了临时表

mysql> explain select profession,age,count(*)  from tb_user group by profession,age;
+----+-------------+---------+------------+-------+----------------------+----------------------+---------+------+------+----------+-------------+
| id | select_type | table   | partitions | type  | possible_keys        | key                  | key_len | ref  | rows | filtered | Extra       |
+----+-------------+---------+------------+-------+----------------------+----------------------+---------+------+------+----------+-------------+
|  1 | SIMPLE      | tb_user | NULL       | index | idx_user_pro_age_sta | idx_user_pro_age_sta | 93      | NULL |    1 |   100.00 | Using index |
+----+-------------+---------+------------+-------+----------------------+----------------------+---------+------+------+----------+-------------+
1 row in set, 1 warning (0.00 sec)
-- 以上满足最左前缀法则，走索引

mysql> explain select age,count(*)  from tb_user where profession='软件' group by age;
+----+-------------+---------+------------+------+----------------------+----------------------+---------+-------+------+----------+-------------+
| id | select_type | table   | partitions | type | possible_keys        | key                  | key_len | ref   | rows | filtered | Extra       |
+----+-------------+---------+------------+------+----------------------+----------------------+---------+-------+------+----------+-------------+
|  1 | SIMPLE      | tb_user | NULL       | ref  | idx_user_pro_age_sta | idx_user_pro_age_sta | 83      | const |    1 |   100.00 | Using index |
+----+-------------+---------+------------+------+----------------------+----------------------+---------+-------+------+----------+-------------+
1 row in set, 1 warning (0.00 sec)
-- 以上满足最左前缀法则
```

## p36 SQL优化-limit优化

`limit 2000000,10`查询代价较高

优化思路：**创建覆盖索引或者子查询**

```sql
explain select * from tb_user t,(select id from tb_user order by id limit 2000000,10) a where t.id = a.id;
```

其中

```sql
mysql> select * from tb_user t where t.id in (select id from tb_user order by id limit 2000000,10);
ERROR 1235 (42000): This version of MySQL doesn't yet support 'LIMIT & IN/ALL/ANY/SOME subquery'

-- MySQL不支持在in之后用到limit
```

## p37 SQL优化-count 优化

count 优化

- MyISAM引擎把一个表的总行数存在磁盘上，因此执行count(*)直接返回这个数，效率很高。
- InnoDB中需要一行一行将数据从引擎中读取出来，然后累积计数。

优化思路：自己计数。比如借助key,value形的数据库（redis),插入加一

count的几种用法

- 聚合函数count()，对于返回的结果集，一行行判断，如果count()参数不为null,累计值加1，否则不加，最后返回累计值
- 用法：`count(*)、count(主键)、count(字段)、count(1)`。
- count(主键):InnoDB遍历整张表，把每一行的主键id值都取出来，返回给服务层。服务层拿到主键，直接按行进行累加（主键不可能为null。
- count(字段值)：

> （1）没有not null约束：InnoDB遍历整张表，把每一行的字段都取出来，返回给服务层，服务层判断是否为null，不为null,计数累加
>
> （2）有not null约束：InnoDB遍历整张表，把每一行的字段都取出来，返回给服务层，直接累加

- count(1)：InnoDB遍历整张表但不取值。服务层对于返回的每一行，放一个数字1进去，直接按行累加。
- count(*)：InnoDB优化，不取值，服务层直接按行累加。

**效率排序：`count(字段)<count(主键)<count(1)≈count(*)`，尽量使用count(*)。**

## p38 SQL优化-update优化

update优化

```sql
-- 事务A
mysql> select * from course;
+----+--------+
| id | name   |
+----+--------+
|  1 | java   |
|  2 | php    |
|  3 | mysql  |
|  4 | hadoop |
+----+--------+
4 rows in set (0.00 sec)

-- 开启事务
mysql> begin;
Query OK, 0 rows affected (0.00 sec)

-- 更新id 为1的数据
mysql> update course set name= 'javaEE' where id = 1;
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

-- 事务B执行更新操作之后commit
mysql> commit;
Query OK, 0 rows affected (0.01 sec)
```

```sql
-- 事务B
-- 此时可以更新id为3数据
mysql> update course set name = 'MySQL' where id = 3;
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

-- 事务A提交后事务B提交
mysql> commit;
Query OK, 0 rows affected (0.01 sec)
```

演示

```sql
-- 事务A
-- 1.首先查询数据
mysql> select * from course;
+----+--------+
| id | name   |
+----+--------+
|  1 | javaEE |
|  2 | php    |
|  3 | MySQL  |
|  4 | hadoop |
+----+--------+
4 rows in set (0.00 sec)

-- 2.开启事务
mysql> begin;
Query OK, 0 rows affected (0.00 sec)

-- 3.更新数据
mysql> update course set name= 'SpringBoot' where name = 'php';
Query OK, 1 row affected (0.00 sec)
Rows matched: 1  Changed: 1  Warnings: 0
```

```sql
-- 事务B
-- 4.事务B开启
mysql> begin;
Query OK, 0 rows affected (0.00 sec)

-- 5.事务B更新数据
mysql> update course set name = 'hadp' where id = 4;
-
-- 此时事务B会阻塞，无法更新，因为事务A跟新数据，name字段没有索引，此时不是加的行锁，而是表锁,要等事务Acommit之后，事务B的更新操作才会进行。
-- 更新的时候一定要根据索引字段更新，此时为name字段创建索引，然后重复以上，事务B可以执行
```

注意：**InnoDB行锁是针对索引加的锁，不是针对记录加的锁，并且该索引不能失效，否则会从行锁升级为表锁，降低数据库的并发访问性能。**



## p39 SQL优化-小结

1. 插入数据

> insert :批量操作、手动控制事务、主键顺序插入
>
> 大批量插入：`load data local infile`

2. 主键插入

> 乱序插入（页分裂）；主键长度尽量短、顺序插入、推荐auto_increment(不推荐uuid,因为无序而且长)

3. order by优化

> `using filesort`:通过表的索引或全表扫描，读取满足条件的数据行，然后在排序缓冲区sort buffer中完成排序操作，所有不是通过索引直接返回排序结果的排序都叫filesort排序。
>
> `using index`：通过有序索引顺序扫描直接返回有序数据，这种情况即为using index,不需要额外排序，操作效率高。

4. group by 优化

> 索引，多字段分组满足最左前缀法则

5. limit 优化

> limit 2000000，10-----》覆盖索引+子查询

6. count 优化

> **效率排序：`count(字段)<count(主键)<count(1)≈count(*)`，尽量使用count(*)。**

7. update优化

> 尽量根据主键/索引字段进行数据更新。

基本上对于索引进行优化

## p40 视图-介绍及基本语法

存储对象：视图/存储过程/触发器

视图

- 介绍

视图（view)是一种虚拟存在的表。视图中的数据并不在数据库中实际存在，行和列数据来自定义视图的查询中使用的表，并且是在使用视图时动态生成的。

视图只保存查询SQL的逻辑，不保存查询结果。所以创建视图时，主要工作落在创建SQL查询语句上

- 创建

```sql
create [or replace] view 视图名称(列名列表) as select语句 [with[cascaded|local]check option]
```

- 查询

```sql
-- 查看创建视图语句
show create view 视图名称;
-- 查看视图数据
select * from 视图名称;
```

- 修改

```sql
-- 1
create [or replace] view 视图名称[(列表列名)] as select语句[with[cascaded|local]check option]

-- 2
alter view 视图名称[(列表列名)] as select语句[with[cascaded|local]check option]
```

- 删除

```sql
drop view [if exists] 视图名称
```



## p41 视图-检查选项cascaded

- 视图检查选项：cascaded(级联)

![image-20220216152737409](https://s2.loli.net/2022/02/16/f38sw9h2IFBYy5u.png)

```sql
-- 创建视图
create or replace view stu_v_1 as select id,name from  student where id <=20 ;

select * from stu_v_1;

insert into stu_v_1 values (6,'tom');

-- 可以插入
insert into stu_v_1 values (25,'tim');
-- 显示有25的数据，但是在视图中没有，因为限定条件
select  id,name from  student;

create or replace view stu_v_2 as select id,name from  ithm.stu_v_1 where id >=10 with cascaded check option ;

-- 不能插入成功，因为加入cascaded选项，会检查后面的条件
insert into stu_v_2 values (7,'tom');

-- 不能插入成功，因为不仅检查 id>=10 ，还要检查依赖的视图（stu_v_1)id<=20,26不满足，因此失败
insert into stu_v_2 values  (26,'tom');

-- 可以插入成功 10<=15<=20
insert into stu_v_2 values (15,'gos');

create or replace view stu_v_3 as select id,name from  ithm.stu_v_2 where id <= 15 ;

-- 插入成功
insert into stu_v_3 values (11,'tom');

-- 插入成功，创建v3时没有加入检查选项，不会检查视图，会检查v2视图，再检查v1视图。
insert into stu_v_3 values  (17,'tom');

-- 不可以插入成功，依赖的v1条件不成立
insert into stu_v_3 values (28,'gos');
```

## p42 视图-检查选项local

local选项，会检查对应依赖视图有无检查选项，如果有，需要满足，如果没有，不需要满足。

```sql
-- local
-- 创建视图
create or replace view stu_v_4 as select id,name from  student where id <=15 ;

select * from stu_v_1;

-- 可以插入
insert into stu_v_4 values (6,'tom');

-- 可以插入，没有加with check option选项，不对条件进行检查
insert into stu_v_4 values (25,'tim');

create or replace view stu_v_5 as select id,name from  ithm.stu_v_4 where id >=10 with local check option ;

-- 插入成功，
insert into stu_v_5 values (13,'tom');

-- 插入成功，需要检查依赖的视图v4，但是v4没有检查选项，所以不用检查v4选项
insert into stu_v_5 values  (17,'tom');

create or replace view stu_v_6 as select id,name from  ithm.stu_v_5 where id < 20 ;

-- 插入成功
insert into stu_v_6 values (14,'tom');

-- 插入成功，创建v6时没有加入检查选项，不会检查视图，会检查v5视图，有选项且满足，再检查v1视图，无检查选项。
insert into stu_v_6 values  (17,'tom');

-- 插入失败，创建v6时没有加入检查选项，不会检查视图，会检查v5视图，有选项不满足，再检查v1视图，无检查选项。
insert into stu_v_6 values (9,'gos');
```

## p43 视图-更新及作用

视图的更新：视图中的行与基表中的行要一一对应才能更新。

![image-20220216154423991](https://s2.loli.net/2022/02/16/BP1jZkpNdnGlO7Y.png)

视图的作用

![image-20220216154746094](https://s2.loli.net/2022/02/16/hYNFqiE1P3rueRv.png)

安全：可以让视图只显示某些数据，

数据独立：可以在视图上对字段取别名，不改变基表

## p44 视图-案例

![image-20220216155049550](https://s2.loli.net/2022/02/16/ql8oJ7wcujAERtM.png)

```sql
-- 只能看到用户基本字段，屏蔽手机号和年龄
create or replace view tb_user_view as select id,gender from tb_user;

-- 查询每个学生所选修的课程（三张表联查），这个功能在很多业务中都有使用到，简化操作，定义视图
select s.name,s.no,c.name from student s,course c,student_course sc  where s.id = sc.studentID and c.id = sc.courseID;

-- 错误，name字段错误，要起别名
create view stu_course_view as select s.name ,s.no,c.name from student s,course c,student_course sc  where s.id = sc.studentID and c.id = sc.courseID;


create view stu_course_view as select s.name sudent_name ,s.no student_no,c.name course_name from student s,course c,student_course sc  where s.id = sc.studentID and c.id = sc.courseID;

```

## p45 存储过程-介绍

存储过程

- 介绍

![image-20220216160528801](https://s2.loli.net/2022/02/16/Gs9MTIBAJpdRKD5.png)

特点：

1. 封装、服用
2. 可以接受参数，也可以返回数据
3. 减少网络交互，效率提升

## p46 存储过程-基本语法

- 创建

```sql
create procedure 存储过程名称([参数列表])
begin
	-- SQL语句
end
```

- 调用

```sql
call 名称([参数])
```

- 查看

```sql
select *from information_schema.routines where routine_schema='xx';-- 查询指定数据库的存储过程及状态信息

show create procedure 存储过程名称; -- 查询某个存储过程定义
```

- 删除

```sql
drop procedure [if exists] 存储过程名称;
```

![](https://s2.loli.net/2022/02/16/epiVP745LnFWMOz.png)

演示：

```sql
-- 存储过程
-- 创建
create procedure p1()
begin
    select count(*) from student;
end;

-- 调用
call p1();

-- 查看
select *from information_schema.routines where routine_schema='ithm';

show create procedure p1;

-- 删除
drop procedure if exists p1;

```

注意：在命令行中，执行创建存储过程的SQL时，需要通过关键字`delimiter`指定SQL语句的结束符。

```sql
-- 在命令行中执行，遇到分号结束
mysql> create procedure p1()
    -> begin
    ->     select count(*) from student;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '' at line 3
mysql> end;

-- 指定以$$为结束符
mysql> delimiter $$

mysql> create procedure p2()
    -> begin
    ->     select count(*) from student;
    -> end$$
Query OK, 0 rows affected (0.01 sec)

mysql> delimiter ;
mysql> call p2();
+----------+
| count(*) |
+----------+
|        8 |
+----------+
1 row in set (0.00 sec)

Query OK, 0 rows affected (0.00 sec)

```

## p47 存储过程-变量-系统变量

变量：系统变量、自定义变量、局部变量

系统变量：由MySQL服务器提供，不是用户定义，属于服务器层面。分为全局变量（Global)、会话变量（session)。

- 查看系统变量

```sql
show [session|global] variables; -- 查看所有系统变量
show [session|global] variables like '...' -- like模糊匹配
select @@[session|global] 系统变量名;-- 查看指定变量名
```

- 设置系统变量

```sql
set [session|global] 系统变量名 = 值;
set @@[session|global] 系统变量名 = 值;
```

注意：

1. 如果没有指定session/global，默认为session，会话变量；
2. mysql服务器启动之后，所设置的全局参数失效，要想不失效，在/etc/my.cnf中设置。

## p48 存储过程-变量-用户自定义变量

- 用户自定义变量：用户根据需要自定义，不用提前声明，在用的时候直接“@变量名”使用即可。其作用域为当前连接。

注意：用户自定义的变量无需对其进行声明或者初始化，只不过获取到的值为null;

1. 赋值

```sql
set @var_name =expr[,@var_name = expr]...;
set @var_name :=expr[,@var_name :=expr]...;


select @var_name :=expr[,@var_name :=expr]...
select 字段名 into @var_name from 表名;
```

2. 使用

```sql
select @var_name;
```

3. 演示

```sql
-- 变量：用户变量
-- 赋值 推荐赋值采用:=
set @myname = 'itcast';

set @myage :=10;
set @mygender :='男' ,@myhobby :='java';

select @mycolor := 'red'; -- select @mycolor = 'red' 错误
select count(*) into @mycount from tb_user;

-- 使用
select @myname,@myage,@mygender,@myhobby;
select @mycolor,@mycount;
```



## p49存储过程-变量-局部变量

局部变量：根据需要定义在局部生效的变量，访问之前，需要declare声明。可用作存储过程内的局部变量和输入参数，局部变量的范围实在其内声明的begin...end块

- 声明

```sql
declare 变量名 变量类型[default...];
```

变量类型就是数据库字段类型：int、bigint、char、varchar、date、time等

- 赋值

```sql
set 变量名 = 值
set 变量名 := 值;
select 字段名 into 变量名 from 表名...;
```

- 演示

```sql
-- 局部变量
-- 声明 - declare
-- 赋值
create procedure p3()
begin
    declare stu_count int default  0;
    -- set stu_count := 100;
    select count(*) into stu_count from student;
    select stu_count;
end;

call p3();
```



## p50存储过程-if判断

- if语法

```sql
if 条件1 then
...
elseif 条件2 then 
...
else
...
end if;
```

![image-20220216171550177](https://s2.loli.net/2022/02/16/9f4CTnpibrH6Pu8.png)

```sql
create procedure p4()
begin
    declare score int default 58;
    declare result varchar(10);
    if score >=85 then
        set result := '优秀';
    elseif score >=60 then
        set result := '及格';
    else
        set result := '不及格';
    end if;
    select result;
end;

call p4();
```

## p51存储过程-参数(in,out,inout)

- 参数

![image-20220216172145107](https://s2.loli.net/2022/02/16/hwmA8pdE9HFgia7.png)

用法

```sql
create procedure 存储过程名称([in/out/inout 参数名 参数类型])
begin
	-- SQL语句
end;
```

![image-20220216172557590](https://s2.loli.net/2022/02/16/1LfWd9Jqo3jlRBa.png)

演示：

```sql
-- 1. in/out
create procedure p5(in score int,out result varchar(10))
begin
    if score >=85 then
        set result := '优秀';
    elseif score >=60 then
        set result := '及格';
    else
        set result := '不及格';
    end if;
end;

-- 用户自定义变量接收
call p5(98,@result);
select @result;

-- 2. inout
create procedure p6(inout score double)
begin
    set score := score *0.5;
end;

set @score = 78;
call p6(@score);
select @score;
```

## p52 存储过程-case

- case

1. 语法1

```sql
case case_value
	when when_value1 then statement_list1
	[when when_value1 then statement_list1]...
	[else statement_list]
end case;
```

2. 语法2

```sql
case  
	when search_conditiom1 then statement_list1
	[when search_conditiom1 then statement_list2]...
	[else statement_list]
end case;
```

演示：季度的转换

```sql
create procedure p7(in month int)
begin
    declare result varchar(10);
    case
        when month >= 1 and month <=3 then
            set result := '第一季度';
        when month >= 4 and month <=6 then
            set result := '第二季度';
        when month >= 7 and month <=9 then
            set result := '第三季度';
        when month >= 10 and month <=12 then
            set result := '第四季度';
        else
            set result :='非法参数';
    end case ;
    select concat('输入月份:',month,',所属的季度:',result);
end;
call p7(12);

-- 输入月份:12,所属的季度:第四季度
```

## p53 存储过程-循环-while

存储过程

- while循环

```sql
while 条件 do
	SQL逻辑...
end while;
```

- 演示：计算从1累加到n的值，n为传入的参数

```sql
-- while 求 1到n;
create procedure p8(in n int)
begin
    declare result int default 0;
    while n >0 do
        set result := result + n;
        set n := n -1;
    end while;
    select result;
end;

call p8(10);
```

## p54 存储过程-循环-repeat

- repeat 

repeat 是有条件的循环控制语句，**当满足条件时退出循环**

语法

```sql
repeat 
	SQL逻辑
	until条件
end repeat;
```

```sql
-- 计算1到n，repeat;
create procedure p9(in n int)
begin 
    declare result int default 0;
    repeat 
        set result := result + n;
        set n = n - 1;
    until  n= 0
    end repeat;
    select result;
end;

call p8(10);
```

## p55 存储过程-循环-loop

- loop

loop如若不在SQL逻辑中增加退出循环的条件，可以用来实现简单的死循环。loop配合以下两个语句使用

1. leave:配合循环使用，退出循环--- break
2. iterate:必须用在循环中，作用时跳过当前循环剩下的语句，直接进入下一次循环 -- continue。

```sql
[begin_label:]loop
	SQL逻辑...
end loop [end_label];

leave label; -- 退出指定循环体
iterate label; -- 直接进入下一次循环
```

演示：

```sql
-- loop 1到n求和
create procedure p10(in n int)
begin
    declare res int default 0;
    sum:loop
        set res := res + n;
        set n := n - 1;
        if n = 0 then
            leave sum;
        end if;
    end loop sum;
    select res;
end;

call p10(100);

-- 计算1到n偶数之和
create procedure p11(in n int)
begin
    declare res int default 0;
    sum:loop
        if n = 0 then
            leave sum;
        end if;
        if n % 2 = 1 then
            set n := n -1;
            iterate sum;
        end if;
        set res := res + n;
        set n := n - 1;
    end loop sum;
    select res;
end;

call p11(10);
```

## p56 存储过程-游标cursor

- 游标

游标（cursor）是用来存储查询结果集的数据类型，在存储过程和函数中可以使用游标对结果集进行循环的处理。游标的使用包括游标的声明、open、fetch和close，其语法如下。

```sql
-- 声明游标
declare 游标名称 cursor for 查询语句;

-- 打开游标
open 游标;

-- 获取游标记录
fetch 游标名称 into 变量[,变量];

-- 关闭游标
close 游标名称;
```

练习：姓名和电话（不是专业）

![image-20220216231829965](https://s2.loli.net/2022/02/16/Kva6jde9shx14YW.png)

```sql
-- 1.声明游标，存储查询结果
-- 2.准备：创建表结构
-- 3.开启游标
-- 4.获取游标中的记录
-- 5.插入数据到新表中
-- 6.关闭游标

create procedure p12(in uage int )
begin
    -- 先声明普通变量，再声明游标
    declare uname varchar(100);
    declare uphone varchar(11);
    declare u_cursor cursor for select name,phone from tb_user where age < uage;
    create table if not exists  tb_user_phone(
        id int primary key auto_increment,
        name varchar(100),
        phone varchar(11)
    );
    
    open u_cursor;

    -- 游标遍历完结束,这里存在不足，当游标没有应该退出，下节解决问题
    while true do
        fetch u_cursor into uname,uphone ;
        insert into tb_user_phone values (null,uname,uphone);
    end while;

    -- 关闭游标
    close u_cursor;
end;

call  p12(40);
```

## p57 存储过程-条件处理程序-handler

- 条件处理程序：用来定义在流程控制结构执行过程中遇到问题时相应的处理步骤，具体语法：

```sql
declare handler_action handler for condition_value[,condition_value]... statement;

handler_action
	continue :继续执行当前程序
	exit:终止执行当前程序
condition_value
	sqlstate sqlstate_value:状态码，如02000
	sqlwarning:所有以01开头的sqlstate代码的简写
	not found: 所有以02开头的sqlstate代码的简写
	sqlexception:所有没有被sqlwarning或者not found捕获的sqlstate代码的简写
```

```sql
create procedure p12(in uage int )
begin
    -- 先声明普通变量，再声明游标
    declare uname varchar(100);
    declare uphone varchar(11);
    declare u_cursor cursor for select name,phone from tb_user where age < uage;
    
    -- 当SQL状态码为02000关闭游标
    declare exit handler for SQLSTATE '02000' close u_cursor;

    create table if not exists  tb_user_phone(
        id int primary key auto_increment,
        name varchar(100),
        phone varchar(11)
    );

    open u_cursor;

    -- 游标遍历完结束,这里存在不足，当游标没有应该退出，下节解决问题
    while true do
        fetch u_cursor into uname,uphone ;
        insert into tb_user_phone values (null,uname,uphone);
    end while;

    -- 关闭游标
    close u_cursor;
end;

call  p12(40);
```

## p58 存储函数

存储函数

存储函数**是有返回值的存储过程**，存储函数的参数**只能是in类型**的，具体语法如下。

```sql
create function 存储函数名称([参数列表])
returns type [characteristic...]
begin
	-- SQL语句
	return ...;
end;

characteristic说明：
1.deterministic:相同的输入参数总是产生相同的结果
2.no sql:不包含SQL的语句
3.reads SQL data:包含读取数据的语句，但不包含写入数据的语句
```

演示：计算1到n的累加和

```sql
-- 存储函数
create function func1(n int)
returns int deterministic
begin
    declare res int default 0;
    while n > 0 do
        set res := res + n;
        set n := n -1;
    end while;

    return res;
end;

select func1(10);
```

## p59 触发器-介绍

![image-20220217000538989](https://s2.loli.net/2022/02/17/5PL782cFBIme6OM.png)

update语句 影响5行，触发5次，称行级触发器；只出发一次，称为语句级触发.

## p60 触发器-insert类型

- 创建

```sql
create trigger trigger_name
before/after insert/update/delete
on table_name for each row -- 行级触发器
begin
	trigger_stmt;
end;
```

- 查看

```sql
show triggers;
```

- 删除

```sql
drop trigger [schema_name.]trigger_name; -- 如果没有指定schema_name，默认为当前数据库.
```

定义触发器，完成以下需求

![image-20220217001730929](https://s2.loli.net/2022/02/17/4Wa6jLGAHSJYi2e.png)

```sql
-- 创建日志表
create table user_logs(
    id int(11) not null auto_increment,
    operation varchar(20) not null comment '操作类型，insert/update/delete',
    operation_time datetime not null comment '操作时间',
    operation_id int(11) not null comment '操作的ID',
    operation_params varchar(500) comment '操作参数',
    primary key (`id`)
)engine = innodb default charset =utf8 ;

-- id name age gender phone
-- 插入数据触发器
create trigger tb_user_insert_trigger
    after insert  on tb_user for each row
begin
    insert into user_logs(id, operation, operation_time, operation_id, operation_params) values
    (null,'insert',now(),NEW.id,concat('插入的数据内容为:id = ',NEW.id,',name = ',NEW.name,',age = ',NEW.age,',gender = ',NEW.gender));
end;

-- 查看触发器
show triggers ;

-- 删除触发器
drop trigger tb_user_insert_trigger;

-- 插入数据到tb_user
insert into tb_user(id, name, age, gender, phone) values (25,'二哈',19,'男',null);
```

```sql
-- 创建日志表
create table user_logs(
    id int(11) not null auto_increment,
    operation varchar(20) not null comment '操作类型，insert/update/delete',
    operation_time datetime not null comment '操作时间',
    operation_id int(11) not null comment '操作的ID',
    operation_params varchar(500) comment '操作参数',
    primary key (`id`)
)engine = innodb default charset =utf8 ;

-- id name age gender phone
-- 插入数据触发器
create trigger tb_user_insert_trigger
    after insert  on tb_user for each row
begin
    insert into user_logs(id, operation, operation_time, operation_id, operation_params) values
    (null,'insert',now(),NEW.id,concat('插入的数据内容为:id = ',NEW.id,',name = ',NEW.name,',age = ',NEW.age,',gender = ',NEW.gender));
end;

-- 查看触发器
show triggers ;

-- 删除触发器
drop trigger tb_user_insert_trigger;

-- 插入数据到tb_user
insert into tb_user(id, name, age, gender, phone) values (25,'二哈',19,'男',null);

-- 执行插入语句之后，查看user_log表;
mysql> select * from user_Logs;
+----+-----------+---------------------+--------------+-----------------------------------------------------------+
| id | operation | operation_time      | operation_id | operation_params                                          |
+----+-----------+---------------------+--------------+-----------------------------------------------------------+
|  1 | insert    | 2022-02-17 00:32:22 |           25 | 插入的数据内容为:id = 25,name = 二哈,age = 19,gender = 男 |
+----+-----------+---------------------+--------------+-----------------------------------------------------------+
1 row in set (0.01 sec)
```

## p61 触发器-update类型

```sql
-- 修改数据触发器
create trigger tb_user_update_trigger
    after update on tb_user for each row
begin
    insert into user_logs(id, operation, operation_time, operation_id, operation_params) values
    (null,'update',now(),NEW.id,
     concat('更新之前内容为:id = ',OLD.id,',name = ',OLD.name,',age = ',OLD.age,',gender = ',OLD.gender,
         '| 更新之后内容为:id = ',NEW.id,',name = ',NEW.name,',age = ',NEW.age,',gender = ',NEW.gender));
end;

show triggers ;

-- 插入数据到tb_user
update tb_user set age = 34 where id = 25;

-- 行级触发器，触发5次
update tb_user set age = 34 where id < 50;
```

![image-20220217004303869](https://s2.loli.net/2022/02/17/ZgJC84GqD69VTty.png)

## p62 触发器-delete类型

```sql
-- 删除数据触发器
create trigger tb_user_delete_trigger
    after delete on tb_user for each row
begin
    insert into user_logs(id, operation, operation_time, operation_id, operation_params) values
    (null,'update',now(),OLD.id,
     concat('删除之前内容为:id = ',OLD.id,',name = ',OLD.name,',age = ',OLD.age,',gender = ',OLD.gender));
end;

show triggers ;

delete from tb_user where id = 25;
```

![image-20220217004816152](https://s2.loli.net/2022/02/17/DpG6eL4oaBikdUF.png)

## p63 视图&存储过程&触发器-小结

1. 视图（view)

- 虚拟存在的表，不保存查询结果，只保存查询的SQL逻辑
- 简单、安全、数据独立

2. 存储过程（procedure）

- 事先定义并存储在数据库中的一段SQL语句的集合
- 减少网络交互，提高性能，**封装重用**
- 变量、if、case、参数（in/out/inout)、while、loop、repeat、loop、cursor、handler.

3. 存储函数（function)

- 存储函数**是有返回值的存储过程**，存储函数的参数**只能是in类型**的
- 存储函数可以被存储过程替代

4. 触发器（trigger）

- 可以在表数据进行insert、update、delete之前或之后触发
- 保证数据完整性、日志记录、数据校验

## p64 锁-介绍

概述、全局锁、表级锁、行级锁；

- 概述

![image-20220217011641147](https://s2.loli.net/2022/02/17/dzMDWtRXxjprv6H.png)

- 分类

MySQL中的锁，按照锁的粒度分，分为以下三类

1. 全局锁：锁定数据库中的所有表
2. 表级锁：每次操作锁住整张表
3. 行级锁：每次操作锁住对应的行数据

## p65 锁-全局锁

- 介绍

![image-20220217011932436](https://s2.loli.net/2022/02/17/fp83rH7tP2SLKnd.png)

备份是有顺序的，在备份tb_stock时，还有订单，会导致之后数据的不一致。

![image-20220217012201872](https://s2.loli.net/2022/02/17/xukFZA6NmWt5fLU.png)

加上全局锁之后：

## ![image-20220217012608710](https://s2.loli.net/2022/02/17/LugYsAtS5oZjdeU.png)p66 锁-全局锁-一致性数据备份



```sql
-- 上锁
mysql> flush tables with read lock;
Query OK, 0 rows affected (0.03 sec)

-- 释放锁
mysql> unlock tables;
Query OK, 0 rows affected (0.00 sec)
```

```shell
 -- windows 下cmd直接执行 数据备份
 mysqldump --no-defaults -uroot -p12345678 -p ithm >D:/mysql/ithm.sql
```



全局锁的特点：

![image-20220217015148112](https://s2.loli.net/2022/02/17/34ZoCKP2XIHNJVr.png)

```shell
mysqldump --no-defaults --single-transaction -uroot -p12345678 -p ithm >D:/mysql/ithm02.sql n
```

底层通过快照读实现

## p67 锁-表级锁 -表锁

- 介绍

表级锁，每次操作锁住整张表。锁定粒度大，发生锁冲突的概率最高，并发度最低。应用在MyISAM、InnoDB和BDB等存储引擎中

表级锁分类：

1. 表锁
2. 元数据锁（meta data lock,MDL)
3. 意向锁

- 表锁

分为以下两类

1. 表共享读锁（read lock)
2. 表独占写锁（write lock)

语法

```sql
-- 加锁：
lock tables 表名... read/write
-- 释放锁
unlock tables / 客户端断开连接
```

加了读锁，只能读，不能写，**读锁不会阻塞其他客户端的读，会阻塞其他客户端的写**

![image-20220217044536237](https://s2.loli.net/2022/02/17/ChJ4w2OivGITWkn.png)

```sql
-- 客户端A
mysql> lock tables tb_user read;
Query OK, 0 rows affected (0.00 sec)

mysql> select * from tb_user;
+----+------+------+--------+------------+
| id | name | age  | gender | phone      |
+----+------+------+--------+------------+
|  1 | tb   |   34 | 1      | 2432352525 |
|  2 | gs   |   34 | 2      | 324252552  |
|  3 | gag  |   34 | 1      | 34252365   |
|  4 | gag  |   34 | 2      | 245263763  |
+----+------+------+--------+------------+
4 rows in set (0.00 sec)
```

```sql
-- 客户端B 可读
mysql> select * from tb_user;
+----+------+------+--------+------------+
| id | name | age  | gender | phone      |
+----+------+------+--------+------------+
|  1 | tb   |   34 | 1      | 2432352525 |
|  2 | gs   |   34 | 2      | 324252552  |
|  3 | gag  |   34 | 1      | 34252365   |
|  4 | gag  |   34 | 2      | 245263763  |
+----+------+------+--------+------------+
4 rows in set (0.00 sec)
```

```sql
-- 客户端A
mysql> update tb_user set name = 'zc' where id = 1;
ERROR 1100 (HY000): Table 'user_logs' was not locked with LOCK TABLES
```

```sql
-- 客户端B
mysql> update tb_user set name = 'zc' where id = 1;
- 光标闪烁 阻塞
此时 客户端释放锁

-- 客户端A 释放表锁
mysql> unlock tables;
Query OK, 0 rows affected (0.00 sec)

-- 客户端B
mysql> update tb_user set name = 'zc' where id = 1;
Query OK, 1 row affected (1 min 13.62 sec)
Rows matched: 1  Changed: 1  Warnings: 0
```



对表加写锁，**其他客户端阻塞，不能读也不能写**，当前客户端可以读也可以写

![image-20220217044629702](https://s2.loli.net/2022/02/17/bjfSnIEGqDXk6Wd.png)

```sql
-- 客户端1 加写锁之后，既能读又能写
mysql> lock tables tb_user write;
Query OK, 0 rows affected (0.00 sec)

mysql> select *from tb_user;
+----+------+------+--------+------------+
| id | name | age  | gender | phone      |
+----+------+------+--------+------------+
|  1 | zc   |   34 | 1      | 2432352525 |
|  2 | gs   |   34 | 2      | 324252552  |
|  3 | gag  |   34 | 1      | 34252365   |
|  4 | gag  |   34 | 2      | 245263763  |
+----+------+------+--------+------------+
4 rows in set (0.00 sec)

mysql> update tb_user set name = 'tom' where id = 2;
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0
```

```sql
-- 客户端2 既不能读，也不能写，一直阻塞，直达客户端1解除表锁
mysql> select * from tb_user;
Enter password: ********
^C -- query aborted
ERROR 1317 (70100): Query execution was interrupted
```

## p68 锁-表级锁-元数据锁

- 元数据锁(metal data lock MDL)

MDL加锁时系统自动控制，无需显式使用，在访问一张表的时候自动加上。

作用是维护表元数据（表结构）的数据一致性，在表上有活动事务时，不可以对元数据进行写入操作。**为了避免DML与DDL冲突，保证读写的正确性。**

**当对一张表增删改查的时候，加DML读锁（共享）；当对表结构进行变更操作时，加MDL写锁（排他）。**

![image-20220217045853152](https://s2.loli.net/2022/02/17/5TfIihX2z8MmnqP.png)

```sql
-- 客户端1 开启事务
mysql> begin;
Query OK, 0 rows affected (0.00 sec)

-- select 会自动加元数据锁
mysql> select *from tb_user;
+----+------+------+--------+------------+
| id | name | age  | gender | phone      |
+----+------+------+--------+------------+
|  1 | zc   |   34 | 1      | 2432352525 |
|  2 | tom  |   34 | 2      | 324252552  |
|  3 | gag  |   34 | 1      | 34252365   |
|  4 | gag  |   34 | 2      | 245263763  |
+----+------+------+--------+------------+
4 rows in set (0.00 sec)

-- 此时切换到客户端2 发现可以读，也可以写
mysql> begin;
Query OK, 0 rows affected (0.00 sec)

mysql> select * from tb_user;
+----+------+------+--------+------------+
| id | name | age  | gender | phone      |
+----+------+------+--------+------------+
|  1 | zc   |   34 | 1      | 2432352525 |
|  2 | tom  |   34 | 2      | 324252552  |
|  3 | gag  |   34 | 1      | 34252365   |
|  4 | gag  |   34 | 2      | 245263763  |
+----+------+------+--------+------------+
4 rows in set (0.00 sec)

mysql> update tb_user set name = 'jerry' where id = 3;
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0
```

```sql
-- 客户端1 
mysql> begin;
Query OK, 0 rows affected (0.00 sec)

mysql> select * from tb_user;
+----+-------+------+--------+------------+
| id | name  | age  | gender | phone      |
+----+-------+------+--------+------------+
|  1 | zc    |   34 | 1      | 2432352525 |
|  2 | tom   |   34 | 2      | 324252552  |
|  3 | jerry |   34 | 1      | 34252365   |
|  4 | gag   |   34 | 2      | 245263763  |
+----+-------+------+--------+------------+
4 rows in set (0.00 sec)

-- 客户端2 执行alter table会一直阻塞 此时加的是排他锁，与其他都互斥，直到客户端1中提交事务才执行。
mysql> alter table tb_user add column java int;
```

查看元数据锁

```sql
select object_type,object_schema,object_name,lock_type,lock_duration from performance_schema.metadata_locks;
```

## p69 锁-表级锁-意向锁

- 意向锁

**为了避免DML在执行过程中，加的行锁与表锁的冲突，在InnoDB中引入了意向锁，使得表锁不用检查每行数据是否加锁，使用意向锁来减少表锁的检查。**

解释todo

1. 意向共享锁（IS):由`select ...lock in share mode`添加，与表锁共享锁（read)兼容，与表锁排他锁（write)互斥。
2. 意向排他锁（IX）：由`insert、update、delete、select ... for update`添加，与表锁共享锁（read)及排他锁（write)都互斥。意向锁之间不会互斥。

查看意向锁及行锁的加锁情况

```sql
select object_schema,object_name,index_name,lock_type,lock_mode,lock_data from performance_schema.data_locks;
```

## p70 锁-表级锁-测试

```sql
-- 客户端1 加上行锁和意向共享锁
mysql> select *from tb_user where id = 1 lock in share mode;
+----+------+------+--------+------------+------+
| id | name | age  | gender | phone      | java |
+----+------+------+--------+------------+------+
|  1 | zc   |   34 | 1      | 2432352525 | NULL |
+----+------+------+--------+------------+------+
1 row in set (0.00 sec)

-- 客户端2
mysql> select object_schema,object_name,index_name,lock_type,lock_mode,lock_data from performance_schema.data_locks;
+---------------+-------------+------------+-----------+---------------+-----------+
| object_schema | object_name | index_name | lock_type | lock_mode     | lock_data |
+---------------+-------------+------------+-----------+---------------+-----------+
| ithm          | tb_user     | NULL       | TABLE     | IS            | NULL      |
| ithm          | tb_user     | PRIMARY    | RECORD    | S,REC_NOT_GAP | 1         |
+---------------+-------------+------------+-----------+---------------+-----------+
2 rows in set (0.00 sec)

-- IS和读锁兼容，可以加锁成功
mysql> lock tables tb_user read;
Query OK, 0 rows affected (0.00 sec)

mysql> unlock tables;
Query OK, 0 rows affected (0.00 sec)

-- IS和写锁互斥，一直阻塞直到客户端1提交事务(行锁和意向共享锁都会释放）。
mysql> lock tables tb_user write;
-光标闪烁，阻塞
```

```sql
-- 客户端1
mysql> begin;
Query OK, 0 rows affected (0.00 sec)
-- 此时加上行锁和IX
mysql> update tb_user set age = 36 where id = 3;
Query OK, 1 row affected (13.39 sec)
Rows matched: 1  Changed: 1  Warnings: 0

-- 客户端2
mysql> select object_schema,object_name,index_name,lock_type,lock_mode,lock_data from performance_schema.data_locks;
+---------------+-------------+------------+-----------+---------------+-----------+
| object_schema | object_name | index_name | lock_type | lock_mode     | lock_data |
+---------------+-------------+------------+-----------+---------------+-----------+
| ithm          | user_logs   | NULL       | TABLE     | IX            | NULL      |
| ithm          | tb_user     | NULL       | TABLE     | IX            | NULL      |
| ithm          | tb_user     | PRIMARY    | RECORD    | X,REC_NOT_GAP | 3         |
+---------------+-------------+------------+-----------+---------------+-----------+
3 rows in set (0.00 sec)

mysql> lock tables tb_user read;
-阻塞，因为IX与读锁和写锁都互斥，直到客户端1提交事务
```

## p71锁-行级锁-介绍

- 介绍

行级锁，每次操作锁住对应的行数据。锁的粒度最小，发生锁冲突的概率最低，并发度最高。应用在InnoDB存储引擎中

**InnoDB的数据是基于索引组织的，行锁是通过对索引上的索引项加锁来实现的，而不是对记录加的锁**。行级锁分三类：

1. **行锁(record lock)**：锁定单个记录的锁，防止其他事务对此进行update和delete。在RC、RR隔离级别下都支持

![image-20220217055228994](https://s2.loli.net/2022/02/17/eo1UpgBruWa2O6h.png)

2. **间隙锁**（Gap lock)：**锁定索引记录间隙（不含该记录）**，确保索引记录间隙不变，防止其他事务在这个间隙进行insert,产生幻读。在RR隔离级别下都支持。

![image-20220217055253885](https://s2.loli.net/2022/02/17/nihWNLuoBjH46Tm.png)3. **临建**锁（next-key lock)：**行锁和间隙锁组合，同时锁住数据，并锁住数据前面的间隙Gap**。在RR隔离级别下支持。

![image-20220217055342991](https://s2.loli.net/2022/02/17/bXrVKSGW7jtCnpF.png)

## p72 锁-行级锁-行锁

- 行锁

InnoDB实现了以下两种类型的行锁（理解todo)

1. 共享锁（S）：允许一个事务去读一行，阻止其他事务获得相同数据集的排它锁。
2. 排它锁（X)：允许获取排他锁的事务更新数据，阻止其他事务获得相同数据集的共享锁和排他锁。

![image-20220217055946273](https://s2.loli.net/2022/02/17/YlX4STvy3NwDhPA.png)



![image-20220217060050641](https://s2.loli.net/2022/02/17/zRob1PtTKasnISW.png)

行锁-演示

默认情况，InnoDB在repeatable read 事务隔离级别运行，**InnoDB使用next-key锁进行搜索和索引扫描，以防止幻读**。

1. 针对唯一索引进行检索时，对已存在的记录进行等值匹配时，将会自动优化为行锁。
2. InnoDB的行锁针对索引加的锁，不通过索引条件检索数据，那么InnoDB将对表中的所有记录加锁，此时就会升级为表锁。

```sql
-- 共享锁与共享锁兼容
-- 客户端1
mysql> begin;
Query OK, 0 rows affected (0.00 sec)

mysql> select * from tb_user where id = 1;
+----+------+------+--------+------------+------+
| id | name | age  | gender | phone      | java |
+----+------+------+--------+------------+------+
|  1 | zc   |   34 | 1      | 2432352525 | NULL |
+----+------+------+--------+------------+------+
1 row in set (0.00 sec)

-- 客户端2
mysql> select object_schema,object_name,index_name,lock_type,lock_mode,lock_data from performance_schema.data_locks;
Empty set (0.00 sec)

mysql> begin;
Query OK, 0 rows affected (0.00 sec)

mysql> select *from tb_user where id = 1;
+----+------+------+--------+------------+------+
| id | name | age  | gender | phone      | java |
+----+------+------+--------+------------+------+
|  1 | zc   |   34 | 1      | 2432352525 | NULL |
+----+------+------+--------+------------+------+
1 row in set (0.00 sec)

-- 客户端1 加行锁（共享S）
mysql> select * from tb_user where id = 1 lock in share mode;
+----+------+------+--------+------------+------+
| id | name | age  | gender | phone      | java |
+----+------+------+--------+------------+------+
|  1 | zc   |   34 | 1      | 2432352525 | NULL |
+----+------+------+--------+------------+------+
1 row in set (0.00 sec)

-- 客户端2 下面为行锁（S,共享锁）且没有间隙。
mysql> select object_schema,object_name,index_name,lock_type,lock_mode,lock_data from performance_schema.data_locks;
+---------------+-------------+------------+-----------+---------------+-----------+
| object_schema | object_name | index_name | lock_type | lock_mode     | lock_data |
+---------------+-------------+------------+-----------+---------------+-----------+
| ithm          | tb_user     | NULL       | TABLE     | IS            | NULL      |
| ithm          | tb_user     | PRIMARY    | RECORD    | S,REC_NOT_GAP | 1         |
+---------------+-------------+------------+-----------+---------------+-----------+
2 rows in set (0.00 sec)

-- 共享锁和共享锁兼容
mysql>  select * from tb_user where id = 1 lock in share mode;
+----+------+------+--------+------------+------+
| id | name | age  | gender | phone      | java |
+----+------+------+--------+------------+------+
|  1 | zc   |   34 | 1      | 2432352525 | NULL |
+----+------+------+--------+------------+------+
1 row in set (0.00 sec)

mysql> select object_schema,object_name,index_name,lock_type,lock_mode,lock_data from performance_schema.data_locks;
+---------------+-------------+------------+-----------+---------------+-----------+
| object_schema | object_name | index_name | lock_type | lock_mode     | lock_data |
+---------------+-------------+------------+-----------+---------------+-----------+
| ithm          | tb_user     | NULL       | TABLE     | IS            | NULL      |
| ithm          | tb_user     | PRIMARY    | RECORD    | S,REC_NOT_GAP | 1         |
| ithm          | tb_user     | NULL       | TABLE     | IS            | NULL      |
| ithm          | tb_user     | PRIMARY    | RECORD    | S,REC_NOT_GAP | 1         |
+---------------+-------------+------------+-----------+---------------+-----------+
4 rows in set (0.00 sec)

mysql> commit;
Query OK, 0 rows affected (0.00 sec)

mysql> begin;
Query OK, 0 rows affected (0.00 sec)

-- 提交之后，第二个客户端的共享锁消失
mysql> select object_schema,object_name,index_name,lock_type,lock_mode,lock_data from performance_schema.data_locks;
+---------------+-------------+------------+-----------+---------------+-----------+
| object_schema | object_name | index_name | lock_type | lock_mode     | lock_data |
+---------------+-------------+------------+-----------+---------------+-----------+
| ithm          | tb_user     | NULL       | TABLE     | IS            | NULL      |
| ithm          | tb_user     | PRIMARY    | RECORD    | S,REC_NOT_GAP | 1         |
+---------------+-------------+------------+-----------+---------------+-----------+
2 rows in set (0.00 sec)

-- 这里操作id 为3 ，而客户端1加的是id为1的行锁(S),不影响
mysql> update tb_user set name = 'zzc' where id = 3;
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

-- 这里阻塞，因为1已经加了共享锁，与排它锁互斥
mysql> update tb_user set name = 'vava' where id = 1;
-
```

```sql
-- 演示排他锁与排他锁
-- 客户端1
mysql> begin;
Query OK, 0 rows affected (0.00 sec)
-- 加上排他锁
mysql> update tb_user set name = 'vava' where id = 1;
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

-- 客户端2 此时会阻塞，因为排他锁和排他锁互斥，直到客户端1事务提交，释放排他锁。
mysql> begin;
Query OK, 0 rows affected (0.00 sec)
mysql> update tb_user set name = 'vava' where id = 1;
-
```

```sql
-- 
-- 客户端1
mysql> select * from tb_user;
+----+------+------+--------+------------+------+
| id | name | age  | gender | phone      | java |
+----+------+------+--------+------------+------+
|  1 | vava |   34 | 1      | 2432352525 | NULL |
|  2 | tom  |   34 | 2      | 324252552  | NULL |
|  3 | zzc  |   36 | 1      | 34252365   | NULL |
|  4 | gag  |   34 | 2      | 245263763  | NULL |
+----+------+------+--------+------------+------+
4 rows in set (0.01 sec)

mysql> begin;
Query OK, 0 rows affected (0.00 sec)

mysql> update tb_user set name = 'vav' where name = 'vava';
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

-- 客户端2
mysql> begin;
Query OK, 0 rows affected (0.00 sec)

-- 阻塞，因为name字段没有索引，所有记录加锁，升级为表锁，直到客户端1commit提交。
mysql> update tb_user set name = 'Php'where id =3 ;

-- 接着客户端1提交，然后客户端2提交
----------------------

-- 客户端1 ，创建索引
mysql> create index idx_user_name on tb_user(name);
Query OK, 0 rows affected (14.92 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> begin;
Query OK, 0 rows affected (0.00 sec)

mysql> update tb_user set name = 'vav' where name = 'va';
Query OK, 0 rows affected (0.00 sec)
Rows matched: 0  Changed: 0  Warnings: 0

-- 客户端2 
mysql> begin;
Query OK, 0 rows affected (0.00 sec)

-- 创建索引之后，更新成功，因此没有锁整个表
mysql> update tb_user set name = 'Php'where id =3 ;
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0
```

## p73 锁-行级锁-间隙锁&临建锁1

默认情况，InnoDB在repeatable read 事务隔离级别运行，**InnoDB使用next-key锁进行搜索和索引扫描，以防止幻读**。

1. 索引上的等值查询(唯一索引)，给不存在的记录加锁，优化为间隙锁。
2. 索引上得等值查询(普通索引)，向右遍历时最后一个值不满足等值查询需求时，next-key lock 退化为间隙锁。
3. 索引上得范围查询（唯一索引）---会访问到不满足条件得第一个值为止。

**注意：间隙锁唯一目的是防止其他事务插入间隙，造成幻读现象。间隙锁可以共存，一个事务采用的间隙锁不会阻止另一个事务在同一间隙上采用间隙锁。**

```sql
-- 客户端1
mysql> select *from tb_user;
+----+------+------+--------+------------+------+
| id | name | age  | gender | phone      | java |
+----+------+------+--------+------------+------+
|  1 | vav  |   34 | 1      | 2432352525 | NULL |
|  2 | tom  |   34 | 2      | 324252552  | NULL |
|  3 | Php  |   36 | 1      | 34252365   | NULL |
|  4 | gag  |   34 | 2      | 245263763  | NULL |
|  8 | 关羽 |   34 | 1      | NULL       | NULL |
+----+------+------+--------+------------+------+
5 rows in set (0.01 sec)

mysql> begin;
Query OK, 0 rows affected (0.00 sec)

-- id 为6的数据不存在，此时会对4到8加上间隙锁
mysql> update tb_user set name = '张三' where id = 6;
Query OK, 0 rows affected (0.00 sec)
Rows matched: 0  Changed: 0  Warnings: 0

-- 客服端2 gap(间隙锁，8之前)
mysql> select object_schema,object_name,index_name,lock_type,lock_mode,lock_data from performance_schema.data_locks;
+---------------+-------------+------------+-----------+-----------+-----------+
| object_schema | object_name | index_name | lock_type | lock_mode | lock_data |
+---------------+-------------+------------+-----------+-----------+-----------+
| ithm          | tb_user     | NULL       | TABLE     | IX        | NULL      |
| ithm          | tb_user     | PRIMARY    | RECORD    | X,GAP     | 8         |
+---------------+-------------+------------+-----------+-----------+-----------+
2 rows in set (0.00 sec)

mysql> begin;
Query OK, 0 rows affected (0.00 sec)
-- 此时插入id为6会阻塞，事务A提交之后，执行成功。
mysql>  insert into tb_user values ('6','关巡航',36,'1',null,null);
-

-- 事务A 提交
mysql> commit;
Query OK, 0 rows affected (0.00 sec)

-- 事务B 提交
mysql> commit;
Query OK, 0 rows affected (0.01 sec)

--  事务A 查询插入成功
mysql> select *from tb_user;
+----+--------+------+--------+------------+------+
| id | name   | age  | gender | phone      | java |
+----+--------+------+--------+------------+------+
|  1 | vav    |   34 | 1      | 2432352525 | NULL |
|  2 | tom    |   34 | 2      | 324252552  | NULL |
|  3 | Php    |   36 | 1      | 34252365   | NULL |
|  4 | gag    |   34 | 2      | 245263763  | NULL |
|  6 | 关巡航 |   36 | 1      | NULL       | NULL |
|  8 | 关羽   |   34 | 1      | NULL       | NULL |
+----+--------+------+--------+------------+------+
6 rows in set (0.01 sec)
```



## p74 锁-行级锁-间隙锁&临建锁2

```sql
-- 演示2
-- 客户端1
mysql> select *from tb_user;
+----+--------+------+--------+------------+------+
| id | name   | age  | gender | phone      | java |
+----+--------+------+--------+------------+------+
|  1 | vav    |   34 | 1      | 2432352525 | NULL |
|  2 | tom    |   34 | 2      | 324252552  | NULL |
|  3 | Php    |   36 | 1      | 34252365   | NULL |
|  4 | gag    |   34 | 2      | 245263763  | NULL |
|  6 | 关巡航 |   36 | 1      | NULL       | NULL |
|  8 | 关羽   |   34 | 1      | NULL       | NULL |
+----+--------+------+--------+------------+------+
6 rows in set (0.00 sec)

mysql> begin;
Query OK, 0 rows affected (0.00 sec)

-- 这里name字段为非唯一索引
mysql> select * from tb_user where name ='关巡航' lock in share mode;
+----+--------+------+--------+-------+------+
| id | name   | age  | gender | phone | java |
+----+--------+------+--------+-------+------+
|  6 | 关巡航 |   36 | 1      | NULL  | NULL |
+----+--------+------+--------+-------+------+
1 row in set (0.00 sec)

-- 客户端2
mysql> select object_schema,object_name,index_name,lock_type,lock_mode,lock_data from performance_schema.data_locks;
+---------------+-------------+---------------+-----------+---------------+-------------+
| object_schema | object_name | index_name    | lock_type | lock_mode     | lock_data   |
+---------------+-------------+---------------+-----------+---------------+-------------+
| ithm          | tb_user     | NULL          | TABLE     | IS            | NULL        |
| ithm          | tb_user     | idx_user_name | RECORD    | S             | '关巡航', 6 |
| ithm          | tb_user     | PRIMARY       | RECORD    | S,REC_NOT_GAP | 6           |
| ithm          | tb_user     | idx_user_name | RECORD    | S,GAP         | '关羽', 8   |
+---------------+-------------+---------------+-----------+---------------+-------------+
4 rows in set (0.00 sec)
-- 以上 34行的共享锁(S)为临建锁;35行对id为6的记录加上行锁（没有间隙）;36行间隙锁将6和8之间的间隙加锁。name字段为非唯一索引，防止其他事务在间隙(id为6和8之间)插入数据，出现幻读现象
```

```sql
-- 演示3
-- 客户端A
mysql> begin;
Query OK, 0 rows affected (0.00 sec)

mysql> select *from tb_user where id >=6 lock in share mode;
+----+--------+------+--------+-------+------+
| id | name   | age  | gender | phone | java |
+----+--------+------+--------+-------+------+
|  6 | 关巡航 |   36 | 1      | NULL  | NULL |
|  8 | 关羽   |   34 | 1      | NULL  | NULL |
+----+--------+------+--------+-------+------+
2 rows in set (0.00 sec)

-- 客户端B
mysql> select object_schema,object_name,index_name,lock_type,lock_mode,lock_data from performance_schema.data_locks;
+---------------+-------------+------------+-----------+---------------+------------------------+
| object_schema | object_name | index_name | lock_type | lock_mode     | lock_data              |
+---------------+-------------+------------+-----------+---------------+------------------------+
| ithm          | tb_user     | NULL       | TABLE     | IS            | NULL                   |
| ithm          | tb_user     | PRIMARY    | RECORD    | S,REC_NOT_GAP | 6                      |
| ithm          | tb_user     | PRIMARY    | RECORD    | S             | supremum pseudo-record |
| ithm          | tb_user     | PRIMARY    | RECORD    | S             | 8                      |
+---------------+-------------+------------+-----------+---------------+------------------------+
4 rows in set (0.00 sec)

-- 以上锁的情况，21行为 id为6这个记录加一个行锁; 23行临建锁(8之前);22行临建锁(8之后，到无穷大)
```

## p75 锁-小结



1. 概述
   - 并发访问，解决数据访问的一致性，有效性问题
   - 全局锁、表级锁、行级锁
2. 全局锁

- 对整个数据库实例加锁，加锁后整个实例处于只读状态
- 性能较差，数据逻辑备份时使用

3. 表级锁

- 操作锁住整张表，锁粒度大，发生锁冲突概率高
- 表锁、元数据锁、意向锁

4. 行级锁

- 每次操作锁住对应的行数据。锁的粒度最小，发生锁冲突的概率最低，并发度最高
- 行锁、间隙锁、临建锁

## p76 InnoDB引擎-逻辑存储结构

逻辑存储结构、结构、事务原理、MVCC

![image-20220215030052564](https://s2.loli.net/2022/02/17/zaEGJuZ2QYr9sI4.png)

表空间(ibd文件)：一个mysql实例可以对应多个表空间，**用于存储记录、索引等数据**。

段：分为数据段、索引段、回滚段、innodb是索引组织表，**数据段就是B+树的叶子节点，索引段即为B+树的非叶子节点**。段用来管理多个extent(区)。

区：表空间的单元结构，**每个区大小为1m**,默认情况，InnoDB存储引擎页大小为16K，即**一个区一共64个连续的页**。

页：是InnoDB存储引擎磁盘管理的最小单元，每个页的大小默认为16k。**为了保证页的连续性，InnoDB存储引擎每次从磁盘申请4-5个区。**

行：InnoDB存储引擎数据是按行进行存放的。

> - Trx id :每次对某条记录进行改动时，都会把对应事务id赋值给trx_id隐藏列
> - roll_pointer：每次对某条记录进行改动时，都会把旧的版本写入到undo日志中，然后这个隐藏列就相当于一个指针，可以通过它来该记录修改前的信息。

## p77&78 InnoDB引擎-架构-内存结构

MySQL(5.5之后）默认InnoDB存储引擎，**擅长处理事务，具有崩溃恢复特性，支持在线热备份**，在日常开发中使用非常广泛。

下面为innodb架构图，左侧内存结构，右侧为磁盘空间

![image-20220217152431654](https://s2.loli.net/2022/02/17/PQtzHqyNo8evhxu.png)

- InnoDB内存架构

1. Buffer Pool：缓冲池

![image-20220217152912580](https://s2.loli.net/2022/02/17/WVhvyt8uqLD9BaY.png)

2. change buffer：更改缓冲区

同步：change buffer---->buffer pool --->磁盘

![image-20220217153257446](https://s2.loli.net/2022/02/17/BFLAilhDHugG5Yr.png)

3. 自适应哈希索引（adpative hash index)

InnoDB是B+树索引，不支持hash索引（优点是支持快速等值查询）

![image-20220217153650897](https://s2.loli.net/2022/02/17/NgFrcV8iAdjzXfZ.png)

4. `log Buffer`(日志缓冲区)

![image-20220217154103284](https://s2.loli.net/2022/02/17/GafQYZk9ENIwoLl.png)

## p79 InnoDB引擎-架构-磁盘架构

系统表空间、 每张表的独立表空间。

![image-20220217155614811](https://s2.loli.net/2022/02/17/cEYgRxSLIhDfH6k.png)

通用表空间（手动创建，指定表空间）、撤销表空间、临时表空间

![image-20220217155731678](https://s2.loli.net/2022/02/17/yxsteEZHXg9I2Tc.png)

双写缓冲区、**重做日志(事务持久性)**

![image-20220217160637776](https://s2.loli.net/2022/02/17/krOL37inCxKFAha.png)

## p80 InnoDB引擎-架构-后台线程

后台线程：用来将数据从内存刷新到磁盘中。

![image-20220217161007711](https://s2.loli.net/2022/02/17/exH9NkrRl8wmUoS.png)

## p81 InnoDB引擎-事务原理-概述

**事务**：是一组操作的集合，它是一个不可分割的工作单位，事务会把所有的操作作为一个整体一起向系统提交或撤销操作请求，即这些操作要么**同时成功**，要么**同时失败**；

事务四大特性

![image-20220215000807130](https://s2.loli.net/2022/02/17/lzP4f7p5vuOUNJd.png)

注意理解掌握。

- **事务原理**

> 原子性、一致性、持久性：依赖于redo.log、undo.log
>
> 隔离性：依赖于锁机制和mvcc(版本并发控制)

## p82 InnoDB引擎-事务原理-redolog

redo log(重做日志）**保证事务的持久性**

其记录的是事务提交时数据页的物理修改，用来实现事务的持久性。

该日志文件由 **重做日志缓冲（redo log buffer)和重做日志文件(redo log file)**两部分组成，前者在内存中，后者在磁盘中。当事务提交之后会把所有修改信息都存到该日志文件中，**用于在刷新脏页到磁盘，发生错误时，进行数据恢复使用**。

> 更新数据时，首先将增删改操作记录在redolog buffer中，事务提交后，redolog buffer刷新到磁盘中，持久化保存在磁盘文件之中，过一段时间进行脏页刷新时，可以通过redolog来进行恢复。
>
> 为什么每次刷新的时候要将redolog buffer直接刷新到磁盘中，直接将buffer pool中变更的数据刷新到磁盘中不行吗？
>
> 答：可以这么做，但是严重性能问题，事务中操作随机操作记录页，会涉及大量随机磁盘IO。log 日志文件刷新的时候是追加顺序刷新的，顺序磁盘IO，性能由于随机磁盘IO。**这种机制叫做WAL(write-Ahead logging)先写日志**。
>
> 脏页数据顺利刷新到磁盘中，redolog日志不需要，会隔一段时间清理日志，即会循环写。

![image-20220217164521797](https://s2.loli.net/2022/02/17/3PML6O2WIpfs5vT.png)

## p83 InnoDB引擎-事务原理-undolog

`undo log` **解决事务的原子性**----**当执行失败需要回滚时依赖于undo log进行回滚**还有**MVCC**

物理日志：主要记录数据内容；逻辑日志：每一步的数据操作。

事务提交或者回滚成功之后不需要undolog，但会去检查MVCC；

段存储，回滚段(内部包含1024个undo log段)

![image-20220217164830011](https://s2.loli.net/2022/02/17/ndkcS7o1GCNzyJV.png)

## P84 InnoDB引擎-MVCC-概念

- 当前读

读取的时记录的最新版本，读取时还要保证其他并发事务不能修改当前记录，会对读取的记录进行加锁。对于

`select ... lock in share mode(共享锁),select... for update、update、insert、delete(排他锁)`都是一种当前读。

```sql
 -- 客户端1
 mysql> begin;
Query OK, 0 rows affected (0.00 sec)

-- 这个地方为快照读，后续读的时候，查的都是这个快照数据
mysql> select * from tb_user;
+----+--------+------+--------+------------+------+
| id | name   | age  | gender | phone      | java |
+----+--------+------+--------+------------+------+
|  1 | vav    |   34 | 1      | 2432352525 | NULL |
|  2 | tom    |   34 | 2      | 324252552  | NULL |
|  3 | Php    |   36 | 1      | 34252365   | NULL |
|  4 | gag    |   34 | 2      | 245263763  | NULL |
|  6 | 关巡航 |   36 | 1      | NULL       | NULL |
|  8 | 关羽   |   34 | 1      | NULL       | NULL |
+----+--------+------+--------+------------+------+
6 rows in set (0.00 sec)

-- 客户端2
mysql> begin;
Query OK, 0 rows affected (0.00 sec)

mysql> update tb_user set name = 'jsp' where id  = 1;
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

-- 客户端1 MySQL默认事务隔离级别为可重复读，数据还没改变
mysql> select * from tb_user;
+----+--------+------+--------+------------+------+
| id | name   | age  | gender | phone      | java |
+----+--------+------+--------+------------+------+
|  1 | vav    |   34 | 1      | 2432352525 | NULL |
|  2 | tom    |   34 | 2      | 324252552  | NULL |
|  3 | Php    |   36 | 1      | 34252365   | NULL |
|  4 | gag    |   34 | 2      | 245263763  | NULL |
|  6 | 关巡航 |   36 | 1      | NULL       | NULL |
|  8 | 关羽   |   34 | 1      | NULL       | NULL |
+----+--------+------+--------+------------+------+
6 rows in set (0.00 sec)

-- 客户端2 
mysql> commit;
Query OK, 0 rows affected (0.01 sec)

-- 客户端1 事务B提交之后，MySQL默认事务隔离级别为可重复读，数据还没改变
mysql> select * from tb_user;
+----+--------+------+--------+------------+------+
| id | name   | age  | gender | phone      | java |
+----+--------+------+--------+------------+------+
|  1 | vav    |   34 | 1      | 2432352525 | NULL |
|  2 | tom    |   34 | 2      | 324252552  | NULL |
|  3 | Php    |   36 | 1      | 34252365   | NULL |
|  4 | gag    |   34 | 2      | 245263763  | NULL |
|  6 | 关巡航 |   36 | 1      | NULL       | NULL |
|  8 | 关羽   |   34 | 1      | NULL       | NULL |
+----+--------+------+--------+------------+------+
6 rows in set (0.00 sec)

-- 但是采用当前读，可以看到最新的数据
mysql> select * from tb_user lock in share mode;
+----+--------+------+--------+------------+------+
| id | name   | age  | gender | phone      | java |
+----+--------+------+--------+------------+------+
|  1 | jsp    |   34 | 1      | 2432352525 | NULL |
|  2 | tom    |   34 | 2      | 324252552  | NULL |
|  3 | Php    |   36 | 1      | 34252365   | NULL |
|  4 | gag    |   34 | 2      | 245263763  | NULL |
|  6 | 关巡航 |   36 | 1      | NULL       | NULL |
|  8 | 关羽   |   34 | 1      | NULL       | NULL |
+----+--------+------+--------+------------+------+
6 rows in set (0.00 sec)
```

- 快照读

简单的select(不加锁)就是快照读，读取的是记录数据的可见版本，有可能是历史数据，不加锁，**是非阻塞读**。

1. read committed : 每次select，都会生成一个快照读。
2. repeatable read:开启事务后第一个select语句才是快照读的地方
3. Serializable：快照读会退化为当前读。

- MVCC

多版本并发控制。指维护一个数据的多个版本，使得读写操作没有冲突，快照读为MySQL实现MVCC提供了一个非阻塞读功能。MVCC的具体实现，还需要依赖于数**据库记录的三个隐式字段、undo log日志、readView**。

## P85 InnoDB引擎-MVCC-隐藏字段

- 记录中得隐藏字段

![image-20220217172101744](https://s2.loli.net/2022/02/17/SMsJzTn7C1geQoc.png)

```sql
-- 查看字段
ibd2sdi xxx.ibd
```

## P86 InnoDB引擎-MVCC-undo log版本链

- undo log

1. 回滚日志，在insert、update、delete的时候产生的便于数据回滚的日志。
2. 当insert的时候，产生的undo log日志只在回滚时需要，在事务提交后，可被立即删除
3. 而update、delete的时候，产生的undo log日志不仅在回滚时需要，在快照读时也需要，不会立即删除。

- undo log 版本链

![image-20220217174036290](https://s2.loli.net/2022/02/17/WNFJHBblSZGVD4M.png)

## P87 InnoDB引擎-MVCC-readview介绍

- readview

Readview(读视图)是快照读SQL执行时MVCC提取数据的依据，记录并维护系统当前活跃的事务(未提交的)id.

包含四个核心字段：

![image-20220217174430702](https://s2.loli.net/2022/02/17/BDjUH2t6FlWi5ep.png)

![image-20220217174824257](https://s2.loli.net/2022/02/17/piNIcExzDP2raHG.png)

`trx_id`: 当前undo log记录对应的当前事务id。

## P88 InnoDB引擎-MVCC-原理分析（RC级别）

- readview

**RC隔离级别下，在事务每一次执行快照读时生成ReadView。**

![image-20220217200820267](https://s2.loli.net/2022/02/17/yA7LuVdgc2DbriM.png)

当执行事务5的第二条查询时，快照读的readview如图所示。

![image-20220217210444229](https://s2.loli.net/2022/02/17/U9B158vpKZfObhn.png)

## P89 InnoDB引擎-MVCC-原理分析（RR级别）

**RR隔离级别下，仅仅事务中第一次执行快照读时生成ReadView，后续复用ReadView.**

![image-20220217210845703](https://s2.loli.net/2022/02/17/WkDE5UH42YrxeT7.png)

这种情况下事务5中的第二个查询复用第一个查询时产生的readview，**因此这种隔离级别下是可重复读的**。



redo log -------------->**持久性**

undo log -------------->**原子性**

[隐藏字段+undo log版本链 + readview --------->**MVCC] + 锁** ------------->**隔离性**

**一致性**：数据在执行之前和执行之后是一致的，若事务失败要回滚，保证数据前后一致；若事务正常提交，要保证数据是更新之后的数据，这是由 redo log 和 undo log共同保证的。

## P90 InnoDB引擎-小结

1. 逻辑存储结构

> 表空间 、段、区、页、行
>
> - 一个区的大小是1M，一个页大小16K，一个区包含64个连续的页
> - InnoDB引擎为了保证页的连续性，每次从磁盘申请4-5个区。

2. 架构

> 内存结构
>
> - 缓冲区(服务器中80%的空间)
>
> 磁盘结构
>
> - 表空间、redo log、双写缓冲文件

3. 事务原理

> 原子性 --- undo log
>
> 持久性 --- redo log
>
> 一致性 --- undo log  + redo log
>
> 隔离性 ---MVCC + 锁

4. MVCC

> 作用：快照读的时候，查询对应的历史版本
>
> 记录隐藏字段(事务ID+回滚指针）、undo log 版本链、readview(四个核心字段)

## p91 MySQL管理-系统数据库介绍

系统数据库

MySQL安装完成之后，自带了四个数据库，具体作用如下：

![image-20220217214910498](https://s2.loli.net/2022/02/17/94dKTfenXCFAl8v.png)

## p92&93 MySQL管理-常用工具

- mysql

![image-20220217215051311](https://s2.loli.net/2022/02/17/u62jHJcMBeYXPwQ.png)

```sql
zzc@VM-4-14-ubuntu ~ % sudo mysql -h 110.42.251.37 -P3306 -uroot -p1234 itcast -e "select * from tb_user"                                                  [1]
mysql: [Warning] Using a password on the command line interface can be insecure.
+----+--------+------------------+------------+------+--------+--------+------------+--------+
| id | name   | email            | profession | age  | gender | status | createtime | phone  |
+----+--------+------------------+------------+------+--------+--------+------------+--------+
|  1 | 吕布   | 12131414@134.com | 软件       |   19 | 1      |      6 | 2001-02-02 | 121314 |
+----+--------+------------------+------------+------+--------+--------+------------+--------+
```

- mysqladmin

![image-20220217215743127](https://s2.loli.net/2022/02/17/JIPlXx7fiayzUGM.png)

```sql
zzc@VM-4-14-ubuntu ~ % sudo mysqladmin -uroot -p1234 version                                        [1]
mysqladmin: [Warning] Using a password on the command line interface can be insecure.
mysqladmin  Ver 8.0.27-0ubuntu0.20.04.1 for Linux on x86_64 ((Ubuntu))
Copyright (c) 2000, 2021, Oracle and/or its affiliates.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Server version          8.0.27-0ubuntu0.20.04.1
Protocol version        10
Connection              Localhost via UNIX socket
UNIX socket             /var/run/mysqld/mysqld.sock
Uptime:                 2 days 2 hours 51 min 5 sec

Threads: 2  Questions: 143  Slow queries: 0  Opens: 230  Flush tables: 3  Open tables: 142  Queries per second avg: 0.000
```

- mysqlbinlog

![image-20220217220209617](https://s2.loli.net/2022/02/17/mGsCQVi1cLo28UF.png)

- mysqlshow

![image-20220217220719417](https://s2.loli.net/2022/02/17/ySPBGQxXvlnUpiM.png)

```sql
root@VM-4-14-ubuntu:/var/lib/mysql# mysqlshow -uroot -p1234 --count
mysqlshow: [Warning] Using a password on the command line interface can be insecure.
+--------------------+--------+--------------+
|     Databases      | Tables |  Total Rows  |
+--------------------+--------+--------------+
| information_schema |     79 |        26300 |
| itcast             |      1 |            1 |
| mydb               |      1 |            4 |
| mysql              |     37 |         3907 |
| performance_schema |    110 |       249762 |
| sys                |    101 |         5177 |
+--------------------+--------+--------------+
6 rows in set.
root@VM-4-14-ubuntu:/var/lib/mysql# mysqlshow -uroot -p1234 --count itcast
mysqlshow: [Warning] Using a password on the command line interface can be insecure.
Database: itcast
+---------+----------+------------+
| Tables  | Columns  | Total Rows |
+---------+----------+------------+
| tb_user |        9 |          1 |
+---------+----------+------------+
1 row in set.
```

- mysqldump

![image-20220217221301551](https://s2.loli.net/2022/02/17/W6HzanYGipUwh2c.png)

- mysqlimport/soure

![image-20220217221848302](https://s2.loli.net/2022/02/17/m8IbgEvZP4jGwYl.png)

## p94MySQL管理-小结

mysql、mysqladmin(MySQL管理工具)、mysqlbinlog(二进制日志查看工具)、mysqlshow(查看数据库、表、字段的统计信息)

mysqldump(数据备份工具)、mysqlimport/source(数据导入工具)

## p95进阶篇总结

- 存储引擎(innodb和myisAM区别)
- **索引(数据结构，分类、操作语法、设计原则)**
- SQL优化(索引使用原则，order by 、group by、limit优化、索引优化)
- 视图、存储过程、触发器
- 锁(全局锁、表级锁()、行级锁(行锁、间隙锁、next-key lock))
- InnoDB引擎(存储结构、架构、支持事务，事务实现原理、MVCC)
- MySQL管理工具