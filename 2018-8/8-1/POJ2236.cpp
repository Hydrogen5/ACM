//Wireless Network
#include <iostream>
#include <cstring>
using namespace std;
struct node{
    int x, y;
} p[1010];
int fat[1010];
int vis[1010];
int dist(node a,node b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int find(int x)
{
    return fat[x] == x ? x : fat[x] = find(fat[x]);
}
int main()
{
    int n,d;
    while(cin>>n>>d)
    {
        memset(vis, 0, sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            fat[i] = i;
            cin >> p[i].x >> p[i].y;
        }
        char op[10];
        int x,y;
        while(cin>>op)
        {
            if(op[0]=='O')
            {
                cin>>x;
                vis[x]=1;
                for(int i=1;i<=n;i++)
                {
                    if (vis[i]&&dist(p[i],p[x])<=d*d)
                    {
                        int py=find(i);
                        int px = find(x);
                        fat[py] = px;
                    }
                }
            }
            else
            {
                cin>>x>>y;
                if(find(x)==find(y))
                    cout << "SUCCESS\n";
                else
                    cout << "FAIL\n";
            }
        }
    }
}