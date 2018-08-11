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
#define eps 1e-8;
#define INF 100000000
#define MAXN 500
using namespace std;
typedef long long ll;
bool vis[5000005];
bool ok[5000005];
int a[4500000];
int cnt=0;
int n;
void dfs(int x)
{
    if(vis[x])
        return ;
    vis[x]=1;
    if(ok[x])
        dfs((1<<n)-x-1);
    for(int i=0;i<=n-1;i++)
    {
        if(x&(1<<i))
        {
            int t=x^(1<<i);
                dfs(t);

        }
    }
}
int main()
{
    int m;
    cin>>n>>m;

    for(int i=1;i<=m;i++)
    {

          scanf("%d",&a[i]);
        ok[a[i]]=1;
    }
    for(int i=1;i<=m;i++)
    {
        if(!vis[a[i]])
        {
            cnt++;
            dfs((1<<n)-a[i]-1);
        }
    }

      cout<<cnt<<endl;


    return 0;
}
