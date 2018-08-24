//ASCII Area
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
char img[110][110];
int main()
{
    freopen("ascii.in","r",stdin);
    freopen("ascii.out","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", img[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        bool x = 0;
        for (int j = 0; j < m; j++)
        {
            if (img[i][j] == '\\' || img[i][j] == '/')
            {
                ans++;
                x = !x;
            }
            else if (x)
                ans += 2;
        }
    }
    printf("%d\n", ans / 2);
    return 0;
}