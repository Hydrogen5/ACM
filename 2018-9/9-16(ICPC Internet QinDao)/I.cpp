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
int BitLength(int n) 
{ 
    return n ? BitLength(n / 2) + 1 : 0 ; 
}
int ans[40];
int main() 
{
    int kase;
    scanf("%d", &kase);
    while(kase--)
    {
        int n;
        scanf("%d",&n);
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d", &a);
            int len=BitLength(a);
            ans[len]++;
        }
        int Max=0;
        for(int i=0;i<40;i++)
            Max=max(Max,ans[i]);
        printf("%d\n",Max);
    }
    return 0;
}