//
//  main.cpp
//  堆排序：每一趟将堆顶元素加入有序子序列
//  (与待排序序列中的最后一个元素交换）
//  并将待排序元素序列再次调整为大根堆
// （小元素不断“下坠”）

//  Created by yinqiyu on 2021/8/10.
//

#include <iostream>
void swap(int a,int b);                   //交换
void BuildMaxHeap(int A[],int len);       //建立大根堆
void HeadAdjust(int A[],int k,int len);   //将以k为跟的子树调整为大根堆
void Heapsort(int A[],int len);           //堆排序

//交换
void swap(int a,int b){
    int temp = a;
    a = b;
    b = temp;
    
}

//建立大根堆
void BuildMaxHeap(int A[],int len){
    for(int i = len/2;i>0;i--)
        HeadAdjust(A,i,len);
}


//将以k为跟的子树调整为大根堆(下坠调整)
void HeadAdjust(int A[],int k,int len){
    A[0] = A[k];                        //A[0]暂存子树的根节点
    for(int i = 2*k;i<=len;i*=2){       //沿key交大的子节点向下筛选
        if(i<len && A[i]<A[i+1])        //判断左右子树哪个更大
            i++;                        //若右子树更大i指向右子树
        if(A[0]>=A[i]) break;           //筛选结果，如果跟大于子树 退出
        else{                           //否则
            A[k] = A[i];                //A[i]调整到双亲节点
            k = i;                      //修改k值 继续向下筛选
        }
    }
    A[k] = A[0];                        //被筛选节点的值放入最终位置
}

//堆排序
void Heapsort(int A[],int len){
    BuildMaxHeap(A,len);
    for(int i = len;i>1;i--){
        swap(A[i], A[1]);
        HeadAdjust(A, 1, i-1);
    }
    
}




void test(int &x){
    x = 6666;
    printf("test内部x = %d\n",x);
}

int main(int argc, const char * argv[]) {
    int x  = 1;
    printf("未调用test的x = %d\n",x);
    test(x);
    printf("调用test的x = %d\n",x);
    return 0;
}
