#include <stdio.h>
#include "src/seq_list/link_storage/single_link_list.h"

int main() {
    LinkList list;
    initList(list);
    insertAfterNode(list, -3);
    insertBeforeNode(list->next, -1);
    traverseList(list);
    if(insertAtIndex(list, 2, -2)) {
        printf("Insert successfully\n");
    }

    return 0;
}

