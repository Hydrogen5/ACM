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
    ll sec = 1;
    while(1)
    {
        if(sec>a[sec-(sec-1)/n*n])
            break;
        sec++;
    }
    cout << sec-(sec-1)/n*n << endl;
}