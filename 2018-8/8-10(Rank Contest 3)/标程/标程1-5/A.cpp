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
#define MAXN 100005
using namespace std;
typedef long long ll;

int a[MAXN];
ll sum[MAXN];
ll cnt[MAXN];

int main()
{
    int n,k;
   ll ans=0;

  cin>>n>>k;
  mem(sum,0);
  mem(cnt,0);
    for(int i=1;i<=n;i++)
   // fscanf(fp1,"%d",&a[i]);
   scanf("%d",&a[i]);
    cnt[0]=1;
    for(int i=1;i<=n;i++)
    {
        sum[i]+=sum[i-1]+a[i];
        int x;
        x=sum[i]%k;
            cnt[x]++;
            ans+=cnt[x]-1;
    }

    cout<<ans<<endl;


    return 0;
}

