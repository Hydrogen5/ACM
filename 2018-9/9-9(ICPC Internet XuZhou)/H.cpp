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
int n;
ll fir[100010]={0};
ll sec[100010]={0};
ll num[100010]={0};

void add1(int x, ll y)
{
    if (x == 0)
        return;
    for (; x <= n; x += x & -x)
        fir[x] += y;
}
void add2(int x, ll y)
{
    if (x == 0)
        return;
    for (; x <= n; x += x & -x)
        sec[x] += y;
}
ll ask1(int x)
{
    if (x == 0)
        return 0;
    ll ans = 0;
    for (; x; x -= x & -x)
        ans += fir[x];
    return ans;
}
ll ask2(int x)
{
    if (x == 0)
        return 0;
    ll ans = 0;
    for (; x; x -= x & -x)
        ans += sec[x];
    return ans;
}
int main()
{
    int q;
    scanf("%d%d", &n, &q);
    for (int i = n; i >= 1; i--)
        scanf("%lld", &num[i]);
    for (int i = 1; i <= n; i++)
    {
        add1(i, num[i]);
        add2(i, i * num[i]);
    }
    for (int i = 0; i < q; i++)
    {
        ll a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a == 1)
        {
            ll two = ask2(n - b + 1) - ask2(n - c);
            ll one = ask1(n - b + 1) - ask1(n - c);
            ll ans = two - (n - c) * one;
            printf("%lld\n", ans);
        }
        if (a == 2)
        {
            ll d = c - num[n - b + 1];
            add1(n + 1 - b, d);
            d = d * (n - b + 1);
            add2(n + 1 - b, d);
            num[n - b + 1] = c;
        }
    }
    return 0;
}
//后缀和，ai*(n-i+1)后缀和