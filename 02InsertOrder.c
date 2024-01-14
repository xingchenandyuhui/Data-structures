// ���붩��
Order* insert_order(Order *root, int id, char *product_name, int num, double amount, char *time) {
	//�ö���������Ϊ�� 
    if (root == NULL) {
//    	�򴴽��½�� 
        return create_order(id, product_name, num, amount, time);
    }
//    Ҫ��ӵĶ������<��ǰ��㶩����� 
    if (id < root->id) {
//    	����ݹ���뵽��ǰ���������� 
        root->left = insert_order(root->left, id, product_name, num, amount, time);
    } else if (id > root->id) {// Ҫ��ӵĶ������>��ǰ��㶩����� 
//    ����ݹ���뵽��ǰ���������� 
        root->right = insert_order(root->right, id, product_name, num, amount, time);
    }
    return root;
}
