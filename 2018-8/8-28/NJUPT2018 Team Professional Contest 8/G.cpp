//Miraculous Drug
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
#define l(x) node[x].l
#define r(x) node[x].r
#define mi(x) node[x].mi
using namespace std;
int a[10010];
int cnt;
int m[10010];
int ans[10010];
struct Node
{
    int l;
    int r;
    int mi;
} node[40010];
void build(int p, int l, int r)
{
    l(p) = l;
    r(p) = r;
    if (l == r)
        mi(p) = a[cnt++];
        int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    mi(p) = min(mi(p * 2), mi(p * 2 + 1));
}
int query(int p,int l,int r)
{
    if(l<=l(p)&&r>=r(p)) return mi(p);
    int mid=(l(p)+r(p))/2;
    int val=1000000;
    if(l<=mid)
        val = min(val,query(p * 2, l, r));
    if(r>mid)
        val = min(val,query(p * 2 + 1, l, r));
    return val;
}
int main()
{
    int n;
    int h;
    int l, r;
    while (scanf("%d %d %d %d", &n, &h, &l, &r) == 4)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        cnt = 1;
    }
    return 0;
}