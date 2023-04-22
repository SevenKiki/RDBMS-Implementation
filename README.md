# RDBMS-Implementation
关系型数据库原型系统实现
SevenKiki
## 系统构建安装
在命令行按照以下步骤进行输入
> cd /to/RDBMS/root_dir
> cd build
> cmake ..
> make -j
> sudo make install # 将rdbms_app安装到/usr/local/bin

## 系统设计方案
### 系统功能模块
本系统是一个简单的关系型数据库原型系统，采用 Visual Studio Code 2019作为开发平台，完成数据库管理系统的设计，实现了对模式、表格、数据库的常规管理及操作。
采用模块化的设计思想，大大提高了系统开发效率，并且最大限度减少错误。在对系统功能分析的基础上，应用模块化设计思路，得到下图所示的关系型数据库原型系统的功能模块图。
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674265001621-d57cfcb0-ba53-43bf-9b70-6e46c80a310a.png#averageHue=%23e8edf6&clientId=u9a3f2234-4eb1-4&from=paste&height=555&id=u5033d8f6&name=image.png&originHeight=1110&originWidth=1678&originalType=binary&ratio=1&rotation=0&showTitle=false&size=175359&status=done&style=none&taskId=u872d7fd0-754c-4e16-b2ba-4a3baecef57&title=&width=839)
### 系统目录结构
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674266382517-a76bd683-4ff1-44f2-83f5-49d975f682db.png#averageHue=%23fefefe&clientId=u9a3f2234-4eb1-4&from=paste&height=587&id=WpQhv&name=image.png&originHeight=1174&originWidth=1128&originalType=binary&ratio=1&rotation=0&showTitle=false&size=127045&status=done&style=none&taskId=uc9d11995-3fe7-4497-a9a8-5811f2531f5&title=&width=564)
## 关键技术与实现
### 算子实现
在本系统中实现了表上的6个算子 Union、Intersection、Difference、Projection、Selection、Natural Join。
> 主要文件：
> rdbms/operations/operation.hpp
> rdbms/operations/operation.cpp

1. runion<table R1, table R2>
   1. 功能：在两表上进行union操作
   2. 实现：将两个表的数据添加到一个新表
```
R1 U R2 = {(a1,...,an) | (a1,...,an) E R1 V (a1,..,an) E R1}
```

2. intersection<table R1, table R2>
   1. 功能：在两个表上进行intersection操作
   2. 实现：当表中元组在两个表中都存在，将元组插入到新表中
```
R1 n R2 = {(a1,...,an) | (a1,..,an) E R1 & (a1,..,an) E R2 }
```

3. difference<table R1, table R2>
   1. 功能：在两表上进行difference操作
   2. 实现：当表中元组只存在本表，而不存在另外一个表中时，将元组插入到新表中
```
R1 - R2 = {(a1,...,an) | (a1,..,an) E R1 & ~((a1,..,an) E R2)}
```

4. projection<table R1, string P>
   1. 功能：在表R1中映射P对应属性值
   2. 实现：当P匹配某一个属性名时，将该属性所有值插入到新表中
```
Pi(A1,A2,......,An) R1 = {(a1,.....,an)| (b1,....,bn) E R1 ^ (a1 = b1,....am = bm)}
```

5. selection<table R1, string A, string S>
   1. 功能：在表R1中筛选出属性A的值为S的元组
   2. 实现：当P匹配表中某一个属性名，且S匹配该属性中某一个值时，将该元组插入到新表中
```
Tproposition (R1) = {(a1,a2,......an)|(a1,a2,.....an) E R1 ^ (proposition)}
```

6. natural_join<table R1, table R2, string id1, string id2, string A1, string A2>
   1. 功能：连接两表 
   2. 实现：如果关系R1与R2具有相同的属性组B，且该属性组的值相等时的连接，结果关系的属性集合为R1的属性并上R2减去属性B的属性集合
```
R1 |X| R2 = Pi(a1,a2,...an)|(a1,a2,.....an) E R1 ^ (a1,a2,.....an) E R2 ^ (T R1.A1 = R2.A2 = ...= Rn.An)
```
### 元组管理——tuple类
> 主要文件：
> rdbms/util/tuples.hpp
> rdbms/util/tuples.cpp

- 使用cell类存储元组中的每个属性值
- 使用STL set容器存储tuple的cells set<set<cell,cellComparator> > elements，优势为：set的底层实现是基于**红黑树**，加入set的所有元素会依据元素的键值自动被排序，加快查找速度，set不允许两个元素有相同的元素，这也符合表中不能有两个相同的元组这一原则
### 表管理——table 类
> 主要文件：
> rdbms/operations/table.hpp
> rdbms/operations/table.cpp

表类是一种使用n元关系存储数据的关系数据模型
```
R = {(a1,...,an) | a1 E A1 ,a2 E A2, ...,an E An}
```
其中

- 表是一个关系
- 每一行是一个n元组
- **co**lumns（属性）来自一个已定义的Domain，每个属性都有一个唯一的属性名
### 模式管理——rschema类
> 主要文件：
> rdbms/operations/rschema.hpp
> rdbms/operations/rschema.cpp

一个关系型模式包含表名和属性名，一个关系实例是一组用预定义模式创建的有限元组。示例如下，这是一个关系模式，其中表名是student, 属性有name、Age和Departmen。
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674269880920-38cf0f2f-c552-4e97-bd4a-ce4f39399855.png#averageHue=%23fefefe&clientId=u9a3f2234-4eb1-4&from=paste&height=95&id=u622f2c9c&name=image.png&originHeight=190&originWidth=632&originalType=binary&ratio=1&rotation=0&showTitle=false&size=19538&status=done&style=none&taskId=ud9207341-6e9f-406a-9f60-a867e05468f&title=&width=316)
基于该模式，可以创建一个名为student_info的表，如下图所示：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674269928840-7b75d7a2-f119-445c-a4c2-850c687cac7b.png#averageHue=%23f1f1f2&clientId=u9a3f2234-4eb1-4&from=paste&height=212&id=u29615534&name=image.png&originHeight=424&originWidth=646&originalType=binary&ratio=1&rotation=0&showTitle=false&size=50088&status=done&style=none&taskId=u07994be9-7ff6-49f0-a491-e2dc4698611&title=&width=323)
## 用户界面命令与测试截图
**以下命令支持从RDBMS命令行使用，本节使用一个简单的学生系统作为测试示例,展示了输出截图。为了与平时实验衔接，在下一节还测试了个人通信薄用例**

1. 给定模式名称、属性列表，新建一个关系型模式

**create rschema <rschema name> <list of column names>**
> e.g: create rschema ID Name ID-num
> 其中 ID 是模式名，Name， ID-num是属性

其他例子：
> create rschema Attendance ID-num Number-of-present
> create rschema Contact Name Email
> create rschema Grade ID-num Points

输出截图：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674274845478-0712681d-f3ac-4fbd-8bbc-7bd58b5e882e.png#averageHue=%23f8f8f8&clientId=u9a3f2234-4eb1-4&from=paste&height=44&id=u2f32b72d&name=image.png&originHeight=88&originWidth=1252&originalType=binary&ratio=1&rotation=0&showTitle=false&size=14307&status=done&style=none&taskId=u7be6b92a-5d89-4870-8971-880a12211e9&title=&width=626)

2. 给定表名、关系型模式，新建一个空表

**create table <table name> <name of rschema>**
> e.g:create table Student ID

其他例子：
> create table Training-attendance Attendance 
> create table Training-grade Grade  
> create table Students-contact Contact  
> create table Team-leader ID

输出截图：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674274932846-ac0920ae-c5d1-4a3d-9a01-2d1fc9e0810e.png#averageHue=%23f8f8f8&clientId=u9a3f2234-4eb1-4&from=paste&height=46&id=ud2b945b7&name=image.png&originHeight=92&originWidth=1246&originalType=binary&ratio=1&rotation=0&showTitle=false&size=14512&status=done&style=none&taskId=uaa8dd901-87ef-476a-89ca-a1d0bc3f8fd&title=&width=623)

3. 给定表名、csv文件路径，将文件导入到表中（追加模式）

**copy <table name， string filepath>**
> e.g: copy student /Users/yuki/Desktop/student

4. 在现有表中插入一行数据

**insert <table name> <row to insert>**
> e.g: insert Student Kirub G1T31

输出截图：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674275004108-62d816ca-5844-4356-97e3-aec97656ab43.png#averageHue=%23f4f4f4&clientId=u9a3f2234-4eb1-4&from=paste&height=47&id=u6dc4cb2d&name=image.png&originHeight=94&originWidth=772&originalType=binary&ratio=1&rotation=0&showTitle=false&size=13807&status=done&style=none&taskId=u548f9b80-4b27-4ce0-94e5-b7c77ed9a6e&title=&width=386)

5. 在现有表中删除一行数据

**remove row <table name> <row to remove>**
> remove row Student Kirub G1T31

输出截图：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674275101565-cf863530-a0a7-47a7-8fe0-a86633be8db0.png#averageHue=%23f6f6f6&clientId=u9a3f2234-4eb1-4&from=paste&height=45&id=pgjgi&name=image.png&originHeight=90&originWidth=1130&originalType=binary&ratio=1&rotation=0&showTitle=false&size=15817&status=done&style=none&taskId=ue6fcb855-a88c-461a-bffc-8bd3a7a59c4&title=&width=565)

6. 给定表名，显示表中所有数据

**display <table name>**
> display Student

输出： 
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674275186321-42baee97-dd91-43d5-9a79-58e5cca0d81e.png#averageHue=%23f9f9f9&clientId=u9a3f2234-4eb1-4&from=paste&height=116&id=uad2cfe0b&name=image.png&originHeight=232&originWidth=1120&originalType=binary&ratio=1&rotation=0&showTitle=false&size=30414&status=done&style=none&taskId=ub0a9d98d-3f8d-4542-a596-3fc250e12f5&title=&width=560)

7. 删除现有表

**remove table <table name>**
> remove table Student

输出：

8. 给定两个表名，进行intersect

**intersect <first table name> <second table name>**
> intersect Student Team-leader

输出：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674275207501-29f5f5cf-327d-4e05-a921-51cb24f167d4.png#averageHue=%23f8f8f8&clientId=u9a3f2234-4eb1-4&from=paste&height=78&id=u59134453&name=image.png&originHeight=156&originWidth=706&originalType=binary&ratio=1&rotation=0&showTitle=false&size=15161&status=done&style=none&taskId=ua67f5527-c902-4b21-b6fb-2256f565eed&title=&width=353)

9. 给定两个表名，进行union 

**union <first table name> <second table name>**
> union Student Team-leader

输出：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674275244215-1d091b3e-db0d-4bc2-8edf-99ebcd90da07.png#averageHue=%23f6f6f6&clientId=u9a3f2234-4eb1-4&from=paste&height=320&id=ufc08ece3&name=image.png&originHeight=640&originWidth=758&originalType=binary&ratio=1&rotation=0&showTitle=false&size=72776&status=done&style=none&taskId=u88211c58-3745-4ce3-93f8-e836aaad243&title=&width=379)

10. 给定两个表名，进行difference

**difference <first table name> <second table name>**
> difference Student Team-leader

输出：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674275273350-626327fe-c823-48fd-bb20-4a152dab3e9d.png#averageHue=%23f3f3f3&clientId=u9a3f2234-4eb1-4&from=paste&height=301&id=u7654783e&name=image.png&originHeight=602&originWidth=546&originalType=binary&ratio=1&rotation=0&showTitle=false&size=61362&status=done&style=none&taskId=u87239764-5a8e-4aa8-9b5e-2e9b0bb2178&title=&width=273)

11. 给定一个表名、需要映射的属性列表，进行Projection

**project <table name> <list of column names>**
> project Students-contact Email

输出：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674275290713-af403d1e-0bcc-4bc3-9dbc-d87cd0c4b204.png#averageHue=%23f4f4f4&clientId=u9a3f2234-4eb1-4&from=paste&height=119&id=u5ec40b3b&name=image.png&originHeight=238&originWidth=608&originalType=binary&ratio=1&rotation=0&showTitle=false&size=27648&status=done&style=none&taskId=ue6bc4e5e-2bd2-46be-95f1-1dc126bd251&title=&width=304)

12. 给定一个表名、属性名、具体的值，进行select

**select <table name> <column name> <value>**
> select Training-grade ID-num G1T32

输出：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674275343765-04402a8f-7a04-4727-9f41-8e048a1d9893.png#averageHue=%23f7f7f7&clientId=u9a3f2234-4eb1-4&from=paste&height=162&id=u5bbc2d1a&name=image.png&originHeight=324&originWidth=634&originalType=binary&ratio=1&rotation=0&showTitle=false&size=28613&status=done&style=none&taskId=u9d0cf046-0842-4b7b-9008-c3ae36387a7&title=&width=317)

13. 给定两个表名，两个属性名，两个连接属性名，进行natural join

**njoin <table1 name> <table2 name> <comp1> <comp2> <joining atribute from the 1st table> <joining atribute from the second table>**
> Njoin Student Training-attendance ID-num ID-num Name Number-of-present

输出：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674275429097-3cda8d81-eaea-4415-82e5-0e9876c37a9b.png#averageHue=%23f4f4f4&clientId=u9a3f2234-4eb1-4&from=paste&height=102&id=u4aa0ac9f&name=image.png&originHeight=204&originWidth=618&originalType=binary&ratio=1&rotation=0&showTitle=false&size=23771&status=done&style=none&taskId=uea8c1546-1e3c-4386-8264-1631beae65b&title=&width=309)

14. 查询数据库中的所有关系模式、表的元数据
> database

输出：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674275488576-ffcef63a-99a7-48f0-b85f-a18873461b0d.png#averageHue=%23fafafa&clientId=u9a3f2234-4eb1-4&from=paste&height=565&id=u883ea23a&name=image.png&originHeight=1130&originWidth=934&originalType=binary&ratio=1&rotation=0&showTitle=false&size=90855&status=done&style=none&taskId=ubb8ed9fd-2a49-4c99-bdaa-02eb509b97a&title=&width=467)

15. 清屏
> cls

16. 退出程序
> exit

### 个人通信薄测试截图

1. 创建通信薄模式 addressbook

create rschema addressbook id name address email resume
测试截图：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674276443374-909cd49c-910a-4d7f-8d7f-3fd98a938aa9.png#averageHue=%23f1f1f1&clientId=u9a3f2234-4eb1-4&from=paste&height=45&id=u8b0c5a98&name=image.png&originHeight=90&originWidth=1040&originalType=binary&ratio=1&rotation=0&showTitle=false&size=15913&status=done&style=none&taskId=ucf9f87c3-13c9-4eb9-b53a-12a20f8fd5c&title=&width=520)

2. 由通信薄模式创建表 ab

create table ab addressbook
测试截图：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674276492041-4e8fa0f5-44fa-4463-b29d-81ca7ae84c31.png#averageHue=%23ededed&clientId=u9a3f2234-4eb1-4&from=paste&height=30&id=lNN2r&name=image.png&originHeight=60&originWidth=632&originalType=binary&ratio=1&rotation=0&showTitle=false&size=10896&status=done&style=none&taskId=u68dfcee9-ed40-4e90-bb08-df40d953841&title=&width=316)

3. 显示表ab

display ab
测试截图：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674276576875-cbc13061-112a-45ce-9844-810b074b0ae3.png#averageHue=%23f4f4f4&clientId=u9a3f2234-4eb1-4&from=paste&height=60&id=u0b570896&name=image.png&originHeight=120&originWidth=692&originalType=binary&ratio=1&rotation=0&showTitle=false&size=14792&status=done&style=none&taskId=uc8074cfc-c290-4f56-ab4a-ba4847d9588&title=&width=346)

4. 从csv文件导入数据

copy ab /Users/yuki/Desktop/addressbook.csv
测试截图：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674276623880-78dd5e73-27bd-44e5-92af-2b51585634a1.png#averageHue=%23e7e7e7&clientId=u9a3f2234-4eb1-4&from=paste&height=191&id=u09a51f8f&name=image.png&originHeight=382&originWidth=902&originalType=binary&ratio=1&rotation=0&showTitle=false&size=62682&status=done&style=none&taskId=u3f6fc689-995c-4145-bf59-030b44d17f2&title=&width=451)

5. 插入新数据

insert ab 11 tom11 address11 email11 resume11111111111111
insert ab 12 tom12 address12 email12 resume11111111111111
测试截图：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674277187578-c9a0fd16-9def-4d78-8173-8a6c30b90a7e.png#averageHue=%23efefef&clientId=u9a3f2234-4eb1-4&from=paste&height=82&id=ud5f93bb2&name=image.png&originHeight=164&originWidth=918&originalType=binary&ratio=1&rotation=0&showTitle=false&size=23464&status=done&style=none&taskId=u93fc21b2-6a21-4f3b-a192-c05f5cbcb47&title=&width=459)

6. 删除刚插入的一条数据

remove row ab 2 tom12 address12 email12 resume11111111111111
测试截图:
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674277338169-bc110a22-7a0c-4bd2-9875-be44020d212c.png#averageHue=%23eaeaea&clientId=u9a3f2234-4eb1-4&from=paste&height=271&id=u516df354&name=image.png&originHeight=542&originWidth=952&originalType=binary&ratio=1&rotation=0&showTitle=false&size=85827&status=done&style=none&taskId=u2889d3bf-b226-42c6-bf39-ec65b6dda12&title=&width=476)

7. 显示database

database
测试截图：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674277375556-6389eaa0-ef44-470e-be8c-3a5f8243dcdc.png#averageHue=%23f8f8f8&clientId=u9a3f2234-4eb1-4&from=paste&height=208&id=u002d0759&name=image.png&originHeight=416&originWidth=820&originalType=binary&ratio=1&rotation=0&showTitle=false&size=33551&status=done&style=none&taskId=u1c59ac5f-3939-433d-b6ce-72d6b8dea76&title=&width=410)

8. select * from ab where ab.name = tom8

select ab name tom8
测试截图：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674277945643-603e820f-0f1b-4430-9a55-7cea1709e7cd.png#averageHue=%23f7f7f7&clientId=u9a3f2234-4eb1-4&from=paste&height=76&id=u218caaf4&name=image.png&originHeight=152&originWidth=964&originalType=binary&ratio=1&rotation=0&showTitle=false&size=16733&status=done&style=none&taskId=u9629145c-bd43-4c5b-87ce-80237fe187f&title=&width=482)

9.  select * from ab where ab.email = email8

select ab email email8
测试截图：
![image.png](https://cdn.nlark.com/yuque/0/2023/png/12955952/1674278050280-0422731b-c6c2-4533-8fdb-fa9dd5ee0de2.png#averageHue=%23f5f5f5&clientId=u9a3f2234-4eb1-4&from=paste&height=78&id=ua0e9fdf2&name=image.png&originHeight=156&originWidth=782&originalType=binary&ratio=1&rotation=0&showTitle=false&size=16255&status=done&style=none&taskId=u5de6b2bc-605c-4175-83fc-e3165a860c4&title=&width=391)

## 未来工作与体会
### 体会
#### 数据定义
在原型系统的设计阶段，我意识到之前三个实验都有一个明显缺陷——表的结构无法自定义，也就是说，表的属性个数、属性类型、属性名称在系统实现时就已经固定，比如在实验三中固定通信薄的结构如下， 这样的数据库系统只能运用用于个人通信薄，如何让数据库系统可以满足自定义的表结构？
```
struct addressbook{
    int ab_size;             //record size in bytes
    int ab_personkey;       //主键值
    char ab_phonenum;		//手机号
    char ab_name[25];       //人名
    char ab_address[50];    //地址
    char ab_email[25];      //邮箱
    int resume_len;        //变长个人简历
    char ab_resume[0];
};
```
对于这个问题，我在本原型系统解决方法是：

- 定义模式，在建表前先根据表的属性建立模式
- 指定模式，进行建表
#### 查询解析
数据库查询语句复杂，如何进行查询语句解析？
对于这个问题，我在本原型系统解决方法是：

- 简化查询语句，查询词之间用空格分割，便于解析，减少工作量
- 逐个实现数据库的六个算子（Union、Intersection、Difference、Projection、Selection、Natural Join），调用算子进行查询
#### 加快查询速度
如何加快数据库查询速度？
商业界和学术界通常使用索引来加快查询速度，考虑到索引工作量大、难实现，在本原型系统解决方法是：

- 将表中的所有元组存储在STL set容器中，set容器基于红黑树，能够快速查找元组
- 将元组中的属性值存储在STL set容器中，能够快速查找元组中的属性
#### 用户界面
本原型系统的用户界面良好，主要体现在以下方面：

- 可以安装到系统，在命令行中可直接连接数据库
- 用户界面简洁，键入-help可以获取命令帮助
- 提供清幕指令
- 命令输入错误会有详细提示，以及相关指令帮助
### 未来工作

1. 数据权限管理：使用独立的用户权限表来设计表上的授权访问机制，包括：用户信息和权限的定义、授权和验证；
2. 事务回滚：对简单的事务性故障，能够支持对元组的删除撤销(UNDELETE)；
3. 表的属性个数限制：目前表属性的个数限制为10，未来将扩展表的属性个数；
4. 导入数据的文件格式限制：目前仅支持csv文件导入，未来将支持更多的文件类型；
5. 查询条件： 目前仅支持单表查询，系统中已经实现了连接算子，未来将基于连接算子实现多表查询；
6. 索引结构：目前属于哪个STL set容器加快查询速度，但是会增加空间大小，未来考虑设计索引类，加快查询速度。
