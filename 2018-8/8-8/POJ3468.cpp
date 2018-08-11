//A Simple Problem with Integers
#include <iostream>
#include <cstdio>
#define l(x) node[x].l
#define r(x) node[x].r
#define sum(x) node[x].sum
#define add(x) node[x].add
#define ll long long
using namespace std;
ll a[200000];
struct node{
    ll sum,add;
    int l,r;
} node[500000];
void build(int p,int l,int r)
{
    l(p) = l;
    r(p) = r;
    if(l==r)
    {
        sum(p)=a[l];
        return;
    }
    int mid = (l + r) / 2;
    add(p) = 0;
    build(p*2,l,mid);
    build(p * 2 + 1, mid + 1, r);
    sum(p) = sum(p * 2) + sum(p * 2 + 1);
}
void spread(int p)
{
    if(add(p))
    {
        sum(p * 2) += add(p) * (r(p*2) - l(p*2) + 1);
        sum(p * 2 + 1) += add(p) * (r(p * 2 + 1) - l(p * 2 + 1) + 1);
        add(p*2) += add(p);
        add(p*2+1) += add(p);
        add(p) = 0;
    }
}
ll query(int p,int l,int r)
{
    if(l<=l(p)&&r>=r(p))
        return sum(p);
    spread(p);
    int mid = (l(p) + r(p)) / 2;
    ll ret = 0;
    if(l<=mid)
        ret += query(p * 2, l, r);
    if(r>mid)
        ret += query(p * 2 + 1, l, r);
    return ret;
}
void change(int p,int l,int r,ll d)
{
    if (l<=l(p)&&r>=r(p))
    {
        sum(p)+=(ll)d*(r(p)-l(p)+1);
        add(p)+=d;
        return;
    }
    spread(p);
    int mid=(l(p)+r(p))/2;
    if(l<=mid) change(p*2,l,r,d);
    if(r>mid)
        change(p * 2 + 1, l, r, d);
    sum(p) = sum(p * 2) + sum(p * 2 + 1);
}

int main()
{
    int N,Q;
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=N;i++)
        scanf("%lld",&a[i]);
    build(1,1,N);
    while(Q--)
    {
        char a[2];
        scanf("%s",a);
        if(a[0]=='Q')
        {
            int l,r;
            scanf("%d%d",&l,&r);
            cout << query(1, l, r) << endl;
        }
        if(a[0]=='C')
        {
            int l,r,d;
            scanf("%d%d%d",&l,&r,&d);
            change(1, l, r, d);
        }
    }
}