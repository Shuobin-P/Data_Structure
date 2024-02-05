#include "src/linear_list/link_storage/double_link_list.h"

int main() {
    DouLinkList list;
    initDoubleLinkList(list);
    insertNodeAfterTarNode(list, createNode(1));
//    insertNodeAfterTarNode(list, createNode(2));
//    insertNodeAfterTarNode(list, createNode(3));
    traverseList(list);
    destroyList(list);
    traverseList(list);
    return 0;
}

