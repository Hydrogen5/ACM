//Til the Cows Come Home
//SPFA,BF+队列优化
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int head[4010];
int ver[4010];
int Next[4010];
int edge[4014];
int tot=0;
int vis[2010];
int dist[2010];
queue<int> q;
void addedge(int x,int y,int z)
{
    ver[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}
void spfa()
{
    memset(vis, 0, sizeof(vis));
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i = head[x];i;i=Next[i])
        {
            int y=ver[i];
            int z=edge[i];
            if(dist[y]>dist[x]+z)
            {
                dist[y]=dist[x]+z;
                if(!vis[y])
                {
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&m,&n);
    for (int i = 0;i<m;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        addedge(x, y, z);
        addedge(y, x, z);
    }
    spfa();
    printf("%d\n", dist[n]);
}