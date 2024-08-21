/********************************************************************************
* @author: Shuobin
* @date: 2024/4/19 16:54
* @version: 1.0
* @description: 排序算法实现
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
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
 * 保证idx对应的元素是大根堆，递归实现。
 * @param arr
 * @param idx 需调整为大根堆的元素的下标
 */
void keepMaxHeapRecurImpl(int *arr, int arrLen, int idx) {
    if (idx > arrLen / 2) return; //说明无孩子节点
    if (2 * idx + 1 > arrLen) {   //说明idx只有左孩子
        if (arr[idx] < arr[2 * idx]) {
            arr[0] = arr[idx];
            arr[idx] = arr[2 * idx];
            arr[2 * idx] = arr[0];
        }
    } else {                    //说明idx有左，右孩子
        if (!(arr[idx] > arr[2 * idx] && arr[idx] > arr[2 * idx + 1])) {
            int maxIdx = arr[2 * idx] > arr[2 * idx + 1] ? 2 * idx : 2 * idx + 1;
            arr[0] = arr[idx];
            arr[idx] = arr[maxIdx];
            arr[maxIdx] = arr[0];
            keepMaxHeapRecurImpl(arr, arrLen, maxIdx); //保证下坠元素依然满足大根堆的要求。
        }
    }
}

/**
 * 保证idx对应的元素是大根堆的非递归实现。使得堆排序整体复杂度为O(NlogN)的选择，logN是以2为底。
 * @param arr
 * @param arrLen
 * @param idx 需调整为大根堆的元素的下标
 */
void keepMaxHeapNotRecur(int *arr, int arrLen, int idx) {
    //判断arr[idx]与左孩子，右孩子的大小，然后arr[idx]与大的那个孩子交换位置，被替换的元素称为下坠元素，下坠元素依然需要保证大根堆
    arr[0] = arr[idx]; //把arr[idx]以外的其它元素放好位置，再把arr[0]放到最终的位置。
    for (int i = 2 * idx; i <= arrLen; i = 2 * i) {
        //i是idx的左孩子，考虑了只有左孩子，无右孩子的情况
        if (i < arrLen && arr[i] < arr[i + 1]) {
            i++;
        }
        if (arr[0] >= arr[i]) break; // 比左右孩子都大
        else {
            arr[idx] = arr[i];
            idx = i;
        }
    }
    arr[idx] = arr[0];
}

/**
 * 保证idx对应的元素是大根堆
 * @param arr
 * @param arrLen
 * @param idx 目标元素下标
 * @param opt 1：递归实现 2：非递归实现
 */
void keepMaxHeap(int *arr, int arrLen, int idx, short opt) {
    if (opt == 1) {
        keepMaxHeapRecurImpl(arr, arrLen, idx);
    } else if (opt == 2) {
        keepMaxHeapNotRecur(arr, arrLen, idx);
    }
}

void buildMaxHeap(int *arr, int arrLen) {
    for (int i = arrLen / 2; i >= 1; i--) {
        //arr[i]即为要调整为大根堆的非叶子结点
        //判断arr[i]大于arr[2i]和arr[2i+1]，如果不是，则找到最大的元素与arr[i]交换。但是下坠后的arr[i]，还要保证大根堆的性质，需要继续进行处理
        keepMaxHeap(arr, arrLen, i, KEEP_MAX_HEAP_OPT);
    }
}

void heapSort(int *arr, int arrLen) {
    buildMaxHeap(arr, arrLen);
    //交换arr[1]和arr的最后一个元素，再调用keepHeap(arr, arrLen, 1)
    for (int last = arrLen; last > 1;) {
        arr[0] = arr[1];
        arr[1] = arr[last];
        arr[last] = arr[0];
        keepMaxHeap(arr, --last, 1, KEEP_MAX_HEAP_OPT);
    }
    for (int i = 1; i <= arrLen; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * 将lArr，rArr两个有序数组合并到新数组newArr中
 * @param lArr
 * @param rArr
 * @param lArrLen
 * @param rArrLen
 * @param newArr 合并了lArr和rArr两个有序数组的新数组
 */
void merge(int *lArr, int *rArr, int lArrLen, int rArrLen, int *newArr) {
    int lPtr, rPtr, newArrPtr = 0;
    while (lPtr < lArrLen && rPtr < rArrLen) {
        if (lArr[lPtr] > rArr[rPtr]) {
            newArr[newArrPtr++] = rArr[rPtr++];
        } else {   //保证该排序算法是稳定的
            newArr[newArrPtr++] = lArr[lPtr++];
        }
    }
    //把 lArr剩余部分加入到newArr
    while (lPtr < lArrLen) {
        newArr[newArrPtr++] = lArr[lPtr++];
    }
    //把 rArr剩余部分加入到newArr
    while (rPtr < rArrLen) {
        newArr[newArrPtr++] = rArr[rPtr++];
    }
}

/**
 * 排序后的数据在新数组newArr中，如果需要让排序好的数组的数据依然在arr中，可以使用另外一种实现方式。
 * @param arr 待排序数组
 * @param newArr 存储排序后的数组数据
 * @param left 待排序序列在arr中的开始位置
 * @param right 待排序序列在arr中的结束位置
 */
void mergeSortOptOne(int *arr, int *newArr, int left, int right) {
    //将arr分成两部分，分别排好序，然后再将两部分合并即可得到最终的序列
    if (left == right) {
        //需要把数据放入到newArr中
        newArr[0] = arr[left];   //IMPORTANT 易忘，易错
        return;
    }
    int mid = left + (right - left) / 2;
    int lNewArr[mid - left + 1];
    int rNewArr[right - mid];
    mergeSortOptOne(arr, lNewArr, left, mid);
    mergeSortOptOne(arr, rNewArr, mid + 1, right);
    //合并lNewArr和rNewArr，将其放入newArr中
    merge(lNewArr, rNewArr, mid - left + 1, right - mid, newArr);
}

/**
 * 把arr中从left->mid, mid+1->right之间的元素排序
 * @param arr 存储待排序数据的数组
 * @param tmpArr 缓存数组
 * @param left 第一个已排序的数组的起始地址（在arr中的地址）
 * @param mid 第一个已排序的数组的结束地址，mid+1即为第二个已排序的数组的起始地址
 * @param right 第二个已排序的数组的结束地址
 */
void merge(int *arr, int *tmpArr, int left, int mid, int right) {
    int ptr = left;
    int lPtr = left;
    int rPtr = mid + 1;
    for (int i = left; i <= right; i++) {
        tmpArr[i] = arr[i];
    }
    while (lPtr <= mid && rPtr <= right) {
        if (tmpArr[lPtr] > tmpArr[rPtr]) {
            arr[ptr++] = tmpArr[rPtr++];
        } else if (tmpArr[lPtr] <= tmpArr[rPtr]) {
            arr[ptr++] = tmpArr[lPtr++];
        }
    }
    while (lPtr <= mid) {
        //把lPtr指向的数组剩余元素加入到arr
        arr[ptr++] = tmpArr[lPtr++];
    }
    while (rPtr <= right) {
        arr[ptr++] = tmpArr[rPtr++];
    }
}

/**
 * 对arr进行归并排序后的数据依然存储在arr中
 * @param arr
 * @param tmpArr 缓存arr数据的数组
 * @param left 待排序序列的在arr的起始地址
 * @param right 待排序序列的在arr的终止地址
 */
void mergeSortOptTwo(int *arr, int *tmpArr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortOptTwo(arr, tmpArr, left, mid);
    mergeSortOptTwo(arr, tmpArr, mid + 1, right);
    merge(arr, tmpArr, left, mid, right);
}

void mergeSort(int *arr, int arrLen, int *newArr, short opt) {
    if (opt == 1) {
        mergeSortOptOne(arr, newArr, 0, arrLen - 1);
    } else if (opt == 2) {
        mergeSortOptTwo(arr, newArr, 0, arrLen - 1);
    }
}

