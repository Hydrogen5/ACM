//Colossal Fibonacci Numbers!
//快速幂，循环节
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
unsigned long long f[1000010];
unsigned long long a, b, n;
unsigned long long qm(unsigned long long a,unsigned long long b,unsigned long long n)
{
    if(n==0)
        return 1;
    unsigned long long  ans = 1;
    while(b>0)
    {
        if(b&1)
            ans = (ans * a) % n;
        a=(a%n)*(a%n)%n;
        b >>= 1;
    }
    return ans;
}
int main()
{
  int k;
    cin>>k;
    while(k--)
    {
        cin>>a>>b>>n;
        f[0] = 0;
        f[1] = 1;
        int brk=1;
        if(n==1)
            cout << "0\n";
        else
        {
            for (int i = 2; i <= n * n;i++)
            {
                f[i] = (f[i - 1] + f[i - 2]) % n;
                if(f[i-1]==0&&f[i]==1)
                {
                    brk=i-1;
                    break;
                }
            }
            cout << f[qm(a,b,brk)] << endl;
        }
    }
}