//
//  main.c
//  kruskal2.0
//
//  Created by yinqiyu on 2021/6/20.
//

#include <stdio.h>

#include<stdio.h>
#include<stdlib.h>
#define MaxVexNum 50
#define MaxInt 32767
#define MaxEdgeNum 50
//邻接矩阵
typedef int VertexType;
typedef int EdgeType;
typedef struct AMGraph{
    VertexType vexs[MaxVexNum];//顶点表
    EdgeType arcs[MaxVexNum][MaxVexNum];//邻接矩阵表
    int vexnum,edgenum;//顶点数，边数
}AMGraph;
 
void createGraph(AMGraph &g){//创建无向图
    printf("请输入顶点数：");
    scanf("%d",&g.vexnum);
    printf("\n请输入边数：");
    scanf("%d",&g.edgenum);
    
    //初始化顶点表
    for(int i=1;i<=g.vexnum;i++){
        g.vexs[i]=i;
    }
    for(int i=1;i<=g.vexnum;i++){
        for(int j=1;j<=g.vexnum;j++){
            g.arcs[i][j]=MaxInt;
            if(i==j) g.arcs[i][j]=0;
        }
    }
    printf("请输入边的信息以及边的权值(顶点是0~n-1)\n");
    for(int i=0;i<g.edgenum;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        g.arcs[x][y]=w;
        g.arcs[y][x]=w;
    }
}
void PrintGraph(AMGraph g){
    printf("邻接矩阵为:\n");
    for(int i=1;i<=g.vexnum;i++) {
        printf("  %d",g.vexs[i]);
    }
    printf("\n");
    for(int i=1;i<=g.vexnum;i++){
        printf("%d ",g.vexs[i]);
        for(int j=1;j<=g.vexnum;j++){
            if(g.arcs[i][j]==MaxInt){
                printf("∞ ");
            }else{
                printf("%d  ",g.arcs[i][j]);
            }
        }
        printf("\n");
    }
}
 
//寻找根节点的函数
int GetRoot(int v[],int p){
    while(p!=v[p]){//依据根节点的数组下标和里面的值相同来找到根节点
        p=v[p];//若两个元素的根节点相同则属于同一颗树
    }
    return p;
}
void unionn(int v[],int p,int q){  //p加入q;
    v[q]=GetRoot(v,p);
}

void Kruskal(AMGraph g){
    int v[g.vexnum];//需要用到并查集，看是否选出的边的两个顶点是否已经归并，避免形成回路
    for(int i=1;i<=g.vexnum;i++) v[i]=i;//初始化并查集
    int sum=0;
    for(int q=1;q<=g.vexnum-1;q++){//连通一个图需要n-1条边，(n为顶点数)
    int x,y;
    int  min=MaxInt;
    for(int i=1;i<=g.vexnum;i++){
        for(int j=1;j<=g.vexnum;j++){
            if(g.arcs[i][j] <min&&g.arcs[i][j]>0&&GetRoot(v,i)!=GetRoot(v,j)){//选出的边不能形成回路
                min=g.arcs[i][j];
                x=i;
                y=j;
            }
        }
    }
                printf("[%d %d]\n",x,y);
                sum+=min;
                g.arcs[x][y]=0;//将这条边置零，以便选出次小边
                g.arcs[y][x]=0;//无向图
                unionn(v,y,x);
    }
    printf("\n最短路径长度为：%d\n",sum);
}

int main(){
    AMGraph g;
    createGraph(g);
    PrintGraph(g);
    Kruskal(g);
        system("pause");
}
