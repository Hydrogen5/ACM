//Lighting System Design
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
struct node
{
    int v, k, c, l;
} b[1010];
int s[1010];
int dp[1010];
int cmp(node a, node b)
{
    return a.v < b.v;
}
int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d%d%d%d", &b[i].v, &b[i].k, &b[i].c, &b[i].l);
        sort(b + 1, b + n + 1, cmp);
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] = min(dp[i], dp[j] + (s[i] - s[j]) * b[i].c + b[i].k);
            }
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}