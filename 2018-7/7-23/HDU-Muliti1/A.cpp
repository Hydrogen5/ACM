//Maximum Multiple
//r=n/x,s=n/y,t=n/z
//->1/r+1/s+1/t==1
//x=n/2,y=n/4,z=n/4
//或x=y=z=n/3
//或x=n/2,y=n/3,z=n/6(显然可以转化为3*1/3，舍去)
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long n;
        scanf("%lld",&n);
        if(n%3==0)
            cout << n * n * n / 27 << endl;
        else
        {
            if(n%2)
                cout << -1 << endl;
            else
            {
                if(n%4==0)
                    cout << n * n * n / 32<<endl;
                else
                    cout << -1 << endl;
            }
        }
    }
    return 0;
}
