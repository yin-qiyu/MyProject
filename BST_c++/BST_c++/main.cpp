//
//  main.cpp
//  BST
//
//  Created by yinqiyu on 2021/6/13.
//

#include <iostream>
#define TRUE 1
#define FALSE 0
//二叉排序树节点
typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//函数声明
int BST_Insert(BSTree &T,int k);
void Creat_BST(BSTree &T,int str[],int n);
void order(BSTree t);
int DeleteBST(BSTree *T, int key);
int Delete(BSTree *p);
BSTNode *BST_Search(BSTree T,int key);

/**
 函数名：BST_Insert
 函数作用：在二叉排序树插入关键字为k的新节点（递归）
 
 若原二叉排序树为空，则知己诶插入结点，否则
 若关键字k小于根节点的值，则插入到左子树，
 若关键字k'大于根节点的值，则插入到右子树
 */
int BST_Insert(BSTree &T,int k){
    if(T==NULL){                              //原树为空，新插入的节点为根节点
        T = (BSTree)malloc(sizeof(BSTree));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return  1;                             //返回1 插入成功
    }
    else if(k == T->key)                        //树种存在相同关键字的节点，插入失败
        return 0;
    else if (k<T->key)
        return BST_Insert(T->lchild,k);         //插到T的左子树
    else
        return BST_Insert(T->rchild,k);         //插到T的右子树
}

/**
 函数名：Creat_BST
 函数作用：二叉树的构造
 
 按照str{}中关键字序列建立二叉排序树
 */
void Creat_BST(BSTree &T,int str[],int n){
    T = NULL;
    int i = 0;
    while(i<n){
        BST_Insert(T, str[i]);
        i++;
    }
}

/**
 函数名：order
 函数作用：中序输出
 */
void order(BSTree t)//中序输出
{
    if(t == NULL)
        return ;
    order(t->lchild);
    printf("%d ", t->key);
    order(t->rchild);
}


/**
 函数名：DeleteBST
 函数作用：二叉排序树的删除
 
 若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素节点
 并返回TRUE；否则返回FALSE
 */
int DeleteBST(BSTree *T, int key)
{

    if( !(*T))
        return FALSE;    //不存在关键字等于key的数据元素
    else
    {
        if( key == (*T)->key )  //如果key等于这个节点
            Delete(T);
        else if( key < (*T)->key)
            return DeleteBST(&(*T)->lchild, key);      //若key小于节点，那么节点在左子树
        else
            return DeleteBST(&(*T)->rchild, key);      //若key小于节点，那么节点在右子树
    }
    return TRUE;
}

int Delete(BSTree *p)
{
    /* 从二叉排序树中删除节点p， 并重接它的左或右子树 */
    BSTree q, s;                              //q 双亲节点，s每次迭代用到的节点
    if(  !(*p)->lchild && !(*p)->rchild )    //p为叶子节点
        *p = NULL;
    else if( !(*p)->lchild )    //左子树为空，重接右子树
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else if( !(*p)->rchild )    //右子树为空
    {
        q = *p;                 
        *p = (*p)->lchild;      //左子树的值给自己
        free(q);
    }
    else                        //左右子树均不为空
    {
        q = *p;
        s = (*p)->lchild;
        while(s->rchild)        // 转左，然后向右走到尽头,找到最右的右子树s
        {
            q = s;              //q指向s的前驱
            s = s->rchild;
        }
        (*p)->key = s->key;     //把s的数据给p
        if( q != *p )                // 判断是否执行上述while循环
            q->rchild = s->lchild;   // 执行上述while循环，重接右子树
        else
            q->lchild = s->lchild;    // 未执行上述while循环，重接左子树
        free(s);
    }
    return TRUE;
}

////删除操作2
//BSTNode *DeleteBST2(BSTree T,int key){
//    if(!T){
//        return FALSE;
//    }
//    else{
//        if(key == T->key){
//            return Delete();
//        }
//    }
//}

/**
 函数名：BST_Search
 函数作用：在二叉排序树中查找值为key的节点

 若树非空，目标值与根节点的值比较
 若相等，则查找成功
 若小于根节点，则在左子树，否则在右子树上查找
 查找成功，返回节点指针，查找失败返回null
 */
//在二叉排序树中查找值为key的节点
//BSTNode *BST_Search(BSTree T,int key){
//    while(T!=NULL&&key!=T->key){        //若树空或等于根节点的值，则结束循环
//        if(key<T->key) T = T->lchild;   //小于，则在左子树上查找
//        else T=T->rchild;               //大于，则在右子树上查找
//    }
//    return T;
//}

//在二叉排序树中查找值为key的节点（递归）
BSTNode *BST_Search(BSTree T,int key){
    if (T == NULL)
        return NULL;                        //查找失败
    if(key==T->key)
        return T;                           //查找成功
    else if (key<T->key)
        return BST_Search(T->lchild, key);  //在左子树查
    else
        return BST_Search(T->rchild, key);  //在右子树查找
}



//主函数
int main() {
    
    //int a[8] = {50,66,60,26,21,30,70,68};
    //int a[8] = {26,21,30,50,60,66,68,70};
    //int a[10] = {62,88,58,47,35,73,51,99,37,93};
    //int a[] = {8,11,13,19,21,26,30,50,60,61,63,65,66,70};
    int a[10] = {19,13,50,11,26,66,21,30,60,70};
    
    BSTree T = NULL;
    Creat_BST(T,a,10);
    for (int i = 0; i<10; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
        
    printf("查找值为");                       //查找
    BSTNode *T1 = BST_Search(T,19);
    if (T1) {
        printf("%d\n",T1->key);
    }
    else
        printf("NULL");
    printf("\n");
    
    printf("中序遍历二叉排序树：\n");           //遍历
    order(T);
    printf("\n");
    
    printf("插入12后，中序遍历二叉排序树:\n");   //插入
    BST_Insert(T, 12);
    order(T);
    printf("\n");
    
    printf("删除50后，中序遍历二叉排序树：\n");  //删除
    DeleteBST(&T,50);
    order(T);
    printf("\n");
    
}

