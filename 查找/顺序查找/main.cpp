//
//  main.cpp
//  顺序查找
//
//  Created by yinqiyu on 2021/8/8.
//

#include <iostream>

typedef struct{
    int *elem;      //元素储存空间地址，建表时按世纪长度分配
    int TableLen; //表的长度
}
SSTable;

int Search_seq(SSTable ST,int key){
    int i;
    for (i = 0;i<ST.TableLen && ST.elem[i]!=key;++i);
        return i==ST.TableLen?-1:1;
}

int Search_seq2(SSTable ST,int key){
    ST.elem[0] = key;      //哨兵
    int i;
    for(i = ST.TableLen;ST.elem[i]!=key;--i);
    return i;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
