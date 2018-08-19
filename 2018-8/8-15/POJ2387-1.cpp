//Til the Cows Come Home
//dijkstra+堆优化
#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int ver[4010], head[4010], edge[4010], Next[4010], dist[4010];
int vis[4010];
int N;
int tot = 0;
priority_queue<pair<int,int> > pq;
void addedge(int x,int y,int z)
{
    ver[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}
void dijkstra()
{
    memset(dist,0x3f,sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[1]=0;
    pq.push(make_pair(0, 1));
    while(!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for (int i = head[x]; i;i=Next[i])
        {
            int y = ver[i];
            int z = edge[i];
            if(dist[y]>dist[x]+z)
            {
                dist[y] = dist[x] + z;
                pq.push(make_pair(-dist[y], y));
            }
        }
    }
}
int main()
{
    int T;
    cin>>T>>N;
    for (int i = 0; i < T;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        addedge(x, y, z);
        addedge(y, x, z);
    }
    dijkstra();
    printf("%d\n", dist[N]);
}