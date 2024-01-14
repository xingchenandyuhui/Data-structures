// ÐÞ¸Ä¶©µ¥
void update_order(Order *root, int id, char *product_name, 
					int num, double amount, char *time) {
    if (root == NULL) return;
    if (id < root->id) {
        update_order(root->left, id, product_name, num, amount, time);
    } else if (id > root->id) {
        update_order(root->right, id, product_name, num, amount, time );
    } else {
        strcpy(root->product_name, product_name);
        root->num = num;
        root->amount = amount;
        strcpy(root->time, time);
    }
}
