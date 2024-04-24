/********************************************************************************
* @author: Shuobin
* @date: 2024/4/19 16:54
* @version: 1.0
* @description: 排序算法实现
********************************************************************************/
#include <stdio.h>
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

/**
 * 保证idx对应的元素是大根堆
 * @param arr
 * @param idx 需调整为大根堆的元素的下标
 */
void keepHeap(int *arr, int arrLen, int idx) {
    if (idx > arrLen / 2) return;
    if (2 * idx + 1 > arrLen) { //说明idx只有左孩子
        if (arr[idx] < arr[2 * idx]) {
            arr[0] = arr[idx];
            arr[idx] = arr[2 * idx];
            arr[2 * idx] = arr[0];
        }
    } else {//说明idx有左，右孩子
        if (!(arr[idx] > arr[2 * idx] && arr[idx] > arr[2 * idx + 1])) {
            int maxIdx = arr[2 * idx] > arr[2 * idx + 1] ? 2 * idx : 2 * idx + 1;
            arr[0] = arr[idx];
            arr[idx] = arr[maxIdx];
            arr[maxIdx] = arr[0];
            keepHeap(arr, arrLen, maxIdx); //保证下坠元素依然满足大根堆的要求。
        }
    }
}

void buildMaxHeap(int *arr, int arrLen) {
    for (int i = arrLen / 2; i >= 1; i--) {
        //arr[i]即为要调整为大根堆的非叶子结点
        //判断arr[i]大于arr[2i]和arr[2i+1]，如果不是，则找到最大的元素与arr[i]交换。但是下坠后的arr[i]，还要保证大根堆的性质，需要继续进行处理
        keepHeap(arr, arrLen, i);
    }
}

void heapSort(int *arr, int arrLen) {
    buildMaxHeap(arr, arrLen);
    //交换arr[1]和arr的最后一个元素，再调用keepHeap(arr, arrLen, 1)
    for (int last = arrLen; last > 1;) {
        arr[0] = arr[1];
        arr[1] = arr[last];
        arr[last] = arr[0];
        keepHeap(arr, --last, 1);
    }
    for (int i = 1; i <= arrLen; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}

