//Unidirectional TSP
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
int dp[110][110];
int Next[110][110];
int Map[110][110];
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &Map[i][j]);
        memset(dp, 0x3f, sizeof(dp));
        memset(Next, 0, sizeof(Next));
        for (int i = 1; i <= n; i++)
            dp[i][m] = Map[i][m];
        for (int i = m - 1; i >= 1; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                int row[3] = {j, j - 1, j + 1};
                if (j == 1)
                    row[1] = n;
                if (j == n)
                    row[2] = 1;
                sort(row, row + 3);
                for (int k = 0; k < 3; k++)
                {
                    int tmp = dp[row[k]][i + 1] + Map[j][i];
                    if (tmp < dp[j][i])
                    {
                        dp[j][i] = tmp;
                        Next[j][i] = row[k];
                    }
                }
            }
        }
        int start = 0;
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++)
        {
            if (dp[i][1] < ans)
            {
                ans = dp[i][1];
                start = i;
            }
        }
        printf("%d", start);

        for (int i = Next[start][1], j = 1; j < m; j++, i = Next[i][j])
        {
            printf(" %d", i);
        }
        printf("\n%d\n", ans);
    }
    return 0;
}