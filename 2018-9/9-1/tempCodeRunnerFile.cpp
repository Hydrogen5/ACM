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
int a[25], b[25], pre[25];
int dp[22][1<<(21)][2];
int main()
{
    int n;
    scanf("%d", &n);
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++)
    {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        a[i] = x;
        b[i] = y;
        for (int j = 0; j < k; j++)
        {
            int t;
            scanf("%d", &t);
            pre[i] |= 1 << (t - 1);
        }
    }
    int Max = 0;
    dp[0][0][0] = 1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(1<<(n));j++)
        {
            if(dp[i-1][j][0]==0)
                continue;
            for(int k=1;k<=n;k++)
            {
                if(j>>(k-1)&1)
                    continue;
                if((pre[k]&j)==pre[k])
                {
                    dp[i][j | (1 << (k - 1))][1] = dp[i - 1][j][1] + i * a[k] + b[k];
                    Max = max(dp[i][j | (1 << (k - 1))][1], Max);
                    dp[i][j | (1 << (k - 1))][0] = 1;
                }
            }
        }
    }
    cout << Max << endl;
}