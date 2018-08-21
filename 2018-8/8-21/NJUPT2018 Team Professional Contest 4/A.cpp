//Binomial coefficients
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iterator>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <cstdlib>
#define ll long long
#define Max 100000000000001000
using namespace std;
vector<pair<ll,ll> > v;
ll calc(ll n,ll k)
{
    ll sum=1;
    for(int i=1;i<=k;i++)
    {
        ll tmp = sum;
        if(tmp/i>=Max/(n+1-i))
            return Max;
        sum = sum * (n + 1 - i) / i;
    }
    return sum;
}
int main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        v.clear();
        ll m;
        scanf("%lld",&m);
        ll tot = 0;
        for(int k=2;k<=30;k++)
        {
            ll l=2*k;
            ll r = m;
            while(l<=r)
            {
                ll mid = (l + r) / 2;
                ll sum=calc(mid,k);
                if(sum==m)
                {
                    v.push_back(make_pair(mid,k));
                    tot++;
                    if(mid!=2*k)
                        {
                            v.push_back(make_pair(mid, mid-k));
                            tot++;
                        }
                        break;
                }
                else 
                    if (sum<m)
                        l = mid + 1;
                    else
                        r = mid - 1;
            }
        }
        v.push_back(make_pair(m, 1));
        tot++;
        if(m!=2)
        {
                v.push_back(make_pair(m, m - 1));
                tot++;
        }        
        sort(v.begin(), v.end());
        printf("%lld\n",tot);
        for(ll i=0;i<tot;i++)
        {
            printf("(%lld,%lld)", v[i].first, v[i].second);
            if(i!=tot-1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}