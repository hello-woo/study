# MySQL-运维篇

## p01课程介绍

日志、主从复制、分库分表、读写分离

## p02 日志-错误日志

- 错误日志

记录mysql启动和停止时，以及服务器在运行过程种发生任何严重错误时的相关信息，当数据库出现任何故障导致无法正常使用时，建议首先查看此日志

默认开启，存放目录 `/var/log`，默认日志文件名为mysqld.log，查看日志位置

```sql
show variables like '%log_error%';
```

```sql
mysql> show variables like '%log_error%';
+----------------------------+----------------------------------------+
| Variable_name              | Value                                  |
+----------------------------+----------------------------------------+
| binlog_error_action        | ABORT_SERVER                           |
| log_error                  | /var/log/mysql/error.log               |
| log_error_services         | log_filter_internal; log_sink_internal |
| log_error_suppression_list |                                        |
| log_error_verbosity        | 2                                      |
+----------------------------+----------------------------------------+
5 rows in set (0.00 sec)
```

## p03 日志-二进制日志

- 介绍

二进制日志（binglog）记录了所有得DDL（数据定义语言）语句和DML（数据操纵语言）语句，但不包括数据查询(select、show)语句

作用

1. 灾难时的数据恢复
2. MySQL的主从复制。MySQL8版本中，默认二进制文件日志是开启的

```sql
mysql> show variables like '%log_bin%';
+---------------------------------+-----------------------------+
| Variable_name                   | Value                       |
+---------------------------------+-----------------------------+
| log_bin                         | ON                          |
| log_bin_basename                | /var/lib/mysql/binlog       |
| log_bin_index                   | /var/lib/mysql/binlog.index |
| log_bin_trust_function_creators | OFF                         |
| log_bin_use_v1_row_events       | OFF                         |
| sql_log_bin                     | ON                          |
+---------------------------------+-----------------------------+
6 rows in set (0.00 sec)
```

- 日志格式

![image-20220217230915011](https://s2.loli.net/2022/02/17/yeAnGirctMQY7Hg.png)

```sql
mysql> show variables like '%binlog_format';
+---------------+-------+
| Variable_name | Value |
+---------------+-------+
| binlog_format | ROW   |
+---------------+-------+
1 row in set (0.00 sec)
```

- 日志查看

日志二进制文件，不能直接读取，需要通过二进制日志查询工具mysqlbinlog查看，具体语法

![image-20220217231406669](https://s2.loli.net/2022/02/17/MBvl92dioRJrtNg.png)

```shell
sudo mysqlbinlog -v /var/lib/mysql/binlog.000056 
### UPDATE `itcast`.`tb_user`
### WHERE
###   @1=1
###   @2='吕布'
###   @3='12131414@134.com'
###   @4='软件'
###   @5=19
###   @6='1'
###   @7=6
###   @8='2001:02:02'
###   @9='121314'
### SET
###   @1=1
###   @2='吕布'
###   @3='12131414@134.com'
###   @4='软件'
###   @5=20
###   @6='1'
###   @7=6
###   @8='2001:02:02'
###   @9='121314'
```

- 日志删除

![image-20220217232546652](https://s2.loli.net/2022/02/17/LixRC9V1hWUS2OK.png)

```sql
reset master;
purge master logs to 'binlog.000050';
```

mysql配置文件中配置二进制日志过期的时间，设置之后，二进制日志过期会自动删除

```sql
show variables like '%binlog_expire_logs_seconds%';

mysql> show variables like '%binlog_expire_logs_seconds%';
+----------------------------+---------+
| Variable_name              | Value   |
+----------------------------+---------+
| binlog_expire_logs_seconds | 2592000 |
+----------------------------+---------+
1 row in set (0.00 sec)

```

## p04 日志-查询日志

- 查询日志

查询日志记录了客户端所有操作的语句，而二进制日志不包含查询数据的SQL语句。默认情况下，查询日志是未开启的，如果需要开启查询日志，可以设置

```sql
show variables like '%general%';

mysql> show variables like '%general%';
+------------------+-----------------------------------+
| Variable_name    | Value                             |
+------------------+-----------------------------------+
| general_log      | OFF                               |
| general_log_file | /var/lib/mysql/VM-4-14-ubuntu.log |
+------------------+-----------------------------------+
2 rows in set (0.00 sec)
```

修改MySQL配置文件`/stc/my.cnf文件`，添加以下内容

```sql
general_log = 1 ;-- 0关闭 1开启

#设置日志文件名，默认为host_name.log
general_log_file = mysql_query.log
```

```sql
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| itcast             |
| mydb               |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
6 rows in set (0.00 sec)

mysql> use itcast;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
mysql> show tables;
+------------------+
| Tables_in_itcast |
+------------------+
| tb_user          |
+------------------+
1 row in set (0.00 sec)

mysql> select * from tb_user;
+----+--------+------------------+------------+------+--------+--------+------------+--------+
| id | name   | email            | profession | age  | gender | status | createtime | phone  |
+----+--------+------------------+------------+------+--------+--------+------------+--------+
|  1 | 吕布   | 12131414@134.com | 软件       |   20 | 1      |      6 | 2001-02-02 | 121314 |
+----+--------+------------------+------------+------+--------+--------+------------+--------+
1 row in set (0.00 sec)

mysql> update tb_user set name ='刘备' where id = 1;
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select * from tb_user;
+----+--------+------------------+------------+------+--------+--------+------------+--------+
| id | name   | email            | profession | age  | gender | status | createtime | phone  |
+----+--------+------------------+------------+------+--------+--------+------------+--------+
|  1 | 刘备   | 12131414@134.com | 软件       |   20 | 1      |      6 | 2001-02-02 | 121314 |
+----+--------+------------------+------------+------+--------+--------+------------+--------+
1 row in set (0.00 sec)

mysql> drop table tb_user;
Query OK, 0 rows affected (0.06 sec)

root@VM-4-14-ubuntu:/var/lib/mysql# tail -f VM-4-14-ubuntu.log
2022-02-17T15:38:08.601858Z	   90 Connect	root@localhost on  using Socket
2022-02-17T15:38:08.602313Z	   90 Query	select @@version_comment limit 1
2022-02-17T15:38:14.024108Z	   90 Query	show databases
2022-02-17T15:38:21.039922Z	   90 Query	SELECT DATABASE()
2022-02-17T15:38:21.040064Z	   90 Init DB	itcast
2022-02-17T15:38:21.040857Z	   90 Query	show databases
2022-02-17T15:38:21.041544Z	   90 Query	show tables
2022-02-17T15:38:21.043143Z	   90 Field List	tb_user 
2022-02-17T15:38:25.038920Z	   90 Query	show tables
2022-02-17T15:40:00.092633Z	   90 Query	select * from tb_user
2022-02-17T15:42:12.177936Z	   90 Query	update tb_user set name ='刘备' where id = 1
2022-02-17T15:42:38.896486Z	   90 Query	select * from tb_user
2022-02-17T15:43:54.019711Z	   90 Query	drop table tb_user
```

## p05 日志-慢查询日志

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

## p06 主从复制-概述

- 概述

主从复制是指将主数据库DDL和DML操作通过二进制日志传到从服务器，然后再库上对这些日志重新执行（重做），从而重新使得从库和主库的数据保持同步。

MySQL支持一台主库(master)同时向多台从库(slave)进行复制，从库同时也可以作为其他从服务器的主库，实现链状复制。

MySQL复制的优点主要包含以下三个方面

1. 主库出现问题，可以快速切换到从库提供服务
2. 实现读写分离，降低主库的访问压力，增删改在主库，查询在从库。
3. 可以在从库中执行备份，以避免备份期间影响主库服务，从库中备份（全局锁，可以查）。

## p07 主从复制-原理

- 原理

MySQL主从复制的原理

![image-20220218130234403](https://s2.loli.net/2022/02/18/XkfVrMqNQ35HpxY.png)



## p08主从复制-主库配置

- 服务器准备

主库(matser)ip地址：110.42.251.37 

从库(salve)ip地址：8.130.13.175

以上均开放端口3306

- 主库配置（unbuntu系统)e

1. 修改配置文件 unbuntu系统`/etc/mysql/mysql.cnf`

```sql
#mysql 服务ID，保证集群环境唯一，取值范围1-2^32 - 1，默认为1
server-id = 1
#是否只读，1代表只读。0代表读写
read-only = 0
#忽略的数据。指的是不需要同步的数据库
#binlog-ignore-db = mysql
#指定同步的数据库
#binlog-do-db=db01
```

2. 重启MySQL服务器

```sql
-- unbuntu 系统
sudo service mysql start
sudo service mysql stop
sudo service mysql restart
```

错误信息

```sql
root@VM-4-14-ubuntu:/etc# mysql -uroot -p
mysql: [ERROR] Found option without preceding group in config file /etc/my.cnf at line 1.
mysql: [ERROR] Fatal error in defaults handling. Program aborted!

在/etc/mysql/mysql.cnf 第一行加入[mysqld]
```

3. 登录mysql，创建远程连接账号，并授予主从复制的权限

```sql
#创建itcast用户，并设置密码，该用户可在任意主机连接改MySQL服务
create user 'itcast'@'%'identified with mysql_native_password by 'root@123456';
#为itcast@%用户分配主从复制权限
grant replication slave on *.* to 'itcast'@'%';
```

4. 通过指令，查看二进制日志坐标

```sql
show master status;

mysql> show master status;
+---------------+----------+--------------+------------------+-------------------+
| File          | Position | Binlog_Do_DB | Binlog_Ignore_DB | Executed_Gtid_Set |
+---------------+----------+--------------+------------------+-------------------+
| binlog.000014 |      664 |              |                  |                   |
+---------------+----------+--------------+------------------+-------------------+
1 row in set (0.00 sec)

file :从那个日志文件开始推送日志文件
position:从那个位置开始推送
binlog_ignore_db:不需要同步的库
```

## p09主从复制-从库配置

- 从库配置(centos系统)

1. 修改配置文件`/etc/my.cnf`

```sql
#mysql 服务ID，保证集群环境唯一，取值范围1-2^32 - 1，和主库不一样即可
server-id =2
#是否只读，1代表只读，0代表读写
read-only = 1

super-read-only =1
```

2. 重启MySQL服务器

```sql
systemctl restart mysqld
```

3. 登录mysql，设置主库配置

```sql
change replication source to source_host ='xxx.xxx',source_user='xxx',source_password='xxx',source_log_file='xxx',source_log_pos=xxx;

-- 8.0.23之后
change replication source to source_host ='110.42.251.37',source_user='itcast',source_password='1234',source_log_file='binlog.000014',source_log_pos=664;

-- 8.0.23之前
change master to master_host='110.42.251.37',master_user='itcast',master_password='1234',master_log_file='binlog.000014',master_log_pos=664;

change master to master_host='110.42.251.37',master_user='it',master_password='root@123456',master_log_file='binlog.000014',master_log_pos=3455;
```

![image-20220218211225894](https://s2.loli.net/2022/02/18/w6ouMXhIeq41JGt.png)

4. 开启同步操作

```sql
start replica /8.0.22之后
start slave; /8.0.22之前
```

5. 查看主从同步状态

```sql
show replica status;
show slave status; /8.0.22之前


STOP SLAVE IO_THREAD FOR CHANNEL '' 
```

![](C:/Users/zzc/AppData/Roaming/Typora/typora-user-images/image-20220218213245672.png)

查看日志 `vi /var/log/mysql/mysqld.log`

```sql
2022-02-18T13:30:28.652756Z 9 [ERROR] [MY-013117] [Repl] Slave I/O for channel '': Fatal error: The slave I/O thread stops because master and slave have equal MySQL server ids; these ids must be different for replication to work (or the --replicate-same-server-id option must be used on slave but this does not always make sense; please check the manual before using it). Error_code: MY-013117

[auto]
server-uuid=fc56274c-907f-11ec-806d-00163e012d61
这是因为./etc/my.cnf中要加上[mysqld]在最前面
```

修改之后：

![image-20220218223042085](https://s2.loli.net/2022/02/18/kCtU5e9u6vBgqMS.png)

## p10-主从复制-测试

```sql
 -- 主库
mysql> create database db02;
Query OK, 1 row affected (0.01 sec)

mysql> use db02;
Database changed
mysql> create table tb_user(
    ->     id int auto_increment primary key comment '主键ID',
    ->     name varchar(10) comment '姓名',
    ->     age int comment '年龄',
    ->     gender char(1) comment '1:男，2:女',
    ->     phone char(11) comment '手机号'
    -> )comment '用户基本信息表';
Query OK, 0 rows affected (0.04 sec)

mysql> insert into tb_user values (null,'tb','45','1','2432352525'),
    ->                            (null,'gs',43,'2','324252552'),
    ->                            (null,'gag',25,'1','34252365'),
    ->                            (null,'gag',20,'2','245263763');
Query OK, 4 rows affected (0.01 sec)
Records: 4  Duplicates: 0  Warnings: 0

mysql> show tables;
+----------------+
| Tables_in_db02 |
+----------------+
| tb_user        |
+----------------+
1 row in set (0.01 sec)

mysql> select * from tb_user;
+----+------+------+--------+------------+
| id | name | age  | gender | phone      |
+----+------+------+--------+------------+
|  1 | tb   |   45 | 1      | 2432352525 |
|  2 | gs   |   43 | 2      | 324252552  |
|  3 | gag  |   25 | 1      | 34252365   |
|  4 | gag  |   20 | 2      | 245263763  |
+----+------+------+--------+------------+
4 rows in set (0.00 sec)

-- 从库
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| db02               |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
+--------------------+
5 rows in set (0.00 sec)

mysql> use db02;
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A
Database changed

mysql> select *from tb_user;
+----+------+------+--------+------------+
| id | name | age  | gender | phone      |
+----+------+------+--------+------------+
|  1 | tb   |   45 | 1      | 2432352525 |
|  2 | gs   |   43 | 2      | 324252552  |
|  3 | gag  |   25 | 1      | 34252365   |
|  4 | gag  |   20 | 2      | 245263763  |
+----+------+------+--------+------------+
4 rows in set (0.00 sec)

-- 此时主库执行更新操作
mysql> update tb_user set age = age + 1;
Query OK, 4 rows affected (0.01 sec)
Rows matched: 4  Changed: 4  Warnings: 0

mysql> select * from tb_user;
+----+------+------+--------+------------+
| id | name | age  | gender | phone      |
+----+------+------+--------+------------+
|  1 | tb   |   46 | 1      | 2432352525 |
|  2 | gs   |   44 | 2      | 324252552  |
|  3 | gag  |   26 | 1      | 34252365   |
|  4 | gag  |   21 | 2      | 245263763  |
+----+------+------+--------+------------+
4 rows in set (0.00 sec)

-- 从库
mysql> select *from tb_user;
+----+------+------+--------+------------+
| id | name | age  | gender | phone      |
+----+------+------+--------+------------+
|  1 | tb   |   46 | 1      | 2432352525 |
|  2 | gs   |   44 | 2      | 324252552  |
|  3 | gag  |   26 | 1      | 34252365   |
|  4 | gag  |   21 | 2      | 245263763  |
+----+------+------+--------+------------+
4 rows in set (0.00 sec)
```

## p11 分库分表-介绍

Mycat概述、Mycat入门、Mycat配置、Mycat分片、Mycat管理及监控

- 问题分析

采用单数据库进行数据存储，存在以下性能瓶颈

1. IO瓶颈：热点数据太多、数据库缓存不足，产生大量磁盘IO，效率较低。请求数据太多，带宽不够，网络io瓶颈
2. cpu排序：排序、分组、连接查询、聚合统计等SQL会耗费大量的CPU资源，请求数量太多，CPU出现瓶颈。

分库分表的思想：将数据分散存储，使得单一数据库/表的数据量变小来缓解单一数据库的性能问题，从而达到提升数据库性能的目的

## p12 分库分表-介绍-拆分方式

- 拆分策略

垂直拆分：垂直分库、垂直分表

水平拆分：水平分库、水平分表

分库：对数据库拆分，分表：对表进行拆分。两者粒度不同

- 垂直拆分

![image-20220219130719571](https://s2.loli.net/2022/02/19/3HZCWcd4PYmNwpr.png)

- 水平拆分

![image-20220219131018371](https://s2.loli.net/2022/02/19/dnKUSyMsWlO17cr.png)

- 实现方式

1. shardingJDBC：基于AOP原理，在应用程序中对本地执行的SQL进行拦截，解析、改写、路由处理。需要自行编码配置实现，只支持java语言，性能较高。
2. Mycat：数据库分库分表的中间件，不用调整代码即可实现分库分表，支持多种语言，性能不及前者。

## p13 Mycat概述&安装&核心概念

Mycat伪装协议

![image-20220219132804080](https://s2.loli.net/2022/02/19/xcaobQPVJUiOTlG.png)

不存具体数据，只在逻辑上处理

## p14 分库分表-Mycat入门

![image-20220219133015622](https://s2.loli.net/2022/02/19/zZEfjt63Sa9YonG.png)

![image-20220219133208758](https://s2.loli.net/2022/02/19/Ce7UbvPRB3M5F46.png)

分片规则

`schema.xml`配置

`server.xml`配置

## p15&16分库分表-Mycat入门-测试

Mycat 端口号8806

在mycat中执行增删改

数据怎么分布---分表时要有**分片规则(`rule.xml`）**

rang-long算法

0-5000000 节点1；

5000000-10000000；节点2；

大于10000000为节点3；

## p19&20 Mycat垂直分库

![image-20220219140030666](https://s2.loli.net/2022/02/19/LZXpIrgNw6Hhako.png)

如果两张表在不同服务器上，多表联查会出现问题。**路由**

对于一些通用的表（字典表,对应关系不可变）可以设置为全局表

## p21-分库分表-Mycat分片-水平分表

![image-20220219141728054](https://s2.loli.net/2022/02/19/RqZhkzedXyxF5mN.png)

`id取模分片`分表

## p24- 30分库分表-分片规则

1. 一致性hash算法：

主键为uuid，通过哈希算法分配到指定的服务器上面

一致性哈希：相同的哈希因子计算值总是被划分到相同的分区表中，不会因为分区节点的增加而改变原来数据的分区位置。

**2. 枚举分片**

枚举值，指定数据分布到不同的数据节点上

3. 应用指定

自主决定路由到那个分片，直接根据字符字串（必须为数字）计算分片号

4. 固定分片hash算法

二进制位运算：取id的二进制低10位与1111111111进行位&运算。

5. 字符串哈希解析算法

截取字符串中的指定位置的子字符串，进行hash算法，算出分片

6. 按天分片

7. 按自然月分片

## p31-34分库分表-Mycat管理与监控

- Mycat原理

![image-20220219150311342](https://s2.loli.net/2022/02/19/Y5DO6GA9wS7CMFd.png)

查询语句

![image-20220219150418582](https://s2.loli.net/2022/02/19/TEd6Za92snWHORo.png)

排序，聚合统计都是在MyCat中执行的

Mycat -web监控管理平台；

zookeeper配置中心

## p35 分库分表-总结

分库分表-水平切分、垂直切分

## p36 读写分离-介绍

一主一从、一主一从读写分离、双主双重、双主双重读写分离。

- 介绍

读--从节点；写-主节点

![image-20220219152810768](https://s2.loli.net/2022/02/19/WJlaRZB3Gx4zgIT.png)

## p37 读写分离-一主一从原理

![image-20220219153021384](https://s2.loli.net/2022/02/19/Oexm1R4MJihbflA.png)

## p38-一主一从-读写分离

mycat配置实现

`writehost，readhost`

## p39 双主双从

数据库高可用：一主一从，主节点Master宕机之后，业务系统就只能读，而不能写入数据。

![image-20220219153933771](https://s2.loli.net/2022/02/19/duaEsfp3v48b7zq.png)

## p40 双主双从搭建

![image-20220219154121503](https://s2.loli.net/2022/02/19/ethw8UTyDNYoClH.png)

另一个主库配置和这个类似，但是`server-id=3`

从库配置：

![image-20220219154343238](https://s2.loli.net/2022/02/19/8qWECJFtbNlxsBu.png)

两台主从可以参考上面，两台主库相互关联如下

![image-20220219154635023](https://s2.loli.net/2022/02/19/bRu94qIAf5B82xP.png)

## p41-读写分离-双主双重从读写分离

配置文件

![image-20220219165624325](https://s2.loli.net/2022/02/19/kE1arovw3xLzR5D.png)

![image-20220219170047460](https://s2.loli.net/2022/02/19/H4KCOQlX8ocny5I.png)

## p42 读写分离-总结

1. 介绍

读写分裂是为了降低单台服务器的访问压力，写走主库，读走从库。

2. 一主一从

MySQL主从复制是基于二进制日志binlog实现的。master、slave

3. 一主一从读写分离

4. 双主双从

两台主库，相互复制、互为主备，增强MySQL的可用性

4. 双主双从读写分离

## p43 MySQL总结

1. 日志

> 错误日志、二进制日志、查询日志、慢查询日志(sql满语句)

2. 主从复制
3. 分库分表
4. 读写分离

![image-20220219171414399](https://s2.loli.net/2022/02/19/NDybsq7O34pFrLS.png)