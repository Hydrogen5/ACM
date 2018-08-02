//Boredom
#include <iostream>
#include <algorithm>
using namespace std;
long long num[1000010]={0};
long long dp[1000010]={0};
int main()
{
    long long n;
    cin>>n;
    for (long long i = 0; i < n;i++)
    {
        long long x;
        cin>>x;
        num[x]++;
    }
    dp[1] = 1 * num[1];
    long long MAXN = dp[1];
    for(long long i=2;i<=100000;i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + i * num[i]);
        MAXN = max(MAXN, dp[i]);
    }
    cout << MAXN << endl;
}