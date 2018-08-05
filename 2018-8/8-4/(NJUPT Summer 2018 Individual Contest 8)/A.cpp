//The World is a Theatre 
#include <iostream>
#define ll long long
using namespace std;
ll C(int n,int m)
{
    ll ans=1;
    for(int i=1;i<=m;i++)ans=ans*(n-m+i)/i;
    return ans;
}
int main()
{
    int n,m,t;
    cin>>n>>m>>t;
    ll ans=0;
    for(int i=4;i<=n;i++)
        if(i<t&&t-i<=m)
            ans+=C(n,i)*C(m,t-i);
    cout << ans << endl;

}