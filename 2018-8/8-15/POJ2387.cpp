//Til the Cows Come Home
#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int ver[2010], head[2010], edge[2010], Next[2010], dist[2010];
int vis[2010];
int N;
priority_queue<pair<int,int> > pq;
void dijkstra()
{
    memset(dist,0x3f,sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[1]=0;
    pq.push(make_pair(0, N));
    while(!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        if(vis[x]) continue;
        vis[x]=1;
        for (int i = head[x]; i;i=Next[x])
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
    int tot = 0;
    for (int i = 0; i < T;i++)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        ver[++tot] = y;
        edge[tot] = z;
        Next[tot] = head[x];
        head[x] = tot;
    }
    dijkstra();
    printf("%d\n", dist[1]);
}