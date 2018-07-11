//The Euler function
//欧拉函数（eeeeeasy)
#include <iostream>
using namespace std;
int phi[3000010]={0};
void phitable()
{
    phi[1]=1;
    for (int i = 2; i <= 3000000;i++)
    {
        if(!phi[i])
        {
            for (int j = i; j <= 3000000;j+=i)
            {
                if(!phi[j]) phi[j]=j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

int main()
{
    phitable();
    int a, b;
    while(cin>>a>>b)
    {
        long long ans=0;
        for (int i = a;i<=b;i++)
            ans += phi[i];
        cout << ans << endl;
    }
}