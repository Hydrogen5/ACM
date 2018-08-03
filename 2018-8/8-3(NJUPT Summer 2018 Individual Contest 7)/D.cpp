//Socks 
//并查集
#include <iostream>
#include <map>
using namespace std;
int pre[200010];
int col[200010];
map<int, map<int,int> > iii;
map<int, int>::iterator it;
int find(int x)
{
    if(x!=pre[x])
        pre[x]=find(pre[x]);
    return pre[x];
}
void mix(int x,int y)
{
    int px=find(x);
    int py=find(y);
    if(px!=py)
        pre[px] = py;
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>col[i];
        pre[i] = i;
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        mix(l, r);
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int fa=find(i);
        iii[fa][col[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        int cnt=0,MAXN=0;
        for(it=iii[i].begin();it!=iii[i].end();it++)
        {
            if(it->second>MAXN) MAXN=it->second;
            cnt+=it->second;
        }
        sum+=cnt-MAXN;
    }
    cout << sum << endl;
}