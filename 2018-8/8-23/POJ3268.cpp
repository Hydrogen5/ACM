//Silver Cow Party
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
#define inf 0x3f3f3f3f
using namespace std;
int roads[1010][1010];
int dist1[1010], dist2[1010];
int vis[1010];
int n, m, x;
void dij1()
{
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int, int>> pq;
    dist1[x] = 0;
    pq.push(make_pair(0, x));
    while (pq.size())
    {
        int v = pq.top().second;
        pq.pop();
        if (vis[v])
            continue;
        vis[v] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (dist1[i] > dist1[v] + roads[v][i])
            {
                dist1[i] = dist1[v] + roads[v][i];
                pq.push(make_pair(-dist1[i], i));
            }
        }
    }
}
void dij2()
{
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int, int>> pq;
    dist2[x] = 0;
    pq.push(make_pair(0, x));
    while (pq.size())
    {
        int v = pq.top().second;
        pq.pop();
        if (vis[v])
            continue;
        vis[v] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (dist2[i] > dist2[v] + roads[i][v])
            {
                dist2[i] = dist2[v] + roads[i][v];
                pq.push(make_pair(-dist2[i], i));
            }
        }
    }
}
int main()
{
    cin >> n >> m >> x;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            roads[i][j] = inf;
        }
        roads[i][i] = 0;
        dist1[i] = inf;
        dist2[i] = inf;
    }
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        roads[a][b] = min(c, roads[a][b]);
    }
    dij1();
    dij2();
    int Max = 0;
    for (int i = 1; i <= n; i++)
    {
        Max = max(Max, dist1[i] + dist2[i]);
    }
    cout << Max << endl;
    return 0;
}