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
#define eps 1e-8
#define INF 100000000
#define MAXN 500
#define rep(x,y,z) for(int x=y;x<=z;x++)
using namespace std;
typedef unsigned long long ll;
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    if(a==0||b==0)
        return 0;
    return a/(ll)gcd(a,b)*b;
}
ll a[120];
int main()
{
     unsigned int t,x,y,z;
    int n,T;
   ll temp;

   scanf("%d%d%d%d",&n,&x,&y,&z);
    for(int i=0;i<n;i++)
    {

    x^=x<<16;
    x^=x>>5;
    x^=x<<1;
    t=x;
    x=y;
    y=z;
     z=t^x^y;
    //cout<<z<<endl;
     if(z>a[0])
        a[0]=z;
    else
     continue;
     for(int j=1;j<100;j++)
     {
         if(a[j-1]>a[j])
         {
             temp=a[j-1];
             a[j-1]=a[j];
             a[j]=temp;
         }
         else
            break;
     }

    }
  ll maxn=0;
     for(int i=0;i<100;i++)
        for(int j=0;j<i;j++)
     {

         if(lcm(a[i],a[j])>maxn)
            maxn=lcm(a[i],a[j]);
     }

    cout<<maxn<<endl;

    return 0;
}

