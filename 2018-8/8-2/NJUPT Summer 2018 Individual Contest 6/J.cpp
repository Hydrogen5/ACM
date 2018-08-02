//Cut Ribbon
#include <iostream>
#include <cstring>
using namespace std;
int dp[5010]={0};
int main()
{
    int n,a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i=0;i<3;i++)
        for(int j=a[i];j<=n;j++)
            if(dp[j-a[i]]!=-1)
                dp[j]=max(dp[j],dp[j-a[i]]+1);
    cout << dp[n] << endl;

}