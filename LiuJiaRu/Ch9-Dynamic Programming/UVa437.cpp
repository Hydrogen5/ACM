//The Tower of Babylon
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
    int x, y, z;
} block[200];
int dp[200];
int cmp(node a, node b)
{
    return a.x * a.y < b.x * b.y;
}
int main()
{
    int n, kase = 1;
    while (scanf("%d", &n) == 1 && n)
    {
        for (int i = 0; i < 6 * n; i += 6)
        {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            block[i].x = a;
            block[i].y = b;
            block[i].z = c;
            block[i + 1].x = a;
            block[i + 1].y = c;
            block[i + 1].z = b;
            block[i + 2].x = b;
            block[i + 2].y = a;
            block[i + 2].z = c;
            block[i + 3].x = b;
            block[i + 3].y = c;
            block[i + 3].z = a;
            block[i + 4].x = c;
            block[i + 4].y = a;
            block[i + 4].z = b;
            block[i + 5].x = c;
            block[i + 5].y = b;
            block[i + 5].z = a;
        }
        sort(block, block + 6 * n, cmp);
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < 6 * n; i++)
        {
            dp[i] = block[i].z;
            for (int j = 0; j < i; j++)
            {
                if (block[j].x < block[i].x && block[j].y < block[i].y)
                {
                    dp[i] = max(dp[i], dp[j] + block[i].z);
                }
                ans = max(ans, dp[i]);
            }
        }
        printf("Case %d: maximum height = %d\n", kase++, ans);
    }
    return 0;
}