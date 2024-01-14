// 查询订单
Order* search_order(Order *root, int id) {
//	查找失败（结点为空（NULL），则返回NULL ） 
    if (root == NULL )
    	return root;
//	查找成功 （要查找的订单编码==当前结点的订单编码 ）	
	if(id == root->id)
		return root;//返回当前结点 
	else if (id < root->id) //要查找的订单编码<当前结点的订单编码
		return search_order(root->left, id);//在左子树中递归找 
	else//要查找的订单编码>当前结点的订单编码
    	return search_order(root->right, id);//在右子树中递归找 
}
