// ������С�ڵ�
Order* find_min(Order *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
