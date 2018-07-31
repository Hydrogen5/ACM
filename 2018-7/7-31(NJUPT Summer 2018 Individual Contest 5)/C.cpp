//Liebig's Barrels
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
long long a[100010];
int main()
{
    ll n,k,l;
    cin>>n>>k>>l;
    for (ll i = 1; i <= n * k;i++)
        cin >> a[i];
    sort(a+1,a+n*k+1);
    if (a[n] - a[1] > l)
        cout << "0\n";
    else
    {
        ll ans=0;
        ll pos=-1;
        for(ll i=n*k;i>=1;i--)
            if(a[i]-a[1]<=l)
            {
                pos=i;
                break;
            }
        ll num=0;
        ll j=pos;
        for(ll i=n*k;i-(k-1)>pos;i=i-(k-1))
        {
            ans+=a[j--];
            num++;
        }
        for(ll i=1;i<pos-num+1;i=i+k)
            ans+=a[i];
        cout << ans <<endl;
    }
}