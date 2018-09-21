//Frosting on the Cake
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
ll b[100010];
ll tmp[3];
ll ans[3];
int main()
{
    ll n;
    scanf("%lld", &n);
    for (ll i = 0; i < n; i++)
    {
        ll a;
        scanf("%lld", &a);
        tmp[i % 3] += a;
    }
    for (ll i = 0; i < n; i++)
        scanf("%lld", &b[i]);
    for(ll i=0;i<n;i++)
        for(ll j=0;j<3;j++)
            ans[(i + j) % 3] += tmp[j] * b[i];
    printf("%lld %lld %lld", ans[1], ans[2], ans[0]);
    return 0;
}