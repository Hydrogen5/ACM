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
#define MAXN 300005
#define rep(x,y,z) for(int x=y;x<=z;x++)
using namespace std;
typedef long long ll;
char s[MAXN];
ll getmin(ll a,ll b)
{
    if(a<b)
        return a;
    else
        return b;
}
    int main()
{

            ll n,x,y;

        cin>>n>>x>>y;
          // for(int i=0;i<n;i++)
            scanf("%s",&s);
            int num0=0,num1=0;
            for(int i=0; i<n;)
            {
                if(s[i]=='0')
                {
                    while(s[i+1]=='0'&&i+1<n)
                    {
                        i++;
                    }
                    num0++;
                }
                else
                {
                    while(s[i+1]=='1'&&i+1<n)
                    {
                        i++;
                    }
                    num1++;
                }
                i++;
            }
            if(num0==0)
            {
                cout<<0<<endl;
            }
            else
            {
                ll q=0,w=0;
                q=(long long)(y*num0);
                w=(long long)(y+(long long)(num0-1)*x);

             cout<<getmin(q,w)<<endl;

           }

        return 0;
    }
