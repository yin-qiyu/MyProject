//

//  LinerList
//
//  Created by yinqiyu on 2021/1/19.
//  动态数组
#include<stdio.h>
#include <stdlib.h>
#define Initsize 10 //默认最大初始长度
typedef struct {
    int *data;      //指示动态分配数组的指针
    int maxsize;    //顺序表的最大容量
    int length;     //顺序表的当前长度
}Seqlist;


//=========初始化=========
void Initlist(Seqlist &L){
    //用malloc 函数申请一片连续的存储空间
    L.data = (int *)malloc(Initsize*sizeof(int)); //返回开辟内存第一个data指针
    L.length = 0;
    L.maxsize = Initsize;
}

//=========动态增加数组的长度=========
void IncreaseSize(Seqlist &L,int len){
    int *p = L.data;
    L.data = (int *)malloc((L.maxsize + len)*sizeof(int));
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];       //将数据复制到新区域
    }
    L.maxsize = L.maxsize + len;    //顺序表最大长度增加len
    free(p);                          //释放原来的存储空间
}

//=========顺序表的按位查找=========
int GetElm(Seqlist L,int i){
    return L.data[i-1];
}

//======顺序表的按值查找=========
int LocateElem(Seqlist L,int e){
    for (int i = 0; i < L.length; i++)
        if(L.data[i] == e)
            return i+1;  //数组下标为i的元素值等于e，返回其位序i+1
    return 0;
}


//=========主函数===========
int main() {
    Seqlist L;
    Initlist(L);
    
    L.data[0] = 6; L.length++;
    L.data[1] = 2; L.length++;
    L.data[2] = 9; L.length++;
    L.data[3] = 4; L.length++;
    L.data[4] = 9; L.length++;
    L.data[5] = 3; L.length++;

    
    for (int i = 0; i<L.length; i++) {
        printf("data[%d]=%d\n",i,L.data[i]);
    }
    printf("L.length = %d\n",L.length);
    printf("%d\n",LocateElem(L, 9));
    
    return 0;
}



