// 快速排序分区函数
Order* partition(Order *root, Order *low, Order *high) {
    Order *pivot = high;
    Order *i = low - 1;
    Order *j; 
    for (*j = low; j <= high - 1; j++) {
        if (root->amount < pivot->amount) {
            i++;
            Order *temp = root[i];
            root[i] = root[j];
            root[j] = temp;
        }
    }
    Order *temp = root[i + 1];
    root[i + 1] = root[high];
    root[high] = temp;
    return i + 1;
}

// 快速排序函数
void quicksort(Order *root, Order *low, Order *high) {
    if (low < high) {
        Order *pi = partition(root, low, high);
        quicksort(root, low, pi - 1);
        quicksort(root, pi + 1, high);
    }
}

