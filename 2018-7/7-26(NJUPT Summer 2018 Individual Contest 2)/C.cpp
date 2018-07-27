//Watering System
#include <iostream>
#include <algorithm>
using namespace std;
long long p[1000000];
int main()
{
    long long n,A,B;
    cin>>n>>A>>B;
    long long sum = 0;
    for (int i = 1; i <= n;i++)
    {
        cin>>p[i];
        sum += p[i];
    }
    sort(p + 2,p+n+1);
    long long i=n,ans=0;
    while(p[1]*A<sum*B)
        {
            sum -= p[i--];
            ans++;
        }
    cout << ans << endl;
}