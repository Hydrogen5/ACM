//Concerts
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#define MOD 1000000007
#define ll long long
using namespace std;
int n, k;
int dis[30];
int tar[101000];
int arr[100100];
ll dp[10][100100];
int main()
{
    scanf("%d %d", &k, &n);
    for (int i = 1; i <= 26; i++)
    {
        scanf("%d", &dis[i]);
        dis[i]++;
    }
    for (int i = 1; i <= k; i++)
    {
        char c;
        cin >> c;
        tar[i] = c - 'A' + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        arr[i] = c - 'A' + 1;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == tar[1])
            cnt++;
        dp[1][i] = cnt;
    }
    for (int i = 2; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i%2][j] = dp[i%2][j - 1];
            if (tar[i] == arr[j] && j > dis[tar[i - 1]])
                dp[i%2][j] = (dp[i%2][j] + dp[(i - 1)%2][j - dis[tar[i - 1]]]) % MOD;
        }
    }
    printf("%lld\n", dp[k%2][n]);
    return 0;
}