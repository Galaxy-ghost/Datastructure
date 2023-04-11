//
// Created by Galaxy. on 2023/1/10.
//

#include "linkList.h"
#include <stdlib.h>
#include <stdio.h>

LinkList *createLinkList() {
    LinkList *link = (LinkList *)malloc(sizeof(LinkList));
    if(link == NULL){
        printf("malloc error!\n");
        return NULL;
    }
    link->len = 0;
    link->head.next = NULL;
    link->head.ele = 0;
    return link;
}

void releaseLinkList(LinkList *linkList) {
    int cnt = 0;
    if(linkList){
        Node *node = &linkList->head;
        while(node->next){
            Node *tmp = node->next;
            node->next = tmp->next;
            free(tmp);
            cnt++;
        }
        printf("release %d nodes!\n",cnt);
        free(linkList);
    }
}

/*
 * pos的范围在[1,linkList->len + 1]
 */
int insertLinkList(LinkList *linkList, int pos, Element e) {
    if(pos < 1 || pos > linkList->len + 1){
        printf("insert pos invalid!\n");
        return -1;
    }
    // 要在pos的位置上插入，要找到pos-1的位置
    int cnt = 0;
    Node *tmp = &linkList->head;
    while(tmp && cnt != pos - 1){
        tmp = tmp->next;
        cnt++;
    }
    // tmp指向了插入节点的前一个节点
    Node *new_node = (Node *)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("malloc new node failed!\n");
        return -1;
    }
    new_node->ele = e;
    new_node->next = tmp->next;
    tmp->next = new_node;
    linkList->len++;
    return 0;
}

void showLinkList(LinkList *linkList) {
    // head是一个节点而不是节点的指针
    Node *tmp = linkList->head.next;
    // 这时候tmp指向单链表中第一个元素
    while(tmp){
        printf("%d\t",tmp->ele);
        tmp = tmp->next;
    }
    printf("\n");
}

/* 删除操作
 * 遍历直到节点的下一个节点的值与目标值相等
 */
int deleteLinkList(LinkList *linkList, Element e) {
    Node *node = &linkList->head;
    while(node->next && node->next->ele != e){
        node = node->next;
    }
    if(node->next == NULL){
        printf("not found!\n");
        return -1;
    }
    // 删除的备份思想
    Node *tmp = node->next;
    node->next = tmp->next;
    free(tmp);
    linkList->len--;
    return 0;
}
