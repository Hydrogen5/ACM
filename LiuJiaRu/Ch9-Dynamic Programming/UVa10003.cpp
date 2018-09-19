//Cutting Sticks
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
int len;
int n;
int a[60];
int dp[70][70];
int solve(int l, int r)
{
    if (l >= r)
        return 0;
    if (r - l == 1)
        return a[r] - a[l];
    for (int k = l + 1; k < r; k++)
    {
        if (dp[l][k] == 0x3f3f3f3f)
            dp[l][k] = solve(l, k);
        if (dp[k][r] == 0x3f3f3f3f)
            dp[k][r] = solve(k, r);
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r] + a[r] - a[l]);
    }
    return dp[l][r];
}
int main()
{
    while (scanf("%d", &len) == 1 && len)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        a[0] = 0;
        a[n + 1] = len;
        memset(dp, 0x3f, sizeof(dp));
        printf("The minimum cutting is %d.\n", solve(0, n + 1)-len);
    }
    return 0;
}