//
// Created by Galaxy. on 2023/1/14.
//

#include "arrayQueue.h"
#include "linkQueue.h"

// 测试顺序队列
int test01(){
    ArrayQueue *queue = createArrayQueue();
    Element e;
    if(queue == NULL) {
        printf("malloc error!\n");
        return -1;
    }
    for(int i = 0; i < MaxQueue - 1; i++){
        enterArrayQueue(queue, i + 100);
    }
    enterArrayQueue(queue, 500);
    printf("=====================\n");
    printf("Queue:");
    for(int i = 0; i < MaxQueue - 1; i++){
        deleteArrayQueue(queue, &e);
        printf("\t%d",e);
    }
    printf("\n");
    deleteArrayQueue(queue,&e);
    releaseArrayQueue(queue);
    return 0;
}

// 测试链式队列
int test02(){
    LinkQueue *queue = createLinkQueue();
    if (queue == NULL){
        printf("malloc error!\n");
        return -1;
    }
    for(int i = 0; i < MaxQueue; ++i){
        enterLinkQueue(queue, i + 100);
    }
    Element e;
    printf("cnt:%d\n",queue->cnt);
    printf("=====================\n");
    printf("queue:");
    for(int i = 0; i < MaxQueue; ++i){
        deleteLinkQueue(queue, &e);
        printf("\t%d",e);
    }
    printf("\n");
    deleteLinkQueue(queue, &e);
    releaseLinkQueue(queue);
    return 0;
}


int main(){
//    test01();
    test02();
    return 0;
}