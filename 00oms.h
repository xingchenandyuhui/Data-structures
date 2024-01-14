#ifndef __OMS_H__
#define __OMS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义订单结构体
typedef struct Order {
    int id;//订单编号
    char product_name[50];//订单名称 
    int num; //订单数量 
    double amount;//订单金额 
    char time[20];//订单时间 
    struct Order *left;
    struct Order *right;
} Order;

//功能模块 

//创建订单 
Order* create_order(int id, char *product_name, 
					int num, double amount, char *time);
								
//添加订单 
Order* insert_order(Order *root, int id, char *product_name,
						 int num, double amount, char *time);
						 
// 删除订单
//void delete_order(Order *root, int id); 
Order* delete_order(Order *root, int id); 
//修改订单
void update_order(Order *root, int id, char *product_name, 
					int num, double amount, char *time)  ; 
					
//查询订单
Order* search_order(Order *root, int id) ; 

//中序遍历输出订单列表
void inorder_print(Order *root); 
 
////排序
//void QuickSort() ; 

// 查找最小节点
Order* find_min(Order *root);


#endif
