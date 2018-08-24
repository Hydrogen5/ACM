//Eve
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
int alive[300010];
int pre[300010];
int ismale[300010];
int a[300010];
map<int, int> dna;
pair<int, int> p[300010];
int find(int x)
{
    if (x != pre[x])
        pre[x] = find(pre[x]);
    return pre[x];
}
void merge(int x, int y)
{
    int px = find(x);
    int py = find(y);
    if (px != py)
        pre[px] = py;
}
int main()
{
    freopen("eve.in", "r", stdin);
    freopen("eve.out", "w", stdout);
    int n;
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i <= 300000; i++)
            pre[i] = i;
        for (int i = 0; i < n; i++)
        {
            char s[2];
            scanf("%s", s);
            alive[i] = 1;
        }
        int m;
        scanf("%d", &m);
        int id = n;
        for (int i = 1+n; i <= m+n; i++)
        {
            int a, b;
            char s[2];
            cin >> a;
            if (a > 0)
            {
                id++;
                cin >> b;
                cin >> s;
                merge(id, b);
                alive[id] = 1;
            }
            else
            {
                a = -a;
                alive[a] = 0;
            }
        }
        dna.clear();
        int k;
        scanf("%d", &k);
        int cnt = 0;
        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &p[i].first, &p[i].second);
            a[cnt++] = p[i].second;
        }
        sort(a, a + cnt);
        cnt = unique(a, a + cnt) - a;
        for(int i=0;i<cnt;i++)        
            dna[a[i]] = i;
        for(int i=0;i<k;i++)
        {
            merge(p[i].first, dna[p[i].second] + 1 + n + m);
        }
        cnt = 0;
        for (int i = 1; i <= id; i++)
        {
            if (alive[i])
            {
                a[cnt++] = find(i);
            }
        }
        sort(a, a + cnt);
        cnt = unique(a, a + cnt) - a;
        if (cnt == 1)
            puts("YES");
        else
        {
            int num = 0;
            for (int i = 0; i < cnt; i++)
                if (a[i] > n + m)
                    num++;
            if (num > 1)
                puts("NO");
            else
                puts("POSSIBLY");
        }
    }
    return 0;
}