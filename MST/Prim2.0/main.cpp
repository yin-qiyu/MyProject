//
//  main.cpp
//  Prim2.0
//
//  Created by yinqiyu on 2021/6/21.
//

#include <iostream>
#include <algorithm>
#define ll 9999     //无穷大

using namespace std;

struct AMGraph
{
    char *vertices;     //定点表
    int *visited;        //蓝白点标志
    int **arcWeight;    //领接矩阵
    int currVex,currArc;    //当前的定点、边数
};

int get_Index(const AMGraph &G,char u)
{
    for(int i = 0;i<G.currVex;i++)
        if (u == G.vertices[i]) {
            return  i;    //获得顶点在顶点数组中的下标
        }
    return -1;
}

//void createUND
