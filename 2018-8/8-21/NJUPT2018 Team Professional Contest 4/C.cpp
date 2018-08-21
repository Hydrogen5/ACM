//Movie collection 
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
int c[200010];
int ans[100010];
int pos[200010];
void add(int x,int y)
{
    for (; x <= 200000;x+=x&-x)
        c[x] += y;
}
int ask(int x)
{
    int ans=0;
    for(;x;x-=x&-x) ans+=c[x];
    return ans;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            pos[i]=i+100000;
            add(pos[i], 1);
        }
        for(int i=1;i<=m;i++)
        {
            int x;
            cin>>x;
            add(pos[x],-1);
            ans[i]=ask(pos[x]);
            pos[x] = 100001 - i;
            add(pos[x], 1);
        }
        cout<<ans[1];
        for(int i=2;i<=m;i++)
            cout<<" "<<ans[i];
        cout << endl;
    }
}