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
    traverseList(list);
    LNode *p = getNodeByVal(list, -3);
    if(p != NULL) {
        printf("The search result is %d\n", p->val);
    } else {
        printf("No results\n");
    }
    return 0;
}

