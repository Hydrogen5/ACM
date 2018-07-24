//Sonya and Robots 
#include <iostream>
#include <cstring>
using namespace std;
int vis[1000000];
int cnt[1000000];
int numb[100000];
int main()
{
    int n;
    cin>>n;
    int k=0;
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n;i++)
    {
        cin>>numb[i];
        cnt[numb[i]]++;
        if(cnt[numb[i]]==1)
            k++;
    }
    long long ans = 0;
    for (int i = 0; i < n;i++)
    {
        cnt[numb[i]]--;
        if(!cnt[numb[i]]) k--;
        if(!vis[numb[i]]) 
        {
            ans += k;
            vis[numb[i]] = 1;
        }
    }
    cout << ans << endl;
}