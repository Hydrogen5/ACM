#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;
int main()
{
    int T;
    cin>>T;
    ll Maxn = 0;
    for (int l = 1; l <= T;l++)
    {
        Maxn = 0;
        char s[25];
        cin>>s;
        int len = strlen(s);
        for (int i = 1; i < len - 3;i++)
        {
            ll  a = 0;
            ll tmp = 1;
            for (int m = i - 1; m >= 0;m--)
            {
                a += (s[m] - '0') * tmp;
                tmp *= 10;
            }
            for (int j = i + 1; j < len - 2; j++)
            {
                ll b = 0;
                ll tmp = 1;
                for (int m = j - 1; m >= i;m--)
                {
                    b += (s[m] - '0') * tmp;
                    tmp *= 10;
                }
                for (int k = j + 1; k < len - 1; k++)
                {
                    ll c = 0;
                    ll tmp = 1;
                    for (int m = k - 1; m >= j;m--)
                    {
                        c += (s[m] - '0') * tmp;
                        tmp *= 10;
                    }
                    for (int m = k + 1; m < len; m++)
                    {
                        ll d = 0;
                        ll tmp = 1;
                        for (int n = m - 1; n >= k;n--)
                        {
                            d += (s[n] - '0') * tmp;
                            tmp *= 10;
                        }
                        ll e = 0;
                        tmp = 1;
                        for (int n = len-1; n >= m;n--)
                        {
                            e += (s[n] - '0') * tmp;
                            tmp *= 10;
                        }
                        ll ans = c * d;
                        ans /= e;
                        ans += a - b;
                        if(ans>Maxn)
                            Maxn = ans;
                    }
                }
            }
        }
        printf("Case #%d: %I64d\n", l, Maxn);
    }
}