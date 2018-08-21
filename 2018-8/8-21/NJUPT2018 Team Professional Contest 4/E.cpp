//Please, go first
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
int pos[200];
int num[200];
char s[25010];
queue<int> q;
int main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        memset(pos,0,sizeof(pos));
        memset(num,0,sizeof(num));
        while(!q.empty())
            q.pop();
        cin>>n;
        cin>>(s+1);
        for(int i=n;i>=1;i--)
        {
            if(pos[s[i]]==0)
            {
                pos[s[i]] = i;
                q.push(s[i]);
            }
            num[s[i]]++;
        }
        int ans=0;
        int cnt = n;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            ans += num[x] * (pos[x] - cnt);
            cnt -= num[x];
        }
        cout << ans*5 << endl;
    }   
    return 0;
}