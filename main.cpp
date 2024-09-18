#include<stdio.h>
#include "src/linear_list/link_storage/single_link_list/single_link_list.h"

using namespace std;

int main() {
    //练习实现线性表的基本操作：
    LinkList list;
    initListDummyHead(list);
    insertAtIndex(list, 1, 1);
    insertAtIndex(list, 2, 2);
    insertAtIndex(list, 3, 3);
    insertAtIndex(list, 4, 4);
    traverseList(list);
    int holder = 0;
    listDelete(list, 5, holder);
    traverseList(list);
    return 0;
}