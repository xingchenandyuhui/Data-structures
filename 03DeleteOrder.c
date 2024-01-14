//// 删除订单
//void delete_order(Order *root, int id) {
//    if (root == NULL) return;
//    if (id < root->id) {
//        delete_order(root->left, id);//往左子树找要删除的结点 
//    } else if (id > root->id) {
//        delete_order(root->right, id);//往右子树找要删除的结点 
//    } else {//查找到了删除结点 
//        if (root->left == NULL) {//左子树为空 ，右子树直接顶上去 
//            Order *temp = root; 
//			root = root->right;
//            free(temp);
//        } else if (root->right == NULL) {//右子树为空 ，左子树直接顶上去
//            Order *temp = root; 
//			root = root->left;
//            free(temp);
//        }else{//左右子树都不为空 
//        	Order *temp = root->left;
//        	while(temp->right != NULL){//向右找到最小的 
//        		temp = temp->right; 
//			}
//			//把temp对应的值替换到要删除的位置上 
//        root->id = temp->id;
//        strcpy(root->product_name, temp->product_name);
//        root->num = temp->num;
//        root->amount = temp->amount;
//        strcpy(root->time, temp->time);
//    	delete_order(root->left, temp->id); //删除temp 
//		} 
//    }
//}

// 删除订单
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
