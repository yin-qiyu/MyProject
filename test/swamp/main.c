//
//  main.c
//  swamp
//
//  Created by yinqiyu on 2021/12/23.
//

#include <stdio.h>
void Swap(int *p1,int *p2);
void Reverse(int *arr,int len);

int main(int argc, const char * argv[]) {
    int arr[5] = {1,2,3,4,5};
    Reverse(arr, sizeof(arr)/sizeof(arr[0]));
//    printf("%d",sizeof(arr)/sizeof(arr[0]));
//    printf("\n");
    for(int i = 0;i<=sizeof(arr)/sizeof(arr[0]);i++){
        printf("%d",arr[i]);
        
    }
    printf("\n");
    
}

void Reverse(int *arr,int len){
    for(int i = 0;i<=len/2;i++){
        Swap(arr+i,arr+len-1-i);
    }
}

void Swap(int *p1,int *p2){
    *p1=*p1^*p2;
    *p2=*p1^*p2;
    *p1=*p1^*p2;
}
