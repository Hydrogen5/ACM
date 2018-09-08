//Longest Run on a Snowboard
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
char name[100];
int n, m, Map[101][101];
int dp[101][101], walk[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void dfs(int a, int b, int k)
{
    for (int p, q, i = 0; i < 4; i++)
    {
        p = a + walk[i][0], q = b + walk[i][1];
        if (p >= 1 && p <= n && q >= 1 && q <= m && (k + 1) > dp[p][q] && Map[a][b] < Map[p][q])
        {
            dp[p][q] = k + 1;
            dfs(p, q, k + 1);
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int maxn = 1;
        scanf("%s", name);
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &Map[i][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (!dp[i][j])
                    dfs(i, j, 1);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                maxn = max(maxn, dp[i][j]);
        printf("%s: ", name);
        printf("%d\n", maxn);
    }
    return 0;
}