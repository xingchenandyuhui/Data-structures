//存放和用户操作有关的函数
//和用户数据有关的操作：登录 注册
void login(struct UserSeq* seq){
	//1、需要输入用户名和密码
	printf("请输入用户名：\n");
	char name[20];
	scanf("%s",&name);
	printf("请输入密码：\n");
	char password[20];
	scanf("%s",&password); 
	//2、需要遍历seq顺序表，匹配用户输入的信息是否存在
	int index = 0;
	int flag = 0;//代表是否登录成功 0失败 1代表成功 
	for(index; index < seq->length; index++){
		//判断用户输入的信息和顺序表当前index位置存储
		//的用户信息是否匹配
		if(strcmp(name,seq->users[index].name) == 0
		   && strcmp(password,seq->users[index].password) == 0){
		   	flag = 1;
			break; 
		} 
	}
	
	if(flag == 1){
		//渲染二级菜单 
		printf("登录成功！\n");
		Order *root = NULL;
        while(1) {
	        printMenu02();//二级菜单 
		    int choice, id, num;
		    double amount;
		    char product_name[50];
		    char time[20];
        	printf("请选择菜单项： ");
        	scanf("%d", &choice);
        	
	        switch (choice) {
	            case 1:
	            	system("cls");
	            	printf("请输入您需要新增的订单详情:\n");
	                printf("订单编号：");
	                scanf("%d", &id);
	                printf("订单名称: ");
	                scanf("%s", product_name);
	                printf("订单数量: ");
	                scanf("%d", &num);
	                printf("订单金额: ");
	                scanf("%lf", &amount);
	                printf("订单时间: ");
	                scanf("%s", time);
	                root = insert_order(root, id, product_name, num, amount, time );
//	                printf("订单编号: %d, 订单名称: %s, 订单数量: %d, 订单金额: %d元\n，订单时间：%s\n", 
//							root->id, root->product_name, root->num, root->amount, root->time);
	                printf("新增完成！\n"); 
	                break;
	            case 2:
	            	system("cls");
	            	printf("请输入您需要删除的订单详情:\n");
	                printf("订单编号: ");
	                scanf("%d", &id);
//	                delete_order(root, id);
					root = delete_order(root, id);
	                printf("删除完成！\n");
	                break;
	            case 3:
	            	system("cls");
	            	printf("请输入您需要修改的订单编号:\n");
	                printf("订单编号：");
	                scanf("%d", &id);
	                printf("订单名称: ");
	                scanf("%s", product_name);
	                printf("订单数量: ");
	                scanf("%d", &num);
	                printf("订单金额: ");
	                scanf("%lf", &amount);
	                printf("订单时间: ");
	                scanf("%s", time);
	                update_order(root, id, product_name, num, amount, time );
	                printf("修改完成！\n");
	                break;
	            case 4:
//	            	if(root == NULL){
//	            		printf("null\n");
//					}
//	            	printf("订单编号: %d, 订单名称: %s, 订单数量: %d, 订单金额: %.2f元\n，订单时间：%s\n", 
//								root->id, root->product_name, root->num, root->amount, root->time);
	            	system("cls");
	            	printf("请输入您需要查询的订单编号:\n");
	                printf("订单编号: ");
	                scanf("%d", &id);
	                root = search_order(root, id);
	                if (root != NULL) {
	                    printf("订单编号: %d, 订单名称: %s, 订单数量: %d, 订单金额: %.2f元，订单时间：%s\n", 
								root->id, root->product_name, root->num, root->amount, root->time);
	                } else {
	                    printf("很抱歉，未找到该订单！\n");
	                }
	                break;
	            case 5:
//	            	printf("null\n"); 
//	            	if(root == NULL){
//	            		printf("null\n"); 
//					}
	            	system("cls");
	                inorder_print(root);
	                printf("输出已完成！\n");
	                break;
	//            case 6:
	//                quicksort(root, root, NULL);
	//                break;
	            case 6:
	            	system("cls");
	            	printf("欢迎您下次使用");
	                exit(0);
	            default:
	                printf("您选择的菜单有误，请重新选择！");
	        }
		
	}
	}else{
		printf("用户名或者密码错误\n");
	} 
	
}

void registerUser(struct UserSeq* seq){
	printf("请输入用户名：\n");
	char name[20];
	scanf("%s",&name);
	printf("请输入密码：\n");
	char password[20];
	scanf("%s",&password);
	//1、注册的信息写到顺序表中
	strcpy(seq->users[seq->length].name,name);
	strcpy(seq->users[seq->length].password,password);
	seq->length++;
	//2、注册信息往文件中追加一份 
	FILE* fp = fopen("users.txt","a");
	fprintf(fp,"%s %s\n",name,password);
	fclose(fp);
	printf("注册成功！\n");
}
