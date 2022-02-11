//
//  main.cpp
//  循环单链表
//
//  Created by yinqiyu on 2021/9/2.
//

#include <iostream>
typedef struct XNode{
    int data;
    struct XNode* next;
}XNode,*XPNode;

XPNode initXLinkList(XPNode L);
void ergodicXLinkList(XPNode L);


int main(){
    XPNode L;
    L = initXLinkList(L);
    ergodicXLinkList(L);
    // L = insertXNode(L,2);
    // ergodicXLinkList(L);
    // L = deleteXNode(L,1);
    // ergodicXLinkList(L);
    system("pause");
    return 0;
}

XPNode initXLinkList(XPNode L){
    L = (XPNode)malloc(sizeof(XNode));
    XPNode p = L,s;
    p->data = 0;
    p->next = L;
    int num;
    scanf("%d",&num);
    while(num!=999){
        s = (XPNode)malloc(sizeof(XNode));
        s->data = num;
        s->next = p->next ;
        p->next = s;
        p = s;
        scanf("%d",&num);
    }
    XPNode q = p->next->next;
    while(q!=L){
        printf("%d ",q->data);
        q = q->next;
    }
    return p;
}


void ergodicXLinkList(XPNode L){
    // XPNode p = L->next;
    // while(p!=L){
    //     printf("%d ",p->data);
    //     p = p->next;
    // }

    // printf("%d ",L->next->next->data);
    // printf("%d ",L->next->next->next->data);
    // printf("%d ",L->next->next->next->next->data);
}
