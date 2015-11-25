# payrollsystem
C++，MFC实现工资管理系统(未使用数据库，使用读写文件)


基本功能要求：
-------
* 以密码登录系统

 <img src="https://github.com/msandroid/payrollsystem/blob/master/screenshot/1.png" alt="Drawing"  /> 
 
* 密码登录时读取文件info.txt(保存员工信息)和Admin.txt(保存管理员息)
* 如果密码错误或者用户账号不存在，会给出相应提示

 <img src="https://github.com/msandroid/payrollsystem/blob/master/screenshot/2.png" alt="Drawing"  /> 
 <img src="https://github.com/msandroid/payrollsystem/blob/master/screenshot/3.png" alt="Drawing"  /> 
 
 

主功能界面
-------
* 菜单布局，对应不同功能

<img src="https://github.com/msandroid/payrollsystem/blob/master/screenshot/4.png" alt="Drawing"  /> 
 
* 录入员工信息具体工资，计算相应的税金（计算规则参见最新公布的政策）

* 查询并显示所有的员工具体信息

* 显示统计信息：员工数目，工资总数和税金总数
 
 <img src="https://github.com/msandroid/payrollsystem/blob/master/screenshot/5.png" alt="Drawing"  /> 

* 按照指定条件查询
 
<img src="https://github.com/msandroid/payrollsystem/blob/master/screenshot/6.png" alt="Drawing"  /> 

* 增删具体员工记录

<img src="https://github.com/msandroid/payrollsystem/blob/master/screenshot/7.png" alt="Drawing"  /> 
 
* 删除 添加
 <img src="https://github.com/msandroid/payrollsystem/blob/master/screenshot/8.png" alt="Drawing"  /> 
员工：
* 以工号为登录ID，密码自己设定；
* 可以查询本人的相关信息；

个人信息菜单中允许查看个人信息并修改密码
<img src="https://github.com/msandroid/payrollsystem/blob/master/screenshot/9.png" alt="Drawing"  /> 
 
注意事项
-------
采用文件系统用来读取信息和存储信息，因此在使用程序的过程中一定要注意相关文件的存储路径和存储格式
说明如下需要使用的文件存储在Demo/res/file文件夹下

 <img src="https://github.com/msandroid/payrollsystem/blob/master/screenshot/10.png" alt="Drawing"  /> 
 
* Admin.txt保存有管理员信息
* Info.txt保存员工基本信息

保存格式
 
 <img src="https://github.com/msandroid/payrollsystem/blob/master/screenshot/11.png" alt="Drawing"  /> 
 
 <img src="https://github.com/msandroid/payrollsystem/blob/master/screenshot/12.png" alt="Drawing"  /> 

关于权限设置
-------
管理员可以使用任意菜单项，但作为普通员工并不能随意修改别人的信息，因此涉及权限问题：
设定普通账号登录后，只开放退出系统，关于软件，个人信息菜单用来查询个人信息和修改密码，

 <img src="https://github.com/msandroid/payrollsystem/blob/master/screenshot/13.png" alt="Drawing"  /> 
 
 <img src="https://github.com/msandroid/payrollsystem/blob/master/screenshot/14.png" alt="Drawing"  /> 
 

至此，所有功能基本完成！由于时间仓促，导致软件还有一定的bug

* 退出软件会弹出报错窗口

* 删除员工对文件操作有时候会失效

* 中文有严重的乱码问题（数据类型？编辑环境？）

License
--------

    Copyright 2015 florent37, Inc.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.




