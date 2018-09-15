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
#define ll long long
using namespace std;
ll dp[6][2];
ll val[1010];
char opt[10];
ll Max[10];
ll Min[10];
int main()
{
    ll T;
    scanf("%d", &T);
    while (T--)
    {
        ll N, M, K;
        scanf("%lld%lld%lld", &N, &M, &K);
        for (ll i = 1; i <= N; i++)
            scanf("%lld", &val[i]);
        scanf("%s", (opt + 1));
        memset(dp, 0, sizeof(dp));
        memset(Max, 0, sizeof(Max));
        memset(Min, 0, sizeof(Min));
        for (ll i = 0; i <= M; i++)
        {
            dp[0][0] = K;
            dp[0][1] = K;
        }
        Max[0] = K;
        Min[0] = K;
        for (ll i = 1; i <= M; i++)
        {
            Max[i] = -100000000000000;
            Min[i] = 100000000000000;
        }
        for (ll i = 1; i <= N; i++)
        {
            for (ll j = 1; j <= M; j++)
            {
                if (i < j)
                    continue;
                if (opt[j] == '+')
                {
                    dp[j][0] = Max[j - 1] + val[i];
                    dp[j][1] = Min[j - 1] + val[i];
                }
                if (opt[j] == '-')
                {
                    dp[j][0] = Max[j - 1] - val[i];
                    dp[j][1] = Min[j - 1] - val[i];
                }
                if (opt[j] == '*')
                {
                    if (val[i] < 0)
                    {
                        dp[j][0] = Min[j - 1] * val[i];
                        dp[j][1] = Max[j - 1] * val[i];
                    }
                    else
                    {
                        dp[j][0] = Max[j - 1] * val[i];
                        dp[j][1] = Min[j - 1] * val[i];
                    }
                }
                if (opt[j] == '/')
                {
                    if (val[i] < 0)
                    {
                        dp[j][0] = Min[j - 1] / val[i];
                        dp[j][1] = Max[j - 1] / val[i];
                    }
                    else
                    {
                        dp[j][0] = Max[j - 1] / val[i];
                        dp[j][1] = Min[j - 1] / val[i];
                    }
                }
            }
            for (ll j = 1; j <= M; j++)
            {
                if (i < j)
                    continue;
                Max[j] = max(Max[j], dp[j][0]);
                Min[j] = min(Min[j], dp[j][1]);
            }
        }
        printf("%lld\n", Max[M]);
    }
    return 0;
}