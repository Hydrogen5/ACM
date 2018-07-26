//Less or Equal 
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];
int main()
{
    int n,k;
    cin>>n>>k;
    for (int i = 1; i <= n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(k==0)
    {
        if(a[1]==1) cout<<-1<<endl;
        else
            cout << a[1]-1 << endl;
    }
    else
    {
        if(a[k]==a[k+1]) cout<<-1<<endl;
        else
            cout << a[k]<<endl;
    }
}