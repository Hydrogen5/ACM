//Robots
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
struct node
{
    double a, t;
} dat[10010];
int cmp(node A, node b)
{
    return A.a > b.a;
}
int main()
{
    // freopen("G.in", "r", stdin);
    int n;
    scanf("%d", &n);
    double def = 0;
    double v = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf %lf", &dat[i].a, &dat[i].t);
    }
    for (int i = n; i >= 1; i--)
    {
        def += dat[i].a * dat[i].t * v;
        v += dat[i].t;
    }
    sort(dat + 1, dat + n + 1, cmp);
    double opt = 0;
    v = 0;
    for (int i = n; i >= 1; i--)
    {
        opt += dat[i].a * dat[i].t * v;
        v += dat[i].t;
    }
    double ans = opt - def;
    printf("%.1lf\n", ans);
    return 0;
}