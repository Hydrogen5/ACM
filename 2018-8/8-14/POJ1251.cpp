//Jungle Roads
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Edge{
    int v1,v2;
    int weight;
} edge[500010];
int pre[100];
int cmp(Edge a,Edge b)
{
    return a.weight < b.weight;
}
int find(int x)
{
    if(x!=pre[x])
        pre[x] = find(pre[x]);
    return pre[x];
}
void merge(int x,int y)
{
    int px = find(x);
    int py = find(y);
    if(px!=py)
        pre[px] = py;
}
int main()
{
    int n;
    while (cin>>n&&n!=0)
    {
        int num=0;
        for(int i=0;i<=n;i++)
            pre[i] = i;
        char ch;
        int v1, k;
        for(int i=1;i<=n-1;i++)
        {
            cin>>ch>>k;
            v1 = ch - 'A';
            for (int j = 1;j<=k;j++)
            {
                cin>>ch;
                edge[num].v1=v1;
                edge[num].v2 = ch - 'A';
                cin >> edge[num].weight;
                num++;
            }
        }
        sort(edge, edge + num, cmp);
        int ans = 0;
        int cnt = 0;
        for(int i=0;i<num;i++)
        {
            if(cnt==n-1)
                break;
            int px = find(edge[i].v1);
            int py = find(edge[i].v2);
            if(px==py) continue;
            pre[px] = py;
            ans += edge[i].weight;
            cnt++;
        }
        cout << ans << endl;
    }
}
