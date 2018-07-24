//Sonya and Hotels 
#include <iostream>
using namespace std;
long long tmp[100010];
int main()
{
    int n, m;
    cin>>n>>m;
    for (int i = 1;i<=n;i++) cin>>tmp[i];
    int ans=2;
    for (int i = 2; i <= n;i++)
    {
        if(tmp[i]-tmp[i-1]>2*m)
            ans += 2;
        if(tmp[i]-tmp[i-1]==2*m)
            ans += 1;
    }
    cout << ans << endl;
}