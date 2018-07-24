//Fafa and his Company
#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int ans = 0;
        for (int i = 2; i <= n;i++)
        {
            if(n%i==0)
                ans++;
        }
        cout << ans << endl;
        ;
    }
}