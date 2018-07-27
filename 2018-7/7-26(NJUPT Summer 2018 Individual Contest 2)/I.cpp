#include <iostream>
using namespace std;
int a[1000000];
int main()
{
    int n, k, sum;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        sum+=i;
        if(sum>=k)
        {
            sum=i-(sum-k);
            cout<<a[sum]<<endl;
            break;
        }
    }
}