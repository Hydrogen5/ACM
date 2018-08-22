//Frogger
//SPFA
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;
int x[300],y[300];
double mapp[300][300];
double dis[300];
int vis[300];
int n;
void spfa()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
        dis[i] = 0x3f3f3f3f;
    dis[1]=0;
    memset(vis,0,sizeof(vis));
    vis[1] = 1;
    q.push(1);
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        vis[k] = 0;
        for (int i = 1; i <= n;i++)
        {
            if(max(dis[k],mapp[k][i])<dis[i])
            {
                dis[i]=max(dis[k],mapp[k][i]);
                if(vis[i]==0)
                {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }
}
int main() 
{
    int kase = 1;
    while(cin>>n&&n)
    {
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i];
        for(int i=1;i<=n;i++)
            for (int j = 1;j<=n;j++)
                mapp[i][j] = mapp[j][i] = sqrt(double(x[i] - x[j]) * (x[i] - x[j]) + double(y[i] - y[j]) * (y[i] - y[j]));
        spfa();
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",kase++,dis[2]);
    }
    return 0;
}