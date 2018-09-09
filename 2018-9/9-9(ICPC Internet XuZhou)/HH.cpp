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
ll fir[100010];
ll sec[100010];
ll num[100010];
ll ch[100010];
int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    fir[n + 1] = 0;
    sec[n + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        fir[i] = fir[i + 1] + num[i];
        sec[i] = sec[i + 1] + num[i] * (n - i + 1);
    }
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == 1)
        {
            ll ans = sec[b] - sec[c + 1] - (n - c) * (fir[b] - fir[c + 1]);
            for (int j = b; j <= c; j++)
            {
                ans += ch[j] * (c - j + 1);
            }
            printf("%lld\n", ans);
        }
        if (a == 2)
        {
            ch[b] += (c - num[b]);
            num[b] = c;
        }
    }
    return 0;
}
//后缀和，ai*(n-i+1)后缀和