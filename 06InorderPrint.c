// ���������ӡ����
void inorder_print(Order *root) {
//	��ǰ���Ϊ�գ���ֱ�ӷ��� 
    if (root == NULL) return;
    //�ȱ��������� 
    inorder_print(root->left);
    //������ǰ��� 
    printf("�������: %d, ��������: %s,����������%d, �������: %.2fԪ, ����ʱ�䣺%s\n", 
						root->id, root->product_name,root->num,	root->amount, root->time);
	//������������ 
    inorder_print(root->right);
}
