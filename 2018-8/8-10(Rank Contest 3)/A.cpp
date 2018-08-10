#include <iostream>
#include <cstdio>
#define l(x) node[x].l
#define r(x) node[x].r
#define sum(x) node[x].sum
using namespace std;
int n;
struct node{
    int l,r;
    long long sum;
} node[200010];
int a[50010];
void build(int p,int l,int r)
{
    l(p) = l;
    r(p) = r;
    if(l==r) 
    {
        cin >> sum(p);
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    sum(p) = sum(p * 2) + sum(p * 2 + 1);
}
long long query(int p,int l,int r)
{
    if(l<=l(p)&&r>=r(p)) return sum(p);
    int mid=(l(p)+r(p))/2;
    long long val=0;
    if(l<=mid)
        val += query(p * 2, l, r);
    if(r>mid)
        val += query(p * 2 + 1, l, r);
    return val;
}
int main()
{
    int k;
    cin>>n>>k;
    build(1,1,n);
    int ans = 0;
    for (int i = 1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(query(1,i,j)%k==0)
                ans++;
        }
    }
    cout << ans << endl;
}