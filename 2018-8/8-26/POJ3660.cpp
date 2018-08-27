//Cow Contest
//floyd
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
int N, M;
int dis[310][310];
void floyd()
{
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dis[i][j] = dis[i][j] || (dis[i][k] && dis[k][j]);
}
int main()
{
    scanf("%d%d", &N, &M);
    memset(dis, 0, sizeof(dis));
    for (int i = 1; i <= M; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        dis[x][y] = 1;
    }
    floyd();
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= N; j++)
            if (dis[i][j] || dis[j][i])
                cnt++;
        if (cnt == N - 1)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}