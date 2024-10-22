create table students(
    sno varchar(20) primary key,  --#学号
    sname varchar(20) not null,   --#名字
    ssex varchar(10) not null,    --#性别
    sbirthday datetime,           --#出生日期
    class varchar(20)             --#班级
)character set = utf8;
/* 最后加上character set = utf8可以插入中文（如果本身就可以插入中文的话就没必要加了）
*/
create table teacher(
    tno varchar(20) primary key,   --#教师号
    tname varchar(20) not null,    --#名字
    tsex varchar(10) not null,     --#性别
    tbirthday datetime,            --#出生年月
    prof varchar(20),              --#职位
    depart varchar(20)             --#所在部门
)character set = utf8;

create table course(
    cno varchar(20) primary key,                --#课程号
    cname varchar(20) not null,                 --#课程名称
    tno varchar(20) not null,                   --#授课教师号
    foreign key(tno) references teacher(tno)    --#授课教师号外键关联教师表中的教师号
)character set = utf8;

create table score(
    sno varchar(20) not null,                    --#学生号
    cno varchar(20) not null,                    --#课程号
    degree decimal,                              --#成绩
    foreign key(sno) references students(sno),   --#学生号外键关联学生表中的学号
    foreign key(cno) references course(cno),     --#课程号外键关联课程表中的课程号
    primary key(sno,cno)                         --#联合主键
)character set = utf8;

--往学生表加数据：
insert into students values('101','曾华','男','1977-09-01','95033');
insert into students values('102','匡明','男','1975-10-02','95031');
insert into students values('103','王丽','女','1976-01-23','95033');
insert into students values('104','李军','男','1975-02-10','95033');
insert into students values('105','王芳','女','1974-06-03','95031');
insert into students values('106','陆君','男','1974-06-03','95031');
insert into students values('107','王尼玛','男','1976-02-20','95033');
insert into students values('108','张全蛋','男','1975-02-10','95031');
insert into students values('109','赵铁柱','男','1974-06-03','95031');


--教师表加数据：
insert into teacher values('804','李诚','男','1958-12-02','副教授','计算机系');
insert into teacher values('856','张旭','男','1969-03-12','讲师','电子工程系');
insert into teacher values('825','王萍','女','1972-05-05','助教','计算机系');
insert into teacher values('831','刘冰','女','1977-08-14','助教','电子工程系');

--课程表加数据：
insert into course values('3-105','计算机导论','825');  
insert into course values('3-245','操作系统','804');  
insert into course values('6-166','数字电路','856');
insert into course values('9-888','高等数学','831'); 


--成绩表加数据：
insert into score values('103','3-105','92');   
insert into score values('103','3-245','86');   
insert into score values('103','6-166','85');   
insert into score values('105','3-105','88');   
insert into score values('105','3-245','75');   
insert into score values('105','6-166','79');   
insert into score values('109','3-105','76');   
insert into score values('109','3-245','68');   
insert into score values('109','6-166','81');   
