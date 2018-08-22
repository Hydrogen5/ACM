//Frogger
//dijkstra
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;
int x[300],y[300];
double mat[300][300];
double dist[300];
int vis[300];
int n;
priority_queue<pair<int, int>> pq;
void dijkstra()
{
    for(int i=0;i<=n;i++)
    {
        dist[i]=0x3f3f3f3f;
        vis[i] = 0;
    }
    pq.push(make_pair(0,1));
    dist[1]=0;
    while(!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        if(vis[x])
            continue;
        vis[x] = 1;
        for(int y=1;y<=n;y++)
        {
            if(dist[y]>max(dist[x],mat[x][y]))
            {
                dist[y]=max(dist[x],mat[x][y]);
                pq.push(make_pair(-dist[y], y));
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
            cin >> x[i] >> y[i];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                mat[i][j] = mat[j][i] = sqrt(double(x[i] - x[j]) * (x[i] - x[j]) + double(y[i] - y[j]) * (y[i] - y[j]));
        dijkstra();
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",kase++,dist[2]);
    }
    return 0;
}