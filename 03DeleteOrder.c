//// ɾ������
//void delete_order(Order *root, int id) {
//    if (root == NULL) return;
//    if (id < root->id) {
//        delete_order(root->left, id);//����������Ҫɾ���Ľ�� 
//    } else if (id > root->id) {
//        delete_order(root->right, id);//����������Ҫɾ���Ľ�� 
//    } else {//���ҵ���ɾ����� 
//        if (root->left == NULL) {//������Ϊ�� ��������ֱ�Ӷ���ȥ 
//            Order *temp = root; 
//			root = root->right;
//            free(temp);
//        } else if (root->right == NULL) {//������Ϊ�� ��������ֱ�Ӷ���ȥ
//            Order *temp = root; 
//			root = root->left;
//            free(temp);
//        }else{//������������Ϊ�� 
//        	Order *temp = root->left;
//        	while(temp->right != NULL){//�����ҵ���С�� 
//        		temp = temp->right; 
//			}
//			//��temp��Ӧ��ֵ�滻��Ҫɾ����λ���� 
//        root->id = temp->id;
//        strcpy(root->product_name, temp->product_name);
//        root->num = temp->num;
//        root->amount = temp->amount;
//        strcpy(root->time, temp->time);
//    	delete_order(root->left, temp->id); //ɾ��temp 
//		} 
//    }
//}

// ɾ������
Order* delete_order(Order *root, int id) {
    if (root == NULL) return root;
    if (id < root->id) {
        root->left = delete_order(root->left, id);
    } else if (id > root->id) {
        root->right = delete_order(root->right, id);
    } else {
        if (root->left == NULL) {
            Order *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Order *temp = root->left;
            free(root);
            return temp;
        }
    Order *temp = find_min(root->right);
        root->id = temp->id;
        strcpy(root->product_name, temp->product_name);
        root->num = temp->num;
        root->amount = temp->amount;
        strcpy(root->time, temp->time);
        root->right = delete_order(root->right, temp->id);
    }
    return root;
}
