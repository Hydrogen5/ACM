//Hotel 
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
struct Node{
    int l,r;
    int set;
    int maxl,maxr,maxin;
}node[800010];
void build(int p,int l,int r)
{
    node[p].l=l;
    node[p].r=r;
    node[p].maxl = node[p].maxr = node[p].maxin = r - l + 1;
    node[p].set = 0;
    if(l==r)
        return;
    int mid=(l+r)/2;
    build(2*p,l,mid);
    build(2 * p + 1, mid + 1, r);
}
void change(int p,int l,int r,int d)
{
    if(node[p].l==l&&node[p].r==r)
    {
        node[p].set=d;
        if(d==0)
            node[p].maxl = node[p].maxr = node[p].maxin = r - l + 1;
        else
            node[p].maxl = node[p].maxr = node[p].maxin = 0;
        return;
    }
    if(node[p].set!=-1)
    {
        node[2*p].set=node[p].set;
        node[2 * p + 1].set = node[p].set;
        if(node[p].set==0)
        {
            node[2 * p].maxl = node[2 * p].maxr = node[2 * p].maxin = node[2 * p].r - node[2 * p].l + 1;
            node[2 * p + 1].maxl = node[2 * p + 1].maxr = node[2 * p + 1].maxin = node[2 * p + 1].r - node[2 * p + 1].l + 1;
        }
        else
        {
            node[2 * p].maxl = node[2 * p].maxr = node[2 * p].maxin = 0;
            node[2 * p + 1].maxl = node[2 * p + 1].maxr = node[2 * p + 1].maxin = 0;
        }
        node[p].set = -1;
    }
    int mid=(node[p].l+node[p].r)/2;
    if(r<=mid)
        change(p * 2, l, r, d);
    
    else if (l>mid)
    {
        change(p * 2 + 1, l, r, d);
    }
    else
    {
        change(p * 2, l, mid, d);
        change(p * 2 + 1, mid + 1, r, d);
    }

    if(node[p].set==-1)
    {
        if(node[2*p].set==0)
        { 
            node[p].maxl=node[p*2].maxl+node[2*p+1].maxl; 
        }
        else
        { 
            node[p].maxl=node[2*p].maxl; 
        } 
        if(node[2*p+1].set==0)
        { 
            node[p].maxr=node[p*2].maxr+node[2*p+1].maxr; 
        }
        else
        { 
            node[p].maxr=node[2*p+1].maxr; 
        } 
        int len=node[2*p].maxr+node[2*p+1].maxl; 
        node[p].maxin=max(len,max(node[2*p].maxin,node[2*p+1].maxin)); 
    }
    if(node[p*2].set==node[p*2+1].set) 
        node[p].set=node[p*2].set; 
    
}
int main() 
{
    int N,P;
    scanf("%d %d",&N,&P);
    build(1, 1, N);
    while(P--)
    {
        int i,a,b;
        scanf("%d",&i);
        if(i==3)
        {
            printf("%d\n", node[1].maxin);
        }
        else
        {
            scanf("%d %d", &a, &b);
            if(i==1)
                change(1, a, a + b - 1, 1);
            else
                change(1, a, a + b - 1, 0);
        }
    }
    return 0;
}