#include <cstdio>
int ans[110];
int num[110];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d", num + i);
        ans[n] = 1;
        for (int i = n - 1; i > 0;i--)
        {
            ans[i] = 1;
            for (int j = i + 1;j<=n;j++)
            {
                if(num[j]>=num[i])
                {
                    ans[i] += ans[j];
                }
            }
        }
        printf("%d", ans[1]);
        for(int i=2;i<=n;i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
}