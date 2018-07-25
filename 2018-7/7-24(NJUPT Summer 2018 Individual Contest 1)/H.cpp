//Sonya and Matrix 
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[1000010];
int d[1000010];
int main()
{
    int t;
    cin>>t;
    int b = 0;
    for (int i = 0;i<t;i++)
    {
        int x;
        cin>>x;
        a[x]++;
        b=max(b,x);
    }
    int x=1,m,y;
    for (int i = 1; i < b;i++)
    {
        if(a[i]!=4*i) 
        {
            x = i;
            break;
        }
    }
    int flag2=1;
    int n ;
    for (n = 1; n <=t;n++)
    {
        if(t%n==0)
        {
            m = t / n;
            y = n + m - b - x;
            memset(d, 0, sizeof(d));
            for (int i = 1; i <= n;i++)
            {
                for (int j = 1; j <= m;j++)
                {
                    int temp = abs(i - x) + abs(j - y);
                    d[temp]++;
                }
            }
            int flag = 1;
            for (int i = 0; i <= b;i++)
            {
                if (a[i]!=d[i])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                cout << n << " " << m << endl;
                cout << x << " " << y << endl;
                flag2=0;
                break;
            }
        }
    }
    if(flag2)
        cout << -1 << endl;
}
