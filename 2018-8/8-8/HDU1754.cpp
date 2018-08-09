//I Hate It
#include <iostream>
#include <cstdio>
#include <algorithm>
#define l(x) node[x].l
#define r(x) node[x].r
#define dat(x) node[x].dat
using namespace std;
struct node{
    int l, r, dat;
} node[800010];
void build(int p,int l,int r)
{
    l(p)=l;
    r(p)=r;
    if(l==r)
    {
        scanf("%d", &dat(p));
        return;
    }
    int mid=(l+r)/2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    dat(p) = max(dat(p * 2), dat(p * 2 + 1));
}
int query(int p,int l,int r)
{
    if(l<=l(p)&&r>=r(p))
        return dat(p);
    int mid=(l(p)+r(p))/2;
    int ret=-1999;
    if(l<=mid)
        ret = max(ret, query(p * 2, l, r));
    if(r>mid)
        ret = max(ret, query(p * 2 + 1, l, r));
    return ret;
}
void change(int p,int x,int d)
{
    if(l(p)==r(p))
    {
        dat(p) = d;
        return;
    }
    int mid=(l(p)+r(p))/2;
    if(x<=mid)
        change(p * 2, x, d);
    else
        change(p * 2 + 1, x, d);
    dat(p) = max(dat(p * 2), dat(p * 2 + 1));
}
int main()
{
    int N,M;
    while(cin>>N>>M)
    {
        build(1,1,N);
        char a;
        int b,c;
        while(M--)
        {
            cin>>a>>b>>c;
            if(a=='Q')
                printf("%d\n",query(1, b, c));
            else
                change(1, b, c);
        }
    }
}