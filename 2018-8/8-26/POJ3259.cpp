//Wormholes
//SPFA判负环
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
using namespace std;
int var[5050], edge[5050], Next[5050], head[5050];
int tot;
int vis[5050];
int dis[5050];
int cnt[5500];
queue<int> q;
int N;
void addedge(int x, int y, int z)
{
    var[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}
int SPFA()
{
    dis[1] = 0;
    vis[1] = 1;
    q.push(1);
    while (q.size())
    {
        int x = q.front();
        vis[x] = 0;
        q.pop();
        for (int i = head[x]; i; i = Next[i])
        {
            int y = var[i];
            int z = edge[i];
            if (dis[y] > dis[x] + z)
            {
                dis[y] = dis[x] + z;
                if (vis[y] == 0)
                {
                    q.push(y);
                    vis[y] = 1;
                    cnt[y]++;
                    if(cnt[y]>N)
                        return 1;
                }
            }
        }
    }
    return 0;
}
int main()
{
    int F;
    scanf("%d", &F);
    while (F--)
    {
        memset(dis, 0x3f, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));
        memset(head, 0, sizeof(head));
        while (q.size())
            q.pop();
        tot = 0;
        int M, W;
        scanf("%d%d%d", &N, &M, &W);
        while (M--)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            addedge(x, y, z);
            addedge(y, x, z);
        }
        while (W--)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            addedge(x, y, -z);
        }
        if (SPFA())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}