//Just a Hook
#include <iostream>
#include <cstdio>
#define l(x) node[x].l
#define r(x) node[x].r
#define set(x) node[x].set
using namespace std;
struct Node
{
    int l,r,set;
}node[50000];

void build(int p,int l,int r)
{
    l(p) = l;
    r(p) = r;
    set(p) = 1;
    if(l==r)
        return;
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
}

void change(int p,int l,int r,int d)
{
    if(l(p)==l&&r(p)==r)
    {
        set(p)=d;
        return;
    }
    if(set(p)!=-1)
    {
        set(2 * p) = set(p);
        set(2 * p + 1) = set(p);
        set(p) = -1;
    }
    int mid = (l(p) + r(p)) / 2;
    if(r<=mid)
        change(p * 2, l, r, d);

    else if (l>mid)
        change(p * 2 + 1, l, r, d);
    
    else
    {
        change(p * 2, l, mid, d);
        change(p * 2 + 1, mid + 1, r, d);
    }
    
}

int find(int p)
{
    if(set(p)!=-1)
        return set(p) * (r(p) - l(p) + 1);
    else
        return find(p * 2)+find(p * 2 + 1);
}

int main()
{
    int T;
    cin>>T;
    for (int i = 1;i<=T;i++)
    {
        int n;
        cin>>n;
        build(1, 1, n);
        int Q;
        cin >> Q;
        while(Q--)
        {
            int l,r,d;
            scanf("%d%d%d", &l, &r, &d);
            change(1, l, r, d);
        }
        printf("Case %d: ",i);
        printf("The total value of the hook is %d.\n",find(1));
    }
}