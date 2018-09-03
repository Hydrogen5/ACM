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
#define inf 0x7f7f7f7f
using namespace std;
int n;
int arr[200010], edge[200010], head[200010], Next[200010];
int tot;
void addedge(int x, int y, int z)
{
    arr[++tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot;
}
int dfs(int id, int sum, int k)
{
    if (id == n)
    {
        return sum;
    }
    int Min = inf;
    for (int i = head[id]; i; i = Next[i])
    {
        int y = arr[i];
        int z = edge[i];
        Min = min(Min, dfs(y, sum + z, k));
        if (k > 0)
            Min = min(Min, dfs(y, sum, k - 1));
    }
    return Min;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(head, 0, sizeof(head));
        tot = 0;
        int m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            addedge(x, y, z);
        }
        int ans = dfs(1, 0, k);
        cout << ans << endl;
    }
    return 0;
}