#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;

#define ll long long
#define INF 0x3f3f3f3f
#define maxn 1000007
bool vis[maxn];
int dis[maxn],n;
int a[]={2,3,5,7,11};

void spfa()
{
    memset(vis,0,sizeof(vis));
    memset(dis,INF,sizeof(dis));
    queue<int>qu;
    qu.push(1);
    vis[1]=1;
    dis[1]=0;
    while(!qu.empty())
    {
        int t=qu.front();
        qu.pop();
        vis[t]=0;
        if(t-1>0&&dis[t-1]>dis[t]+1)
        {
            dis[t-1]=dis[t]+1;
            if(!vis[t-1])
            {
                qu.push(t-1);
                vis[t-1]=1;
            }
        }
        for(int i=0;i<5;i++)
        {
            if(t*a[i]<maxn&&dis[t*a[i]]>dis[t]+a[i])
            {
                dis[t*a[i]]=dis[t]+a[i];
                if(!vis[t*a[i]])
                {
                    qu.push(t*a[i]);
                    vis[t*a[i]]=1;
                }
            }
        }
    }
    printf("%d\n",dis[n]);
}
int main()
{
    scanf("%d",&n);
    spfa();
    return 0;
}
