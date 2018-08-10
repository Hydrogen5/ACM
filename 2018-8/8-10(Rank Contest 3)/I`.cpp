#include <iostream>
#include <queue>
using namespace std;
struct node{
    int bank, copy,cnt;
} a, b,c,d;
int vis[10000000];
queue<node> q;
int main()
{
    int n;
    cin>>n;
    a.bank=1;
    a.copy = 0;
    a.cnt = 0;
    q.push(a);
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        if(vis[a.bank]) continue;
        vis[a.bank] = 1;
        if(a.bank==n)
        {
            cout<<a.cnt<<endl;
            break;
        }
        if(a.copy!=0)
        {
            b.bank = a.copy+a.bank;
            b.copy=a.copy;
            b.cnt = a.cnt + 1;
            q.push(b);
        }
        if(a.copy!=a.bank)
        {
            c.copy=a.bank;
            c.bank = a.bank;
            c.cnt = a.cnt + 1;
            q.push(c);
        }
        if(a.bank!=1)
        {
            d.bank=a.bank-1;
            d.copy = a.copy;
            d.cnt = a.cnt + 1;
            q.push(d);
        }
    }
} 
