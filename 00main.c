#include "00oms.h"
#include "data_model.h"
//�����Ӻ��� 
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

// ������
int main() {
	Order *root = NULL;
    int choice, id, amount, num;
    char product_name[50];
    char time[20];
	//1����ʼ��ϵͳ���ݽṹ
	struct UserSeq* seq = initSeq();
	
	//2����Ⱦ�˵������ݲ˵�ʵ�ֲ�ͬ��ҵ���� 
    while (1) {
    	printMenu01();//��ӡһ���˵� 
		int num;
		scanf("%d",&num);
		switch(num){
			case 1:
				system("cls");
				//��¼ 
				login(seq);
				break;
			case 2:
				system("cls");
				//ע�� 
				registerUser(seq);
				break;
			case 3:
				system("cls");
				//�˳� 
				printf("Bye~");
				return;
			default:
				system("cls");
				printf("ѡ��Ĳ˵�����������ѡ��\n");
				break;
		}
        
    }
    return 0;
}
