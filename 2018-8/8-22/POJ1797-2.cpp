//Heavy Transportation
//SPFA
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
#define N 1000010
using namespace std;
int arr[N], edge[N], Next[N], head[N];
int vis[1010];
int dis[1010];
queue<int> q;
int n, m;
int tot;
inline void addedge(int x, int y, int z)
{
    arr[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}
void SPFA()
{
    for (int i = 0; i <= n; i++)
    {
        vis[i] = 0;
        dis[i] = 0;
    }
    dis[1] = 0x3f3f3f3f;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = head[x]; i; i = Next[i])
        {
            int y = arr[i];
            int z = edge[i];
            if (dis[y] < min(dis[x], z))
            {
                dis[y] = min(dis[x], z);
                if (!vis[y])
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
    int T;
    scanf("%d", &T);
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
        SPFA();
        printf("Scenario #%d:\n%d\n\n", i, dis[n]);
    }
    return 0;
}