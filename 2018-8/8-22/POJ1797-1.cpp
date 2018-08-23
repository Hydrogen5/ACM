//Heavy Transportation
//dijkstra
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#define MAXN 101000
using namespace std;
int arr[2 * MAXN], edge[2 * MAXN], Next[2 * MAXN], head[2 * MAXN];
int dis[MAXN], vis[MAXN];
int n, m;
int tot = 0;
inline void addedge(int x, int y, int z)
{
    arr[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}
void dijkstra()
{
    for (int i = 0; i <= n; i++)
    {
        dis[i] = 0;
        vis[i] = 0;
    }
    dis[1] = 0x3f3f3f3f;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0x3f3f3f3f, 1));
    while (!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = Next[i])
        {
            int y = arr[i];
            int z = edge[i];
            if (dis[y] < min(dis[x], z))
            {
                dis[y] = min(dis[x], z);
                pq.push(make_pair(dis[y], y));
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    for (int i = 1; i <= T; i++)
    {
        memset(head, 0, sizeof(head));
        tot = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            addedge(x, y, z);
            addedge(y, x, z);
        }
        dijkstra();
        printf("Scenario #%d:\n%d\n\n", i, dis[n]);
    }
    return 0;
}