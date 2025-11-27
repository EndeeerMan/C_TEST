#include <stdio.h>

// 交换两个整数的辅助函数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 快速排序核心函数
// arr: 数组
// left: 左边界下标
// right: 右边界下标
void quick_sort(int arr[], int left, int right) {
    // 递归出口：如果左边索引大于或等于右边，说明只剩一个元素或没有元素，不需要排序
    if (left >= right) {
        return;
    }

    int i = left;
    int j = right;
    // 选择最左边的数为基准数
    int pivot = arr[left];

    // 当 i 和 j 没有相遇时，循环执行
    while (i < j) {
        // 【重点】必须先从右边开始找！
        // 只要 j 对应的值大于等于基准值，j 就一直向左移
        while (i < j && arr[j] >= pivot) {
            j--;
        }

        // j 停下后，i 开始行动
        // 只要 i 对应的值小于等于基准值，i 就一直向右移
        while (i < j && arr[i] <= pivot) {
            i++;
        }

        // 如果 i 和 j 还没相遇，说明找到了需要交换的一对数
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    // 当 while 循环结束，说明 i 和 j 相遇了
    // 此时将基准数（原 left 位置）与相遇点（i 位置）交换
    // 这样基准数就归位了
    swap(&arr[left], &arr[i]);

    // 递归处理基准数左边的部分
    quick_sort(arr, left, i - 1);
    
    // 递归处理基准数右边的部分
    quick_sort(arr, i + 1, right);
}

int main() {
    int arr[] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 调用快速排序，范围是 0 到 n-1
    quick_sort(arr, 0, n - 1);

    printf("排序后: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}