// �����¶���
Order* create_order(int id, char *product_name, 
					int num, double amount, char *time) {
	//�����µĽ�� 
    Order *new_order = (Order *)malloc(sizeof(Order));
    //��������Ϣ�����½�� 
    new_order->id = id;
    strcpy(new_order->product_name, product_name);
    new_order->num = num;
    new_order->amount = amount;
    strcpy(new_order->time, time);
    //����ǰ������Һ���ָ��ָ��գ�NULL) 
    new_order->left = NULL;
    new_order->right = NULL;
    //�����½�� 
    return new_order;
}

