//Recursive Queries 
#include <iostream>
using namespace std;
int ans[1000005][10] = {0};
int lead[1000010];
int main()
{
    for(int i=0;i<10;i++)
        lead[i] = i;
    for(int i=10;i<=1000005;i++)
    {
        int n=i;
        int mult = 1;
        while(n)
        {
            int t=n%10;
            if(t) mult*=t;
            n /= 10;
        }
        lead[i] = lead[mult];
    }
    for(int i=1;i<=1000000;i++)
    {
        for(int j=1;j<=9;j++)
            ans[i][j] = ans[i - 1][j];
        ans[i][lead[i]]++;
    }
    int Q;
    cin>>Q;
    while(Q--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        cout << ans[r][k] - ans[l - 1][k] << endl;
    }
}