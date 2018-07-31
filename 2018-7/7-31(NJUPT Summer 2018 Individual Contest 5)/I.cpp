//World Cup
#include <iostream>
#define ll long long
using namespace std;
ll a[100100];
int main()
{
    ll n;
    cin>>n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    ll ans = 1;
    ll MIN = 999999999;
    for (int i =1 ; i <= n;i++)
    {
        if (MIN > (a[i] - i + n) / n)
        {
            MIN = (a[i]-i+n)/n;
            ans = i;
        }
    }
    
    cout << ans << endl;
}