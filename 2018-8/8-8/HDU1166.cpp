//敌兵布阵
#include <iostream>
#include <cstdio>
#define l(x) node[x].l
#define r(x) node[x].r
#define sum(x) node[x].sum
using namespace std;
int n;
struct node{
    int l,r;
    int sum;
} node[200010];
int a[50010];
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
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    sum(p) = sum(p * 2) + sum(p * 2 + 1);
}
int query(int p,int l,int r)
{
    if(l<=l(p)&&r>=r(p)) return sum(p);
    int mid=(l(p)+r(p))/2;
    int val=0;
    if(l<=mid)
        val += query(p * 2, l, r);
    if(r>mid)
        val += query(p * 2 + 1, l, r);
    return val;
}
void change(int p,int x,int d)
{
    if(l(p)==r(p))
    {
        sum(p) += d;
        return;
    }
    int mid=(l(p)+r(p))/2;
    if(x<=mid)
        change(p * 2, x, d);
    else
        change(p * 2 + 1, x, d);
    sum(p) += d;
}
int main()
{
    int T;
    cin >> T;
    for(int afs=1;afs<=T;afs++)
    {
        printf("Case %d:\n", afs);
        cin>>n;
        for (int i = 1;i<=n;i++)
            cin >> a[i];
        build(1, 1, n);
        char s[10];
        while(cin>>s)
        {
            if(s[0]=='E')
                break;
            if(s[0]=='Q')
            {
                int l,r;
                cin>>l>>r;
                cout << query(1, l, r)<<endl;
            }
            if(s[0]=='A')
            {
                int x,d;
                cin>>x>>d;
                change(1, x, d);
            }
            if(s[0]=='S')
            {
                int x,d;
                cin>>x>>d;
                change(1, x, -d);
            }
        }
    }
}