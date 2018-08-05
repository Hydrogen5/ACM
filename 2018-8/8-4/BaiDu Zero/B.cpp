//子串查询
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char s[100010];
int a[100010][30];
int main()
{
    int T;
    cin>>T;
    for (int m = 1; m <= T;m++)
    {
        memset(a, 0, sizeof(a));
        int n, q;
        scanf("%d %d",&n,&q);
        scanf("%s", (s + 1));
        for (int i = 1; i <= n;i++)
        {
            for (int j = 0; j < 26;j++)
                a[i][j] = a[i - 1][j];
            a[i][s[i] - 'A']++;
        }
        cout << "Case #" << m << ":\n";
        while (q--)
        {
            int l,r;
            scanf("%d %d",&l,&r);
            if(l==r)
                printf("1\n");
            else
            {
                int i;
                for (i = 0; i < 26;i++)
                    if (a[r][i] - a[l-1][i])
                        break;
                printf("%d\n", a[r][i] - a[l-1][i]);
            }
        }
    }
}