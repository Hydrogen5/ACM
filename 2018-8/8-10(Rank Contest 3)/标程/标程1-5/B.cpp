#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#define mem(x,y) memset(x,y,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scan2(x,y) scanf("%d%d",&x,&y)
#define eps 1e-5
#define INF 100000000
#define MAXN 1000005
using namespace std;
typedef long long ll;
int a[10];
int ans=0;
int w;
bool vis[10];
int getmin[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000};

void judge()
{

        int m=1;
    int x=0;
    int y=0;
    int z=0;
    double res;
    for(int i=1;i<=7;i++)
    {
        x=0;
         for(int k=1;k<=i;k++)
            x+=a[k]*getmin[i-k];
        for(int j=i+1;j<=8;j++)
            {
                y=0;
                 z=0;
                for(int k=i+1;k<=j;k++)
                    y+=a[k]*getmin[j-k];
                 for(int k=j+1;k<=9;k++)
                    z+=a[k]*getmin[9-k];

                    res=fabs(x+(double)y/z-w);
                if(res<eps)
                    ans++;
            }
    }
}
void dfs(int d)
{
    if(d>9)
    {
       judge();
        return ;
    }
    for(int i=1;i<=9;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            a[d]=i;
          dfs(d+1);
          vis[i]=0;

        }
    }
}

int main()
{

    mem(vis,0);
    ans=0;
    cin>>w;

 dfs(1);

cout<<ans<<endl;
//}
    return 0;
}

