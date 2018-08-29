//Tree
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
int arr[100010], edge[100010], Next[100010], head[100010];
int tot;
int maxi = -1;
int cost[300000];
int cost1[300000];
void addedge(int x, int y, int z)
{
    arr[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}
int bfs(int x)
{
    memset(cost, -1, sizeof(cost));
    queue<int> q;
    q.push(x);
    cost[x] = 0;
    int d = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = Next[i])
        {
            int v = arr[i];
            int w = edge[i];
            if (cost[v] == -1)
            {
                cost[v] = cost[u] + w;
                if (maxi < cost[v])
                {
                    d = v;
                    maxi = cost[v];
                }
                q.push(v);
            }
        }
    }
    return d;
}
int main()
{
    freopen("i.in", "r", stdin);
    int N;
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        addedge(x, y, z);
        addedge(y, x, z);
    }
    int x = bfs(1);
    x = bfs(x);
    for (int i = 1; i <= N; i++)
        cost1[i] = cost[i];
    bfs(x);
    for (int i = 1; i <= N; i++)
        printf("%d\n", max(cost[i], cost1[i]));

    return 0;
}