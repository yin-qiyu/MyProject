//
//  main.cpp
//  LinkList
//
//  Created by yinqiyu on 2021/1/19.

//  不带头结点的单链表

#include<stdio.h>
#include <stdlib.h>
typedef int Elemtype;

typedef struct LNode{       //定义单链表节点类型
    int data;               //每个节点存放一个数据元素
    struct LNode *next;     //指针指向下一个节点
}LNode, *LinkList;

//========初始化一个空的单链表=========
bool InitList(LinkList &L){
    L = NULL;                //空表，暂时还没有任何节点--纺织脏数据
    return true;
}

//======测试======
void test(){
    LinkList L;     //声明一个指向单链表的指针
    InitList(L);    //初始化一个空表
}

//=========判断单链表是否为空===========
bool Empty(LinkList L){
    return (L==NULL);
}

//==========在第i个位置插入元素e（不带头结点）==============
bool ListInsert(LinkList &L,int i,Elemtype e){
    if(i<1)
        return false;
    if(i==1){
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;
    int j = 1;      //！！！！！这里是1！！！！！
    p = L;
    while (p!=NULL&&j<i-1) {
        p=p->next;
        j++;
    }
    if(p==NULL)         //i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;        //将结点s连到p后
    return true;        //插入成功
}
int main (){
    printf("hello word\n");
}
