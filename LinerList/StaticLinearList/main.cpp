//
//  main.cpp
//  staticLinearList
//
//  Created by yinqiyu on 2021/1/19.
//  静态数组插入删除操作

#include<stdio.h>
#include <stdlib.h>
#define MaxSize 10              //定义最大长度

typedef struct {
    int data[MaxSize];          //用静态的数组存放数据元素
    int length;                 //顺序表的房钱长度
}Sqlist;                        //顺序表的类型定义

//==========初始化==========
void InitList(Sqlist &L){
//    for (int i = 0; i < MaxSize; i++) {
//        L.data[i] = 0;
//    }
    L.length = 0;
}

//==========插入操作=========
bool ListInsert(Sqlist &L,int i,int e){
    if(i < 1||i>L.length+1){    //判断i的范围是否有效
        return false;
    }
    if(L.length>=MaxSize){      //当前存储空间已满，不能插入
        return false;
    }
    for (int j = L.length; j>= i ; j--) //将第i个元素以及之后的元素往后移
        L.data[j] = L.data[j-1];
    L.data[i-1] = e;                    //在位置i放入e
    L.length++;                         //长度加1
    return  true;
}

//==========删除操作=========
bool ListDelete(Sqlist &L,int i,int &e){
    if(i < 1||i>L.length)            //判断i的范围是否有效
        return  false;
    e = L.data[i-1];                 //将被删除的元素赋值给e
    for (int j = i; j<L.length; j++) //将第一个位置后的元素前移
        L.data[j-1] = L.data[j];
    L.length--;                      //线性表的长度减1
    return true;
}

//=========顺序表的按位查找=========
int GetElm(Sqlist L,int i){
    return L.data[i-1];
}

//=======顺序表的按值查找==========

//=============主函数==============
int main() {
    Sqlist L;
    InitList(L);
    for (int i = 0; i<5; i++) {  //给数组赋值
        L.data[i] = i+1;
        L.length++;
    }
//----插入操作----
//    printf("插入前L.length = %d\n",L.length);
//    ListInsert(L, 3, 9);
//    printf("插入后L.length = %d\n",L.length);
//    for (int i = 0; i<L.length; i++) {
//        printf("L.data[%d] = %d\n",i,L.data[i]);
//    }
//----删除操作----
//    int e = -1;
//    if(ListDelete(L, 3, e))
//        printf("已经删除第3个元素，删除元素值为=%d\n",e);
//    else
//        printf("位序i不合法，删除失败\n");
    

//------顺序表的按位查找操作------
    printf("查找的元素为：%d\n",GetElm(L, 3));
    return 0;
    
}

