#ifndef __OMS_H__
#define __OMS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���嶩���ṹ��
typedef struct Order {
    int id;//�������
    char product_name[50];//�������� 
    int num; //�������� 
    double amount;//������� 
    char time[20];//����ʱ�� 
    struct Order *left;
    struct Order *right;
} Order;

//����ģ�� 

//�������� 
Order* create_order(int id, char *product_name, 
					int num, double amount, char *time);
								
//��Ӷ��� 
Order* insert_order(Order *root, int id, char *product_name,
						 int num, double amount, char *time);
						 
// ɾ������
//void delete_order(Order *root, int id); 
Order* delete_order(Order *root, int id); 
//�޸Ķ���
void update_order(Order *root, int id, char *product_name, 
					int num, double amount, char *time)  ; 
					
//��ѯ����
Order* search_order(Order *root, int id) ; 

//���������������б�
void inorder_print(Order *root); 
 
////����
//void QuickSort() ; 

// ������С�ڵ�
Order* find_min(Order *root);


#endif

