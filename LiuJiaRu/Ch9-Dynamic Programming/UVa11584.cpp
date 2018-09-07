//Partitioning by Palindromes
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
char s[1010];
bool p[1010][1010];
int dp[1010];
int n;
void judge()
{
    memset(p, 0, sizeof(p));
    for (int i = 1;i<=n; i++)
    {
        int lef = i;
        int ri = i;
        while(lef>0&&ri<=n&&s[lef] == s[ri])
        {
            p[lef][ri] = 1;
            lef--;
            ri++;
        }
    }
    for (int i = 1;i<=n; i++)
    {
        int lef = i;
        int ri = i + 1;
        while (lef>0&&ri<=n&&s[lef] == s[ri])
        {
            p[lef][ri] = 1;
            lef--;
            ri++;
        }
    }
}
int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        scanf("%s", (s + 1));
        n = strlen(s + 1);
        judge();
        memset(dp, 0x3f, sizeof(dp));
        dp[0]=0;
        for (int i = 1; i <=n;i++)
        {
            for (int j = 0; j < i;j++)
            {
                if(p[j+1][i])
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}