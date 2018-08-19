//Lawn mower
#include <iostream>
#include <cstdio>  
#include <algorithm>
using namespace std;
double a[1010], b[1010];
int main()
{
    int n,m;
    double w;
    while(scanf("%d %d %lf",&n,&m,&w)==3)
    {
        if(n==0&&m==0&&w==0) break;
        for (int i = 1;i<=n;i++)
            scanf("%lf", &a[i]);
        for(int i=1;i<=m;i++)
            scanf("%lf", &b[i]);
        sort(a + 1, a + n + 1);
        sort(b + 1, b + m + 1);
        int flag = 1;
        a[0]=-w/2;
        a[n + 1] = 75.0 + w / 2;
        for(int i=1;i<=n+1;i++)
            if(a[i]-a[i-1]>w)
                flag = 0;
        b[0]=-w/2;
        b[m + 1] = 100.0 + w / 2;
        for(int i=1;i<=m+1;i++)
            if(b[i]-b[i-1]>w)
                flag = 0;
        if(flag)
            printf("YES\n");
        else
            puts("NO");
    }
}