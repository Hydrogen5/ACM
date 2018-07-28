//Cyclic Components
#include <iostream>
#include <vector>
using namespace std;
int vis[1000010]={0};
vector<int> v[1000010];
int flag;
void dfs(int i)
{
    vis[i]=1;
    if(v[i].size()!=2)
        flag = 0;
    for (int j = 0; j < v[i].size();j++)
        if(!vis[v[i][j]])
            dfs(v[i][j]);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int j,k;
        cin>>j>>k;
        v[j].push_back(k);
        v[k].push_back(j);
    }
    long long ans = 0;
    for (int i = 1;i<=n;i++)
    {
        if(!vis[i])
        {
            flag = 1;
            dfs(i);
            if(flag)
                ans++;
        }
    }
    cout << ans << endl;
}