#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <cstring>  
using namespace std;
#define LL long long
#define inf 0x3f3f3f3f
LL mod=1e9+7;
int dp[5005];
char s[5005];
bool ok(int a,int b)
{
    int m=b-((b-a)>>1);
    for(int i=a,j=b;i<=m;++i,--j)
        if(s[i]!=s[j]) return 0;
    return 1;
}
int main()
{
    int N,i,j;
    scanf("%s",s+1);
    N=strlen(s+1);
    for(i=1;i<=N;++i)
    {
        dp[i]=dp[i-1]+1;
        for(j=0;j<i;++j)
        {
            if(ok(j+1,i)&&dp[i]>dp[j]+1) dp[i]=dp[j]+1;
        }
    }
    printf("%d\n",dp[N]);
    return 0;
}