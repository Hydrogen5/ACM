//Page Hopping
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
#define inf 0x3f3f3f3f
using namespace std;
int mat[110][110];
void floyd()
{
    for (int k = 1; k <= 100; k++)
        for (int i = 1; i <= 100; i++)
            for (int j = 1; j <= 100; j++)
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
}
int main()
{
    int a, b;
    int kase = 1;
    while (scanf("%d%d", &a, &b) == 2)
    {
        if (a == 0 && b == 0)
            break;
        for (int i = 1; i <= 100; i++)
            for (int j = 1; j <= 100; j++)
                mat[i][j] = inf;
        for (int i = 1; i <= 100; i++)
            mat[i][i] = 0;
        mat[a][b] = 1;
        int n = 0;
        if (a > n)
            n = a;
        if (b > n)
            n = b;
        while (scanf("%d%d", &a, &b))
        {
            if (a == 0 && b == 0)
                break;
            mat[a][b] = 1;
            if (a > n)
                n = a;
            if (b > n)
                n = b;
        }
        floyd();
        int cnt = 0, count = 0;
        for (int i = 1; i <= 100; i++)
            for (int j = 1; j <= 100; j++)
            {
                if (i == j)
                    continue;
                if (mat[i][j] < 100 && mat[i][j])
                {
                    cnt += mat[i][j];
                    count++;
                }
            }
        double ans = 1.0 * cnt / count;
        printf("Case %d: average length between pages = %.3lf clicks\n", kase++, ans);
    }
    return 0;
}