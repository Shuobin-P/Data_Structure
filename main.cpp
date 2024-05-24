#include <stdio.h>
#include "src/algorithm/search/kmp.h"

int main() {
    char str[] = {'a', 'b', 'a', 'a', 'c', 'a', 'a', 'b', 'c', 'a', 'b', 'a', 'a', 'b', 'c'};
    char substr[] = {'a', 'b', 'a', 'a', 'b', 'c'};
    printf("Index = %d", kmp(str, 15, substr, 6));
    return 0;
}




