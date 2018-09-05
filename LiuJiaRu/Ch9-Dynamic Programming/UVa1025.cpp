//A Spy in the Metro
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
int dp[2100][20000];
int t[200];
int hastrain[210][20000][2];
int main()
{
    int N, kase = 0;
    while (scanf("%d", &N) == 1 && N)
    {
        int T;
        scanf("%d", &T);
        memset(hastrain, 0, sizeof(hastrain));
        for (int i = 1; i < N; i++)
            scanf("%d", &t[i]);
        int M1;
        scanf("%d", &M1);
        for (int i = 0; i < M1; i++)
        {
            int start;
            scanf("%d", &start);
            for (int j = 1; j <= N; j++)
            {
                hastrain[start][j][0] = 1;
                start += t[j];
                if (start > T)
                    break;
            }
        }
        int M2;
        scanf("%d", &M2);
        for (int i = 0; i < M2; i++)
        {
            int start;
            scanf("%d", &start);
            for (int j = N; j >= 1; j--)
            {
                hastrain[start][j][1] = 1;
                start += t[j - 1];
                if (start > T)
                    break;
            }
        }
        // for (int i = 1; i <= N ; i++)
        //     dp[N][i] = 0x3f3f3f3f;
        // dp[0][1] = 0;
        // for (int i = 0; i <= T - 1; i++)
        // {
        //     for (int j = 1; j <= N; j++)
        //     {
        //         dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
        //         if (j < N && hastrain[i][j][0] && (i + t[j] <= T))
        //             dp[i + t[j]][j + 1] = min(dp[i + t[j]][j + 1], dp[i][j]);
        //         if (j > 1 && hastrain[i][j][1] && (i + t[j - 1] <= T))
        //             dp[i + t[j - 1]][j - 1] = min(dp[i + t[j - 1]][j - 1], dp[i][j]);
        //     }
        // }
        for (int i = 1; i <= N - 1; i++)
            dp[T][i] = 0x3f3f3f3f;
        dp[T][N] = 0;
        for (int i = T - 1; i >= 0; i--)
        {
            for (int j = 1; j <= N; j++)
            {
                dp[i][j] = dp[i + 1][j] + 1;
                if (j < N && hastrain[i][j][0] && (i + t[j] <= T))
                    dp[i][j] = min(dp[i][j], dp[i + t[j]][j + 1]);
                if (j > 1 && hastrain[i][j][1] && (i + t[j - 1] <= T))
                    dp[i][j] = min(dp[i][j], dp[i + t[j - 1]][j - 1]);
            }
        }
        printf("Case Number %d: ", ++kase);
        if (dp[0][1] < 0x3f3f3f3f)
            printf("%d\n", dp[0][1]);
        else
            printf("impossible\n");
    }
    return 0;
}