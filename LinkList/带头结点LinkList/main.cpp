//
//  main.cpp
//  带头结点LinkList
//
//  Created by yinqiyu on 2021/1/20.
//


#include<stdio.h>
#include <stdlib.h>
typedef int Elemtype;

typedef struct LNode{       //定义单链表节点类型
    int data;               //每个节点存放一个数据元素
    struct LNode *next;     //指针指向下一个节点
}LNode, *LinkList;

//==================================
/**
* show 初始化一个单链表（带头结点）
* <p>show 方法的详细说明第一行<br>
* show 方法的详细说明第二行
* @param L true 表示显示，false 表示隐藏
* @return 没有返回值
*/
bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)          //内存不足，分配失败
        return false;
    L->next = NULL;         //头结点后暂时还没有节点
    return true;
}

//=====测试=========
void test(){
    LinkList L; //声明一个指向单链表的指针
    
    InitList(L);
}



//=============判断单链表是否为空（带头结点）==================
bool Empty(LinkList L){
    if(L->next == NULL)
        return true;
    else
        return false;
}

//===================指定结点的后插操作=====================
//  后插操作：在p结点之后插入元素e
bool InsertNextNode (LNode *p,Elemtype e){
    if(p==NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL)         //内存分配失败
        return false;
    s->data = e;        //用结点s保存数据e
    s->next = p->next;
    p->next = s;        //将结点s连接到p之后
    return true;
    
}

//======按位查找，返回地i个元素（带头结点）======

LNode * GetEllem(LinkList L, int i){
    if(i<0)
        return NULL;
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j<i){
        p = p->next;
        j++;
    }
    return p;
}

/**
* show 按值查找，找到数据域 == e 结点
 */
LNode * LocateElem(LinkList L,Elemtype e){
    LNode *p = L->next;
    //从第1个结点开始查找数据域为e的结点
    while (p != NULL && p->data !=e)
        p = p->next;
    return p;       //找到后返回该结点指针，否则返回NULL
}

//===求表的长度===
int Length(LinkList L){
    int len = 0;
    LNode *p = L;
    while (p->next != NULL){
        p = p->next;
        len++;
    }
    return len;
}

//============在第i个位置插入元素e（带头结点）================
bool ListInsert(LinkList &L,int i,Elemtype e){
    if(i<1)
        return false;
    LNode *p = GetEllem(L,i-1);
/*
    LNode *p;       //指针p指向当前扫描到的节点
    int j = 0;      //当前p指针指向的是第几个节点
    p = L;          //L之低昂头结点，头结点是第0个结点（不存数据）
    while (p!=NULL && j<i-1) {  //循环找到第i-1个结点
        p=p->next;
        j++;
    }
 */
/*    if(p==NULL)         //i值不合法
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;        //将结点s连到p后
    return true;        //插入成功
 */
    return InsertNextNode(p, e);
}


//=================前插操作：在p结点之前插入结点s================
//非常的amazing！！！

bool InsertPriorNode1(LNode *p,Elemtype e){
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL)       //内存分配失败
        return false;
    s->next = p->next;
    p->next = s;            //新节点s连接到p之后
    s->data = p->data;      //p的元素复制到s
    p->data = e;            //p的元素覆盖为e
    
    return true;
    
}

bool InsertPriorNode2(LNode *p,LNode *s){
    if(p==NULL || s==NULL)
        return false;
    s->next = p->next;
    p->next = s;
    Elemtype temp = p->data;
    p->data = s->data;
    s->data = temp;
    return true;
}


//==========================按位序删除======================
bool ListDelete(LinkList &L, int i,Elemtype &e){
    if(i<1)
        return  false;
    LNode *p = GetEllem(L, i-1);
    
/*
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL & j<i-1) {
        p = p->next;
        j++;
    }
 */
    if(p == NULL)
        return false;
    if(p->next == NULL)
        return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(p);
    return true;
}


//============删除指定结点p==============
bool DeleateNode (LNode *p){
    if(p == NULL)
        return  false;
    LNode *q = p->next;     //声明指针*q指向p的后继结点
    p->data = p->next->data;//把p的后继结点的数据复制到p结点
    p->next =q->next;       //断开q
    free(q);                //释放q
    return true;
}

//=====尾插法建立单链表===========
LinkList List_TailInsert(LinkList &L){      //正向建立单链表
    int x;                                  //设elemtype为整型
    L = (LinkList)malloc(sizeof(LNode));    //建立头节点（初始化空表）
    LNode *s,*r=L;                          //r为表尾指针
    scanf("%d",&x);                         //输入节点的值
    while(x!=9999){                         //输入9999表示结束
        s = (LNode *)malloc(sizeof(LNode)); //在r节点之后插入元素x
        s->data = x;
        r->next = s;
        r=s;                                 //r指向新的表尾节点（永远保持r指向最后一个节点）
        scanf("%d",&x);
    }
    r->next == NULL;                         //表尾节点指针为空
    return  L;
}

//=====头插法建立单链表(链表的逆置)===========
LinkList List_HeadInsert(LinkList &L){      //逆向建立单链表
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));    //创建头结点
    L->next = NULL;                         //初始链表为空
    scanf("%d",&x);                         //输入节点的值
    while(x != 9999){                       //输入9999表示结束
        s = (LNode *)malloc(sizeof(LNode)); //创建新节点
        s->data = x;
        s->next = L->next;
        L->next = s;                        //将新节点插入表中，L为头指针
        scanf("%d",&x);
    }
    return L;
}


int main(){
    return 0;
}
