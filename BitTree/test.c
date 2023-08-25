//////
////// Created by William on 2023/7/23.
//////
////
////#include <stdio.h>
////
////// 交换两个元素的值
////void swap(int *a, int *b) {
////    int temp = *a;
////    *a = *b;
////    *b = temp;
////}
////
////// 将数组分区，并返回基准元素的索引
////int partition(int arr[], int low, int high) {
////    int pivot = arr[low]; // 选择第一个元素作为基准元素
////    while (low < high){
////        while (low < high && arr[high] >= pivot)
////            --high;
////        arr[low] = arr[high];
////        while (low < high && arr[low] <= pivot)
////            ++low;
////        arr[high] = arr[low];
////    }
////    arr[low] = pivot;
////    return low;
////
////}
////
////// 快速排序函数
////void quickSort(int arr[], int low, int high) {
////    if (low < high) {
////        int pivotIdx = partition(arr, low, high); // 获取基准元素的索引
////
////        // 递归对基准元素左边和右边的子数组进行排序
////        quickSort(arr, low, pivotIdx - 1);
////        quickSort(arr, pivotIdx + 1, high);
////    }
////}
////
////int main() {
////    int arr[] = {24, 34, 25, 12, 22, 11, 90};
////    int n = sizeof(arr) / sizeof(arr[0]);
////
////    printf("原数组: ");
////    for (int i = 0; i < n; i++) {
////        printf("%d ", arr[i]);
////    }
////
////    quickSort(arr, 0, n - 1);
////
////    printf("\n排序后: ");
////    for (int i = 0; i < n; i++) {
////        printf("%d ", arr[i]);
////    }
////
////    return 0;
////}
//#include <stdio.h>
//
//// 合并两个有序数组
//void merge(int arr[], int left, int mid, int right) {
//    int n1 = mid - left + 1; // 左子数组的长度
//    int n2 = right - mid;    // 右子数组的长度
//
//    // 创建临时数组存放合并后的结果
//    int temp[n1 + n2];
//
//    // 归并排序
//    int i = left; // 左子数组的索引
//    int j = mid + 1; // 右子数组的索引
//    int k = 0; // 合并后数组的索引
//
//    while (i <= mid && j <= right) {
//        if (arr[i] <= arr[j]) {
//            temp[k] = arr[i];
//            i++;
//        } else {
//            temp[k] = arr[j];
//            j++;
//        }
//        k++;
//    }
//
//    // 将剩余元素复制到合并后的数组
//    while (i <= mid) {
//        temp[k] = arr[i];
//        i++;
//        k++;
//    }
//    while (j <= right) {
//        temp[k] = arr[j];
//        j++;
//        k++;
//    }
//
//    // 将合并后的结果复制回原数组
//    for (int p = 0; p < k; p++) {
//        arr[left + p] = temp[p];
//    }
//}
//
//// 归并排序
//void mergeSort(int arr[], int left, int right) {
//    if (left < right) {
//        int mid = left + (right - left) / 2;
//
//        // 分治递归地对左右子数组进行排序
//        mergeSort(arr, left, mid);
//        mergeSort(arr, mid + 1, right);
//
//        // 合并左右子数组
//        merge(arr, left, mid, right);
//    }
//}
//
//int main() {
//    int arr[] = {38, 27, 43, 3, 9, 82, 10};
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    printf("原数组: ");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//
//    mergeSort(arr, 0, n - 1);
//
//    printf("\n排序后: ");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", arr[i]);
//    }
//
//    return 0;
//}

#include <stdio.h>

int main(){
    double f = -7.5;
    short i = f;

    printf("%d",i);
    return 0;
}

