// 创建新订单
Order* create_order(int id, char *product_name, 
					int num, double amount, char *time) {
	//创建新的结点 
    Order *new_order = (Order *)malloc(sizeof(Order));
    //将订单信息填入新结点 
    new_order->id = id;
    strcpy(new_order->product_name, product_name);
    new_order->num = num;
    new_order->amount = amount;
    strcpy(new_order->time, time);
    //将当前结点左右孩子指针指向空（NULL) 
    new_order->left = NULL;
    new_order->right = NULL;
    //返回新结点 
    return new_order;
}

