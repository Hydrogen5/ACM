#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int cnt[30] = {0};
int cha[1010];
int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n;i++)
    {
        char x;
        cin>>x;
        cnt[x - 'a'+1]++;
    }
    int xnt=0;
    while(xnt!=n)
    {
        for (int i = 1; i <= 26;i++)
        {
            if(cnt[i])
            {
                cha[xnt++] = i;
                cnt[i]--;
            }
        }
    }
    cha[n] = '0';
    int ans=0;
    for (int i = 0;i<n;i++)
    {
        if(cha[i]!=cha[i+1]-1)
            ans++;
    }
    cout << ans << endl;
}