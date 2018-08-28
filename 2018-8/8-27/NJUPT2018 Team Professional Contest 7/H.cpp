//Peer Review
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
char name[1010][15];
int cnt[1010];
vector<int> a[1010];
int Right[1010];
int main()
{
    int n, k;
    while (scanf("%d%d", &k, &n) == 2 && n)
    {
        memset(Right, 0, sizeof(Right));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= n; i++)
            a[i].clear();
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", name[i]);
            for (int j = 0; j < k; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                a[i].push_back(tmp);
            }
        }
        for (int i = 1; i <= n; i++)
            sort(a[i].begin(), a[i].end());
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < k; j++)
            {
                if (j != 0 && (a[i][j] == a[i][j - 1]))
                {
                    Right[a[i][j]] = 1;
                    continue;
                }
                if (!strcmp(name[i],name[a[i][j]]))
                    Right[a[i][j]] = 1;
                else
                    cnt[a[i][j]] += 1;
            }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (cnt[i] != k)
                Right[i] = 1;
        for (int i = 1; i <= n; i++)
            if (Right[i])
                ans++;
        if (ans == 0)
            printf("NO PROBLEMS FOUND\n");
        else
            printf("%d PROBLEMS FOUND\n", ans);
    }
    return 0;
}