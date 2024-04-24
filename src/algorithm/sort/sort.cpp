/********************************************************************************
* @author: Shuobin
* @date: 2024/4/19 16:54
* @version: 1.0
* @description: 排序算法实现
********************************************************************************/
#include "sort.h"


void insertionSort(int *arr, int arrLen) {
    for (int i = 1; i <= arrLen - 1; i++) {
        int tmp = arr[i];
        if (tmp >= arr[i - 1]) continue;
        int j = i - 1;
        for (; j >= 0; j--) { //把比tmp大的元素往后移
            if (tmp >= arr[j]) {
                break;
            } else if (tmp < arr[j]) {
                arr[j + 1] = arr[j];
            }
        }
        arr[j + 1] = tmp;
    }
}

void shellSort(int *arr, int arrLen) {
    int gap = arrLen / 2;
    for (; gap >= 1; gap /= 2) { //gap是影响时间复杂度的关键
        for (int i = gap; i <= arrLen - 1; i++) { //注：这里是i++，而不是i+=gap，但是采用i+=gap需要改写算法
            int tmp = arr[i];
            if (tmp >= arr[i - gap]) continue;
            int j = i - gap;
            for (; j >= 0; j -= gap) { //把比tmp大的元素往后移
                if (tmp >= arr[j]) {
                    break;
                } else if (tmp < arr[j]) {
                    arr[j + gap] = arr[j];
                }
            }
            arr[j + gap] = tmp;
        }
    }
}

void bubbleSortAscOrder(int *arr, int arrLen) {
    for (int i = 0; i <= arrLen - 2; i++) {
        bool isExchange = false;    //判断本趟是否发生了数据交换，如果未发生，说明数组已经有序，不需继续运行。
        for (int j = 1; j <= arrLen - i - 1; j++) {
            if (arr[j] < arr[j - 1]) {
                isExchange = true;
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
        if (!isExchange) return;
    }
}

void bubbleSortDescOrder(int *arr, int arrLen) {
    for (int i = 0; i <= arrLen - 2; i++) {
        bool isExchange = false;    //判断本趟是否发生了数据交换，如果未发生，说明数组已经有序，不需继续运行。
        for (int j = arrLen - 1; j >= i + 1; j--) {
            if (arr[j] > arr[j - 1]) {
                isExchange = true;
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
        if (!isExchange) return;
    }
}

void bubbleSort(int *arr, int arrLen, short opt) {
    if (opt == 1) bubbleSortAscOrder(arr, arrLen);
    else if (opt == 2) bubbleSortDescOrder(arr, arrLen);
}

/**
 * 4 3 2 1
 * tmp = 4 low = 0 high = 3
 * 1 3 2 1
 * low = high = 3
 *
 */
void quickSort(int *arr, int low, int high) {
    if (low >= high) return;
    int tmp = arr[low];
    int left = low;
    int right = high;
    while (low < high) {
        while (low < high && arr[high] >= tmp) {
            high--;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] <= tmp) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = tmp;
    quickSort(arr, left, low - 1);
    quickSort(arr, low + 1, right);
}

void quickSort(int *arr, int arrLen) {
    quickSort(arr, 0, arrLen - 1);
}
