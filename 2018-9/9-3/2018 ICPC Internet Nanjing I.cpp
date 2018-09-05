
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

const int maxn = 2000000 + 10;

const ll mod = 1e9 + 7;

const ull bas = 100007;

ull p[maxn << 1], has[maxn << 1];

ll pw[maxn << 1], sum[maxn << 1];

const int MOD = 4000007;

int first[maxn << 1], nxt[maxn << 1], cnt = 0;

ull val[maxn << 1];

bool exist(ull now)

{

    int u = now % MOD;

    for (int i = first[u]; i; i = nxt[i])

        if (val[i] == now)
            return true;

    nxt[++cnt] = first[u];

    first[u] = cnt;

    val[cnt] = now;

    return false;
}

ull gethas(int l, int r)

{

    return has[r] - has[l - 1] * p[r - l + 1];
}

ll solve(int l, int r)

{

    ull tmp = gethas(l, r);

    if (exist(tmp))
        return 0;

    ll ans = sum[r] - sum[l - 1] * pw[(r - l + 1 + 1) / 2] % mod + mod;

    if (ans > mod)

        ans %= mod;

    return ans;
}

char Ma[maxn << 1];

int Mp[maxn << 1];

ll Manacher(char s[], int len)

{

    int l = 0;

    Ma[l++] = '$';

    Ma[l++] = '#';

    for (int i = 0; i < len; i++)

    {

        Ma[l++] = s[i];

        Ma[l++] = '#';
    }

    Ma[l] = 0;

    pw[0] = p[0] = 1;

    has[0] = sum[0] = 0;

    for (int i = 1; i <= l; i++)

    {

        p[i] = p[i - 1] * bas;

        has[i] = has[i - 1] * bas + Ma[i];

        pw[i] = pw[i - 1] * 10 % mod;

        if (Ma[i] >= '0' && Ma[i] <= '9')

            sum[i] = (sum[i - 1] * 10 + Ma[i] - '0') % mod;

        else

            sum[i] = sum[i - 1];
    }

    ll ans = 0;

    int mx = 0, id = 0;

    for (int i = 0; i < l; i++)

    {

        if (Ma[i] != '#')

            ans = (ans + solve(i, i)) % mod;

        Mp[i] = mx > i ? min(Mp[2 * id - i], mx - i) : 1;

        while (Ma[i + Mp[i]] == Ma[i - Mp[i]])

        {

            if (Ma[i + Mp[i]] != '#')

                ans = (ans + solve(i - Mp[i], i + Mp[i])) % mod;

            Mp[i]++;
        }

        if (i + Mp[i] > mx)

        {

            mx = i + Mp[i];

            id = i;
        }
    }

    return ans;
}

char s[maxn];

int main()

{

    scanf("%s", s);

    int len = strlen(s);

    printf("%lld\n", Manacher(s, len));

    return 0;
}
