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
int dp[110000];
char s[110000];
int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int sum = 0;
        for (int i = 0; i <= n - 1; i++)
        {
            dp[i] = 0;
            for (int j = i + 1; j<=n;j++)
            {
                if (s[j] == '1')
                    dp[j] = dp[j - 1] + 1 + (dp[j - 1]) % 2;
                else
                    dp[j] = dp[j - 1] + 1 + (dp[j - 1]+1) % 2;
                sum += dp[j];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}