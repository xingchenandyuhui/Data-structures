//��ź��û������йصĺ���
//���û������йصĲ�������¼ ע��
void login(struct UserSeq* seq){
	//1����Ҫ�����û���������
	printf("�������û�����\n");
	char name[20];
	scanf("%s",&name);
	printf("���������룺\n");
	char password[20];
	scanf("%s",&password); 
	//2����Ҫ����seq˳���ƥ���û��������Ϣ�Ƿ����
	int index = 0;
	int flag = 0;//�����Ƿ��¼�ɹ� 0ʧ�� 1����ɹ� 
	for(index; index < seq->length; index++){
		//�ж��û��������Ϣ��˳���ǰindexλ�ô洢
		//���û���Ϣ�Ƿ�ƥ��
		if(strcmp(name,seq->users[index].name) == 0
		   && strcmp(password,seq->users[index].password) == 0){
		   	flag = 1;
			break; 
		} 
	}
	
	if(flag == 1){
		//��Ⱦ�����˵� 
		printf("��¼�ɹ���\n");
		Order *root = NULL;
        while(1) {
	        printMenu02();//�����˵� 
		    int choice, id, num;
		    double amount;
		    char product_name[50];
		    char time[20];
        	printf("��ѡ��˵�� ");
        	scanf("%d", &choice);
        	
	        switch (choice) {
	            case 1:
	            	system("cls");
	            	printf("����������Ҫ�����Ķ�������:\n");
	                printf("������ţ�");
	                scanf("%d", &id);
	                printf("��������: ");
	                scanf("%s", product_name);
	                printf("��������: ");
	                scanf("%d", &num);
	                printf("�������: ");
	                scanf("%lf", &amount);
	                printf("����ʱ��: ");
	                scanf("%s", time);
	                root = insert_order(root, id, product_name, num, amount, time );
//	                printf("�������: %d, ��������: %s, ��������: %d, �������: %dԪ\n������ʱ�䣺%s\n", 
//							root->id, root->product_name, root->num, root->amount, root->time);
	                printf("������ɣ�\n"); 
	                break;
	            case 2:
	            	system("cls");
	            	printf("����������Ҫɾ���Ķ�������:\n");
	                printf("�������: ");
	                scanf("%d", &id);
//	                delete_order(root, id);
					root = delete_order(root, id);
	                printf("ɾ����ɣ�\n");
	                break;
	            case 3:
	            	system("cls");
	            	printf("����������Ҫ�޸ĵĶ������:\n");
	                printf("������ţ�");
	                scanf("%d", &id);
	                printf("��������: ");
	                scanf("%s", product_name);
	                printf("��������: ");
	                scanf("%d", &num);
	                printf("�������: ");
	                scanf("%lf", &amount);
	                printf("����ʱ��: ");
	                scanf("%s", time);
	                update_order(root, id, product_name, num, amount, time );
	                printf("�޸���ɣ�\n");
	                break;
	            case 4:
//	            	if(root == NULL){
//	            		printf("null\n");
//					}
//	            	printf("�������: %d, ��������: %s, ��������: %d, �������: %.2fԪ\n������ʱ�䣺%s\n", 
//								root->id, root->product_name, root->num, root->amount, root->time);
	            	system("cls");
	            	printf("����������Ҫ��ѯ�Ķ������:\n");
	                printf("�������: ");
	                scanf("%d", &id);
	                root = search_order(root, id);
	                if (root != NULL) {
	                    printf("�������: %d, ��������: %s, ��������: %d, �������: %.2fԪ������ʱ�䣺%s\n", 
								root->id, root->product_name, root->num, root->amount, root->time);
	                } else {
	                    printf("�ܱ�Ǹ��δ�ҵ��ö�����\n");
	                }
	                break;
	            case 5:
//	            	printf("null\n"); 
//	            	if(root == NULL){
//	            		printf("null\n"); 
//					}
	            	system("cls");
	                inorder_print(root);
	                printf("�������ɣ�\n");
	                break;
	//            case 6:
	//                quicksort(root, root, NULL);
	//                break;
	            case 6:
	            	system("cls");
	            	printf("��ӭ���´�ʹ��");
	                exit(0);
	            default:
	                printf("��ѡ��Ĳ˵�����������ѡ��");
	        }
		
	}
	}else{
		printf("�û��������������\n");
	} 
	
}

void registerUser(struct UserSeq* seq){
	printf("�������û�����\n");
	char name[20];
	scanf("%s",&name);
	printf("���������룺\n");
	char password[20];
	scanf("%s",&password);
	//1��ע�����Ϣд��˳�����
	strcpy(seq->users[seq->length].name,name);
	strcpy(seq->users[seq->length].password,password);
	seq->length++;
	//2��ע����Ϣ���ļ���׷��һ�� 
	FILE* fp = fopen("users.txt","a");
	fprintf(fp,"%s %s\n",name,password);
	fclose(fp);
	printf("ע��ɹ���\n");
}
