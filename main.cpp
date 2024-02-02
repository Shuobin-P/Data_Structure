#include <stdio.h>
#include "src/seq_list/link_storage/single_link_list.h"

int main() {
    LinkList list;
    createListByInsertTail(list);
    traverseList(list);
    return 0;
}

