#include <stdio.h>
#include "src/algorithm/sort/sort.h"

int main() {
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    int arrLen = 7;
    quickSort(arr, arrLen);
    for (int i = 0; i < arrLen; i++) {
        printf("%d ", arr[i]);
    }
}




