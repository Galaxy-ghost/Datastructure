//
// Created by Galaxy. on 2023/1/10.
//

#include <stdio.h>
#include "linkList.h"

int main(){
    LinkList *linkList = createLinkList();
    if(linkList == NULL){
        return -1;
    }
    // 插入节点
    for (int i = 0; i < 5; ++i) {
        insertLinkList(linkList, 1, i + 100);
    }
    showLinkList(linkList);
    deleteLinkList(linkList,102);
    showLinkList(linkList);
    releaseLinkList(linkList);
    return 0;
}