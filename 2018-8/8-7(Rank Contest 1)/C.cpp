//S=(1/2)*(x1y2*1+x2y3*1+x3y1*1-x1y3*1-x2y1*1-x3y2*1) =1/2[x1(y2-y3)+x2(y3-y1)+x3(y1-y2)]
#include <cstdio>
#include <cmath>
#include <iostream>
#define ll long long
using namespace std;
int main()
{
    ll x1, x2, x3, y1, y2, y3;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%I64d %I64d %I64d %I64d %I64d %I64d", &x1, &y1, &x2, &y2, &x3, &y3);
        ll ans;
        ans = (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
        if(ans<0)
            ans = -ans;
        printf("%I64d", ans / 2);
        if(ans%2==1)
            printf(".50\n");
        else
            printf(".00\n");
    }
}