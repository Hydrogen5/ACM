//Ingredients
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
map<string, int> dic;
struct Edge
{
    int to, Next, cost, pres;
} edge[1000010];
int vis[10010];
int head[1000010];
int tot;
int Min[10010], Max[10010];
int road[10010];
int dp[10010];
void addedge(int u, int v, int cost, int pres)
{
    edge[tot].to = v;
    edge[tot].Next = head[u];
    edge[tot].pres = pres;
    edge[tot].cost = cost;
    head[u] = tot++;
}
void dijkstra(int s)
{
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));
    Min[s] = 0;
    Max[s] = 0;
    while (!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = head[x]; i!=-1; i = edge[i].Next)
        {
            int y = edge[i].to;
            if (Min[y] > Min[x] + edge[i].cost)
            {
                Min[y] = Min[x] + edge[i].cost;
                Max[y] = Max[x] + edge[i].pres;
                pq.push(make_pair(-Min[y], y));
            }
            else if (Min[y] == Min[x] + edge[i].cost && Max[y] < Max[x] + edge[i].pres)
            {
                Max[y] = Max[x] + edge[i].pres;
                pq.push(make_pair(-Min[y], y));
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int B, N;
    cin>>B>>N;
    memset(head, -1, sizeof(head));
    int cnt = 1;
    for (int i = 1; i <= N; i++)
    {
        string x, y, tmp;
        cin >> y >> x >> tmp;
        int cost, pres;
        cin>>cost>>pres;
        if (!dic.count(x))
            dic[x] = cnt++;
        int u = dic[x];
        if (!dic.count(y))
            dic[y] = cnt++;
        int v = dic[y];
        addedge(u, v, cost, pres);
        road[v] = 1;
    }
    memset(Max, 0, sizeof(Max));
    memset(Min, 0x3f, sizeof(Min));
    for (int i = 1; i < cnt; i++)
        if (!road[i])
            dijkstra(i);
    for (int i = 1; i < cnt; i++)
        for (int j = B; j >= Min[i]; j--)
            dp[j] = max(dp[j], dp[j - Min[i]] + Max[i]);
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i <= B; i++)
    {
        if (dp[i] > ans1)
        {
            ans1 = dp[i];
            ans2 = i;
        }
    }
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}