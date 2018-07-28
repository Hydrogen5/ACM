//New Year Transportation
#include <iostream>
#include <cstdio>
using namespace std;
int cell[1111111];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<n;i++) scanf("%d",&cell[i]);
    int cur=1;
    while(cur<n&&cur<m) cur+=cell[cur];
    if(cur==m) cout<<"YES\n";
    else cout<<"NO\n";
}