//A Simple Problem with Integers
#include <iostream>
#include <cstdio>
#define l(x) node[x].l
#define r(x) node[x].r
#define sum(x) node[x].sum
#define ll long long
using namespace std;
struct node{
    ll sum;
    int l,r;
} node[500000];
void build(int p,int l,int r)
{
    if(l==r)
    {
        cin >> sum(p);
        return;
    }
    int mid = (l + r) / 2;
    build(p*2,l,mid);
    build(p * 2 + 1, mid + 1, r);
    sum(p) = sum(p * 2) + sum(p * 2 + 1);
}
ll query(int p,int l,int r)
{
    if(l<=l(p)&&r>=r(p))
        return sum(p);
    int mid = (l(p) + r(p)) / 2;
    ll ret = 0;
    if(l<=mid)
        ret += query(p * 2, l, r);
    if(r>mid)
        ret += query(p * 2 + 1, l, r);
    return ret;
}
void change(int p,int )
int main()
{

}