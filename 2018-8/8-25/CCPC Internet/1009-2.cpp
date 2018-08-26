#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define LL long long
#define MAXV 100005
#define MAXE 100005
#define MOD 1000000007

inline bool scan_d(LL &num)
{
    char in; bool IsN = false;
    in = getchar();
    if (in == EOF) return false;
    while (in != '-' && (in<'0' || in>'9')) in = getchar();
    if (in == '-') { IsN = true; num = 0; }
    else num = in - '0';
    while (in = getchar(), in >= '0'&&in <= '9') {
        num *= 10, num += in - '0';
    }
    if (IsN) num = -num;
    return true;
}


struct Edge
{
    LL from;
    LL to;
    LL val;
    LL nxt;
}edge[MAXE];



LL head[MAXV];
LL sum[MAXV];
LL deep[MAXV];
LL vis[MAXV];

LL cnte;

void addE(LL from, LL to, LL val)
{
    edge[cnte].from = from;
    edge[cnte].to = to;
    edge[cnte].val = val;

    edge[cnte].nxt = head[from];
    head[from] = cnte++;
}


void init()
{
    memset(head, -1, sizeof(head));
    memset(sum, 0, sizeof(sum));
    memset(deep, 0, sizeof(deep));
    memset(vis, 0, sizeof(vis));
}

void bfs(LL be)
{
    vis[be] = 1;
    for (LL i = head[be]; i != -1; i = edge[i].nxt)
    {
        
        LL to;
        to = edge[i].to;
        if (vis[to])continue;
        deep[to] = deep[be] + 1;
        bfs(to);
        sum[be] += sum[to];
    }
    sum[be]++;
}

LL ans;
void dfs(LL S)
{
    vis[S] = 1;
    LL add2;
    add2 = 0;
    for (LL i = head[S]; i != -1; i=edge[i].nxt)
    {
        LL to;
        LL from;
        to = edge[i].to;
        from = edge[i].from;
        if (vis[to])continue;
        ans += (deep[to] * sum[to] * edge[i].val) % MOD;
        add2 += (deep[to] * (sum[from] - sum[to] - 1)* edge[i].val) % MOD;
        add2 %= MOD;
        ans %= MOD;
        dfs(to);
    }
    ans += add2 / 2;
}

int main()
{
    LL N;
    while (scan_d(N))
    {
        ans = 0;
        init();
        for (LL i = 0; i < N-1; i++) 
        {
            LL u, v, va;
            scan_d(u);
            scan_d(v);
            scan_d(va);
            addE(u, v, va);
        }

        deep[1] = 0;
        bfs(1);

        memset(vis, 0, sizeof(vis));
        dfs(1);
        for (LL i = 1; i <= N - 1; i++)
        {
            ans *= i;
            ans %= MOD;
        }
        ans *= 2;
        ans %= MOD;
        printf("%lld\n", ans);
    }
    return 0;
}