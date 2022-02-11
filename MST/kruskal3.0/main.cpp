//
//  main.cpp
//  kruskal3.0
//
//  Created by yinqiyu on 2021/6/21.
//

#include <iostream>
using namespace std;
#define max 32767
typedef struct {
    char vexs[100];//顶点表
    int arcs[100][100];//邻接矩阵表
    int vexnum,arcnum;//顶点数，边数
}AMGraph;

struct{
    char head;  //头
    char tail;  //尾
    int lowcost; //权值
}Edge[99*50];

//集合
int Vexset[100];

//查找
int LocateVex(AMGraph G,char v){
    for(int i = 0;i<G.vexnum;++i)
        if(G.vexs[i] == v)
            return i;
    return -1;
}

//生成无向图
void CreateUDN(AMGraph &G){
    int i,j,k;
    //输入顶点数、边数
    cout<<"请输入顶点数和边数(空格分开):"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<endl;
    
    cout<<"请输入顶点："<<endl;
    for (i = 0; i<G.vexnum; ++i) {
        cout<<"the"<<(i+1)<<" name of vex"<<endl;
        cin>>G.vexs[i];
    }
    
    //初始化矩阵
    for(i = 0;i<G.vexnum;++i)
    {
        for(j = 0;j<G.vexnum;++j)
        {
            G.arcs[i][j]=max;
        }
    }
    
    cout<<"请输入权值例如 a b 7"<<endl;
    for(k = 0;k<G.arcnum;++k){
        char v1,v2;//定义头和尾
        char weight;//定义权值
        cout<<"请输入"<<(k+1)<<" two arc end name and weight"<<endl;
        cin>>v1>>v2>>weight;
        i = LocateVex(G, v1);//拿序号
        j = LocateVex(G, v2);
        G.arcs[i][j] = weight;
        G.arcs[j][i] = G.arcs[i][j];
        Edge[k].lowcost = weight;
        Edge[k].head    = v1;
        Edge[k].tail    = v2;
    }
}

//排序
void sort(AMGraph G){
    int m = G.arcnum-2;
    int flag = 1;
    while((m>0)&&flag == 1){
        flag = 0;
        for (int i = 0;i <= m;i++)
        {
            if(Edge[i].lowcost>Edge[i+1].lowcost){
                flag = 1;
                char headtemp;
                headtemp = Edge[i].head;
                Edge[i].head=Edge[i+1].head;
                Edge[i+1].head = headtemp;
                
                char tailtemp;
                tailtemp = Edge[i].tail;
                Edge[i].tail=Edge[i+1].tail;
                Edge[i+1].tail = tailtemp;
                
                int lowcosttamp;
                lowcosttamp = Edge[i].lowcost;
                Edge[i].lowcost=Edge[i+1].lowcost;
                Edge[i+1].lowcost = lowcosttamp;
            }
        }
        --m;
    }
}

void kruskal(AMGraph G){
    int i,j,v1,v2,vs1,vs2,sum=0;
    sort(G);
    for(i = 0;i<G.vexnum;++i)
        Vexset[i] = i;
    for(i = 0;i < G.arcnum;++i)
    {
        v1 = LocateVex(G, Edge[i].head);
        v2 = LocateVex(G, Edge[i].tail);
        vs1 = Vexset[v1];
        vs2 = Vexset[v2];
        if (vs1!=vs2) {
            cout<<Edge[i].head<<"-->"<<Edge[i].tail<<"权值为"<<endl; //输出一条边
            for(j = 0;j < G.vexnum;++j)
                if(Vexset[j] == vs2)
                {
                    Vexset[j] = vs1; //把两个节点放到一个集合里面
                    
                }
        }
    }
    
}


int main()
{
    AMGraph G;
    CreateUDN(G);
    cout<<endl;
    kruskal(G);
    
    return 0;
}
