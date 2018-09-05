// Tour
#include <algorithm>
#include <cmath>
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
struct node
{
    double x, y;
} p[1010];
int cmp(node a, node b)
{
    return a.x < b.x;
}
double dis[1010][1010];
double dp[1010][1010];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {

        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        if (n == 1)
        {
            printf("0.00\n");
            continue;
        }
        sort(p + 1, p + n + 1, cmp);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = hypot(p[i].x - p[j].x, p[i].y - p[j].y);
                dp[i][j] = 1000000000.0;
            }
        }
        dp[2][1] = dis[1][2];
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                dp[i + 1][i] = min(dp[i + 1][i], dp[i][j] + dis[j][i + 1]);
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dis[i][i + 1]);
            }
        }
        printf("%.2lf\n", dp[n][n - 1] + dis[n][n - 1]);
    }
    return 0;
}