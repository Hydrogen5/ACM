//Networking
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
struct Edge
{
    int v1, v2, weight;
} edge[550];
int pre[3000];
int find(int x)
{
    if (pre[x] != x)
        pre[x] = find(pre[x]);
    return pre[x];
}
int cmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}
int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        for (int i = 1; i <= n; i++)
            pre[i] = i;
        int eds;
        scanf("%d", &eds);
        for (int i = 0; i < eds; i++)
            scanf("%d %d %d", &edge[i].v1, &edge[i].v2, &edge[i].weight);
        sort(edge, edge + eds, cmp);
        int cnt = 0, ans = 0;
        for (int i = 0; i < eds; i++)
        {
            if (cnt == n - 1)
                break;
            int px = find(edge[i].v1);
            int py = find(edge[i].v2);
            if (px == py)
                continue;
            pre[px] = py;
            cnt++;
            ans += edge[i].weight;
        }
        cout << ans << endl;
    }
    return 0;
}