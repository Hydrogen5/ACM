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
int ab[256];
int opt[10010];
int v[10010];
int j[10010];
int cord[10010];
int cnt[10010];
int vis[260];
int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        memset(cnt, 0, sizeof(cnt));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            char s[5];
            scanf("%s", s);
            if (s[0] == 'a')
            {
                opt[i] = 1;
                scanf("%d", &v[i]);
            }
            else
            {
                if (s[1] == 'e')
                {
                    opt[i] = 2;
                    scanf("%d%d", &v[i], &j[i]);
                }
                if (s[1] == 'n')
                {
                    opt[i] = 3;
                    scanf("%d%d", &v[i], &j[i]);
                }
                if (s[1] == 'l')
                {
                    opt[i] = 4;
                    scanf("%d%d", &v[i], &j[i]);
                }
                if (s[1] == 'g')
                {
                    opt[i] = 5;
                    scanf("%d%d", &v[i], &j[i]);
                }
            }
        }
        memset(ab, 0, sizeof(ab));
        memset(cord, -1, sizeof(cord));
        int r = 0;
        int flag = 1;
        for (int i = 1; i <= n; i++)
        {
            cnt[i]++;
            if (cnt[i] > 256)
            {
                flag = 0;
                break;
            }
            if (opt[i] == 1)
            {
                r += v[i];
                r %= 256;
            }
            else
            {

                if (opt[i] == 2)
                {
                    if (r == v[i])
                    {
                        i = j[i] - 1;
                        continue;
                    }
                }
                if (opt[i] == 3)
                    if (r != v[i])
                    {
                        i = j[i] - 1;
                        continue;
                    }
                if (opt[i] == 4)
                    if (r < v[i])
                    {
                        i = j[i] - 1;
                        continue;
                    }
                if (opt[i] == 5)
                    if (r > v[i])
                    {
                        i = j[i] - 1;
                        continue;
                    }
            }
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}