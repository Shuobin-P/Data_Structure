#include <stdio.h>
#include "src/algorithm/sort/sort.h"

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3};
    int arrLen = 7;
    shellSort(arr, arrLen);
    for (int i = 0; i < arrLen; i++) {
        printf("%d ", arr[i]);
    }
}




