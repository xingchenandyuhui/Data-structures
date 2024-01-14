// 插入订单
Order* insert_order(Order *root, int id, char *product_name, int num, double amount, char *time) {
	//该二叉排序树为空 
    if (root == NULL) {
//    	则创建新结点 
        return create_order(id, product_name, num, amount, time);
    }
//    要添加的订单编号<当前结点订单编号 
    if (id < root->id) {
//    	则将其递归插入到当前结点的左子树 
        root->left = insert_order(root->left, id, product_name, num, amount, time);
    } else if (id > root->id) {// 要添加的订单编号>当前结点订单编号 
//    则将其递归插入到当前结点的右子树 
        root->right = insert_order(root->right, id, product_name, num, amount, time);
    }
    return root;
}
