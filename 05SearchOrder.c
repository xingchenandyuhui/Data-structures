// ��ѯ����
Order* search_order(Order *root, int id) {
//	����ʧ�ܣ����Ϊ�գ�NULL�����򷵻�NULL �� 
    if (root == NULL )
    	return root;
//	���ҳɹ� ��Ҫ���ҵĶ�������==��ǰ���Ķ������� ��	
	if(id == root->id)
		return root;//���ص�ǰ��� 
	else if (id < root->id) //Ҫ���ҵĶ�������<��ǰ���Ķ�������
		return search_order(root->left, id);//���������еݹ��� 
	else//Ҫ���ҵĶ�������>��ǰ���Ķ�������
    	return search_order(root->right, id);//���������еݹ��� 
}
