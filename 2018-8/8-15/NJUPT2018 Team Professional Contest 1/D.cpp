#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 0x7f7f7f7f
using namespace std;
int s[200010];
int a[200010];
int b[200010];
int c[200010];
int main()
{
    int Z;
    cin>>Z;
    while(Z--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            scanf("%d", &s[i]);
        b[1]=1;
        c[1]=inf;
        c[0] = inf;
        for(int i=2;i<=n;i++)
        {
            if(s[i]>s[i-1])
                b[i] = b[i - 1] + 1;
            else
                b[i] = 1;
            c[i] = inf;
           
        }
        a[n] = 1;
        for (int i = n - 1; i >= 0;i--)
        {
            if(s[i]<s[i+1])
                a[i] = a[i + 1] + 1;
            else
                a[i] = 1;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int len = lower_bound(c + 1, c + i + 1, s[i]) - c - 1 + a[i];
            ans = max(ans, len);
            c[b[i]] = min(c[b[i]], s[i]);
        }
        cout << ans << endl;
    }

}