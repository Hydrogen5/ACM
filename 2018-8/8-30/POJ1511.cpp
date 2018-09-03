//Invitation card
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
int arr1[2000010], edge1[2000010], Next1[2000010], head1[2000010];
int arr2[2000010], edge2[2000010], Next2[2000010], head2[2000010];
int tot1;
int tot2;
int dis[1000010], vis[1000010];
void addedge1(int x, int y, int z)
{
    arr1[++tot1] = y;
    edge1[tot1] = z;
    Next1[tot1] = head1[x];
    head1[x] = tot1;
}
void SPFA1()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    dis[1] = 0;
    q.push(1);
    vis[1] = 1;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = head1[x]; i; i = Next1[i])
        {
            int y = arr1[i];
            int z = edge1[i];
            if (dis[y] > dis[x] + z)
            {
                dis[y] = dis[x] + z;
                if (!vis[y])
                {
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
}
void addedge2(int x, int y, int z)
{
    arr2[++tot2] = y;
    edge2[tot2] = z;
    Next2[tot2] = head2[x];
    head2[x] = tot2;
}
void SPFA2()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    dis[1] = 0;
    q.push(1);
    vis[1] = 1;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = head2[x]; i; i = Next2[i])
        {
            int y = arr2[i];
            int z = edge2[i];
            if (dis[y] > dis[x] + z)
            {
                dis[y] = dis[x] + z;
                if (!vis[y])
                {
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        tot1 = 0;
        tot2 = 0;
        memset(head1, 0, sizeof(head1));
        memset(head2, 0, sizeof(head2));
        int k, e;
        scanf("%d %d", &k, &e);
        for (int i = 0; i < e; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            addedge1(x, y, z);
            addedge2(y, x, z);
        }
        SPFA1();
        long long ans = 0;
        for (int i = 2; i <= k; i++)
        {
            ans += dis[i];
        }
        SPFA2();
        for (int i = 2; i <= k; i++)
        {
            ans += dis[i];
        }
        cout << ans << endl;
    }
    return 0;
}