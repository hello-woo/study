

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