//Learning Languages
#include <iostream>
using namespace std;
int pre[110];
int vis[110] = {0};
int find(int x)
{
    if(x!=pre[x])  
        pre[x]=find(pre[x]);
    return pre[x];
}
void merge(int x,int y)
{
    int px=find(x);
    int py=find(y);
    if(px!=py)
        pre[py] = px;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i <= m;i++)
        pre[i]=i;
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int cnt;
        cin>>cnt;
        if(cnt==0) ans++;
        else
        {
            int a;
            cin>>a;
            vis[a]++;
            for (int j=1;j<cnt;j++)
            {
                int x;
                cin>>x;
                vis[x]++;
                merge(a, x);
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= m;i++)
    {
        if(pre[i]==i)
        {
            ans++;
        }
        if(vis[i]==0)
            cnt++;
    }
        if(cnt==m) 
            cout<<n;
        else
            cout << ans - cnt - 1;
}