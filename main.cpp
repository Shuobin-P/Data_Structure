#include<stdio.h>
#include "src/algorithm/sort/sort.h"

int main() {
    int arrLen = 8;
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int newArr[arrLen];
    mergeSort(arr, arrLen, newArr, 1);
    printf("\nFinal Result:\n");
    for (int i = 0; i < arrLen; i++) {
        printf("%d ", newArr[i]);
    }
    printf("\n");
}




