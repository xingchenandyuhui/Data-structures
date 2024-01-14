#include "00oms.h"
#include "data_model.h"
//引入子函数 
#include "01CreateOrder.c"
#include "02InsertOrder.c" 
#include "03DeleteOrder.c"
#include "04UpdateOrder.c"
#include "05SearchOrder.c"
#include "06InOrderPrint.c"
#include "07user_manager.c"
#include "08menu.c"
//#include "09Quicksort.c"
#include "09FindMin.c" 

// 主函数
int main() {
	Order *root = NULL;
    int choice, id, amount, num;
    char product_name[50];
    char time[20];
	//1、初始化系统数据结构
	struct UserSeq* seq = initSeq();
	
	//2、渲染菜单，根据菜单实现不同的业务功能 
    while (1) {
    	printMenu01();//打印一级菜单 
		int num;
		scanf("%d",&num);
		switch(num){
			case 1:
				system("cls");
				//登录 
				login(seq);
				break;
			case 2:
				system("cls");
				//注册 
				registerUser(seq);
				break;
			case 3:
				system("cls");
				//退出 
				printf("Bye~");
				return;
			default:
				system("cls");
				printf("选择的菜单有误，请重新选择\n");
				break;
		}
        
    }
    return 0;
}
