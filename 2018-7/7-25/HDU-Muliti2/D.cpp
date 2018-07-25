//Game
#include <iostream>
#include <cstring>
using namespace std;
int ans[510];
int vis[510];
int main()
{
    for (int i = 510; i >= 1;i--)
    {
        int cnt = 0;
        memset(vis, 0, sizeof(vis));
        for (int j = i; j > 0;j--)
        {
            for (int k = 1; k <= j;k++)
            {
                if(!vis[k]&&j%k==0)
                {
                    cnt++;
                    vis[k] = 1;
                }
            }
        }
        
        ans[i] = cnt%2;
    }
    int n;
    cin>>n;
    while(n--)
    {
        int k;
        cin >> k;
        if(k) cout<<"Yes\n";
        else
            cout << "No\n";
    }
}