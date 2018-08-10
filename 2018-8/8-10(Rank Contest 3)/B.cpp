#include<iostream> 
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[]={1, 2, 3, 4, 5, 6, 7, 8, 9};
int num[3];
int n, ans;
void dfs(int cur, int cnt)
{
    if(cnt > 1)
    {
        num[cnt] = 0;
        for(int i=cur; i<9; i++)
            num[cnt] = num[cnt] * 10 + a[i];
        if(num[1]%num[2]==0 && num[0] + num[1]/num[2] == n) ans++;
        return ;
    }

    int dd = 6+cnt;
    for(int i=cur; i<=dd; i++)
    {
         num[cnt] = 0;
        for(int j=cur; j<=i; ++j)
             num[cnt] = num[cnt] * 10 + a[j];
         dfs(i+1, cnt+1);
     }
}

int main()
{
    while(scanf("%d", &n) != EOF)
    {
        sort(a, a+9);
        ans = 0;
        while(next_permutation(a, a+9))
        {
             dfs(0, 0);
        }
        printf("%d\n", ans);
    }
     return 0;
}
