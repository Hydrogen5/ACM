#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;
int a[10010];
int ans[10010];
int gt(int b,int e,int x)
{
    int val=e+1;
    for (int i = b;i<=e;i++)
        if(a[i]<=x)
            return i;
    return val;
}
int main() 
{
    freopen("g.in", "r", stdin);
    int n;
    int h;
    int l, r;
    while (scanf("%d %d %d %d", &n, &h, &l, &r) == 4)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int res=0;
        for(int i=1;i<=n;i++)
        {
            int pos = gt(i + 1, min(i + h - 1, n), a[i]);
            if(pos<=res) ans[i]=0;
            else
            {
                ans[i] = pos - res - 1;
                res = pos - 1;
            }
        }
        printf("%d",ans[l]);
        for(int i=l+1;i<=r;i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
    
    return 0;
}