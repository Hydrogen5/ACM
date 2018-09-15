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
#define MOD 1000000007
#define ll long long
using namespace std;
int c[2200];
ll dp[10010];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int cnt = 0;
        int N, Q;
        scanf("%d%d", &N, &Q);
        for (int i = 1; i <= N; i++)
        {
            int tmp1, tmp2;
            scanf("%d%d", &tmp1, &tmp2);
            for (int i = 0; i < tmp2; i++)
                c[cnt++] = (1 << i) * tmp1;
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < cnt; i++)
        {
            for (int j = 10000; j >= c[i]; j--)
            {
                if (j >= c[i])
                {
                    dp[j] += dp[j - c[i]];
                    dp[j] %= MOD;
                }
            }
        }
        while (Q--)
        {
            int m;
            scanf("%d", &m);
            printf("%lld\n", dp[m]);
        }
    }
    return 0;
}