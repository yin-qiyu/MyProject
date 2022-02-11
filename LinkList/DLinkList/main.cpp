//
//  main.cpp
//  DLinkList
//  双链表
//  Created by yinqiyu on 2021/3/7.
//

#include <iostream>
typedef int ElemType;
typedef  struct Dnode {                     //D:double
    ElemType data;
    struct Dnode *priro, *next;             //前驱和后继结点
}Dnode,*DLinkList;


//初始化双链表
bool InitDLinkList(DLinkList &L){
    L = (Dnode *)malloc(sizeof(Dnode));     //分配头结点
    if(L == NULL)                           //内存不足，分配失败
        return  false;
    L->priro = NULL;                        //头结点的priro永远指向null
    L->next = NULL;                         //头结点之后暂时还没有节点
    return true;
}

//判断双链表是否为空（带头结点）
bool Empty(DLinkList L){
    if(L->next == NULL)
        return true;
    else
        return false;
}

//在p节点之后插入s节点
//****注意顺序****
bool InsertNextNode(Dnode *p,Dnode *s){
    if(p==NULL || s==NULL)      //非法参数
        return false;
    s->next = p->next;
    if(p->next!=NULL)           //如果p节点有后继结点
        p->next->priro = s;
    s->priro = p;
    p->next = s;
    return true;
}

//删除p节点的后继结点
bool DeleatNextDNode(Dnode *p){
    if(p == NULL) return false;
    Dnode *q = p->next;             //找到p的后继结点q
    if(q == NULL) return false;     //p没有后继
    p->next = q->next;
    if(q->next != NULL)             //q接地那不是最后一个节点
        q->next->priro = p;
    free(q);                        //释放节点空间
    return true;
}

void DestroyList(DLinkList &L){
    //循环释放各个数据节点
    while (L->next != NULL)
        DeleatNextDNode(L);
    free(L);
    L = NULL;
}

void testDLinkList(Dnode *p){
    //初始化双链表
    DLinkList L;
    InitDLinkList(L);
    
    while(p != NULL){
        //向后遍历
        p = p->next;
    }
    
    while(p != NULL ){
        //向前遍历
        p = p->priro;
    }
    
    while(p->priro != NULL){
        //对节点p做相应处理
        p = p->priro;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, DLINKLIST\n";
    return 0;
}
