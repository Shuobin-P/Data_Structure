#include <stdio.h>
#include "./src/linear_list/seq_storage/stack.h"
int main() {
    Stack stack;
    init(stack);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    traverseStack(stack);
    int holder = 0;
    pop(stack, holder);
    traverseStack(stack);
    int topHolder = 0;
    getStackTopEle(stack, topHolder);
    printf("%d", topHolder);

}