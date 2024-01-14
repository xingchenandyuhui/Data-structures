## 京东订单管理系统
### 一、	课题背景
随着电子商务的快速发展，京东作为中国最大的自营式电商企业，其订单量日益增长，对订单管理的需求也越来越高。传统的人工管理方式已经无法满足大规模、高效率的订单处理需求。因此，设计并实现一个高效、稳定、易用的京东订单管理系统，对于提高京东的订单处理效率，提升客户满意度，降低运营成本具有重要的实际意义。
### 二、	课题说明
设计一个京东订单管理系统，实现订单信息的增删改查等功能。

#### 1.	数据结构选择：
   可以使用二叉树链式存储订单信息，使用二叉排序树递归算法来实现快速查找订单。
#### 2. 功能实现：
①	登录功能
②	注册功能
③	退出功能
④	添加订单信息：输入订单编号、订单名称、订单数量、订单价格、订单时间等信息，将其添加到链表或数组中。
⑤	删除订单信息：根据订单编号，从二叉树中删除对应的订单信息。
⑥	修改订单信息：根据订单编号查找，修改其订单名称等信息。
⑦	查询订单信息：根据订单编号查找，输出订单详细信息。
⑧	信息管理：为每个订单管理人员维护一个信息列表，可以添加、删除、修改、查询订单信息。
#### 3. 界面设计：
  使用命令行界面来与用户交互，提供菜单选项供用户选择操作。
#### 4.	测试与调试：
  对系统进行功能测试和性能测试，确保系统的稳定性和正确性。
#### 5.运行
主文件是00main.c，每次点击编译运行该文件就可以，点击编译运行其他文件会报错。
