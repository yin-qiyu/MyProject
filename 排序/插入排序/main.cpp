//
//  main.cpp
//  插入排序
//
//  Created by yinqiyu on 2021/8/9.
//

#include <iostream>



//直接插入法
void InsertSort(int A[],int n){
    int i,j,temp;
    for (i=1; i<n; i++)
        if(A[i]<A[i-1]){
            temp = A[i];
            for (j = i-1; j>0 && A[j]>temp;--j)
                A[j+1] = temp;
        }
}

//直接插入法(带哨兵)
void InsertSort2(int A[],int n){
    int i,j;
    for (i = 2; i<=n; i++)
        if (A[i]<A[i-1]) {
            A[0] = A[1];
            for (j = i-1; A[0]<A[j]; --j)
                A[j+1] = A[j];
            A[j+1]=A[0];
        }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
