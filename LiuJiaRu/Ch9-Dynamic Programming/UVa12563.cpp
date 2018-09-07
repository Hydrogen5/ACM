//Jin Ge Jin Qu hao
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;
int dp[10000];
int len[100];
int main() 
{
    int kase;
    scanf("%d",&kase);
    for(int it=1;it<=kase;it++)
    {
        int n,t;
        scanf("%d%d",&n,&t);
        for (int i = 1;i<=n;i++)
            scanf("%d",&len[i]);
        for(int i=0;i<=t;i++)
            dp[i] = -2147483647;
        dp[0] = 0;
        for (int i = 1; i <= n;i++)
        {
            for(int j=t;j>=0;j--)
            {
                if(len[i]<=j)
                {
                    dp[j] = max(dp[j], dp[j - len[i]] + 1);
                }
            }
        }
        int max = 0, sum = 0;
        for(int i=t-1;i>=0;i--)
        {
            if(dp[i]>max)
            {
                max=dp[i];
                sum = i;
            }
        }
        printf("Case %d: %d %d\n", it, max + 1, sum + 678);
    }
    return 0;
}