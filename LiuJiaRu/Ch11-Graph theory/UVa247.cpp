// Calling Circles
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
vector<string> name;
map<string, int> mapp;
int n, m;
int cas = 1;
int ass[30][30];
int vis[30];
void dfs(int i)
{
    for (int j = 0; j < n; j++)
    {
        if (ass[i][j] && ass[j][i])
        {
            if (!vis[j])
            {
                printf(", %s", name[j].c_str());
                vis[j] = 1;
                dfs(j);
            }
        }
    }
}
int main()
{
    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n + m == 0)
            break;
        mapp.clear();
        name.clear();
        memset(ass, 0, sizeof(ass));
        memset(vis, 0, sizeof(0));
        int id = 0;
        for (int i = 0; i < m; i++)
        {
            string a, b;
            cin >> a >> b;
            if (mapp.count(a) == 0)
            {
                name.push_back(a);
                mapp[a] = id++;
            }
            if (mapp.count(b) == 0)
            {
                name.push_back(b);
                mapp[b] = id++;
            }
            ass[mapp[a]][mapp[b]] = 1;
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    ass[i][j] = ass[i][j] || (ass[i][k] && ass[k][j]);
        if (cas > 1)
            puts("");
        printf("Calling circles for data set %d:\n", cas++);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                printf("%s", name[i].c_str());
                vis[i] = 1;
                dfs(i);
                puts("");
            }
        }
    }
    return 0;
}