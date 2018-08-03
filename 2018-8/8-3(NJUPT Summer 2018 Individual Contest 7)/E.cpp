//Mahmoud and Ehab and the message 
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
string str[1000010];
int pre[100010];
int cost[100010];
map<string, int> ms;
int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    for (int i = 1; i <= n;i++)
        pre[i] = i;
    for (int i = 1; i <= n; i++)
    {
        cin >> str[i];
        ms[str[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    while(k--)
    {
        int x;
        cin>>x;
        int a;
        cin >> a;
        for (int i = 1; i < x;i++)
        {
            int num;
            cin>>num;
            pre[num] = a;
            cost[a]=min(cost[a],cost[num]);
        }
    }
    long long ans=0;
    for (int i = 0; i < m;i++)
    {
        string tmp;
        cin>>tmp;
        int code = ms[tmp];
        ans += cost[pre[code]];
    }
    cout << ans << endl;
}