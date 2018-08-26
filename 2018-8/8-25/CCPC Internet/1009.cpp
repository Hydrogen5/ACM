//Tree and Permutation
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
int mat[100005][100005];
int n;
int cnt[100][100];
int l[100005];
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            if (mat[i][k] != inf)
                for (int j = 1; j <= n; j++)
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
}
int main()
{
    while (cin >> n)
    {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                mat[i][j] = inf;
        for (int i = 0; i <= n; i++)
            mat[i][i] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            mat[x][y] = mat[y][x] = z;
        }
        floyd();
        long long mid = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                mid += mat[i][j];
        for (int i = n - 1; i >= 1; i--)
        {
            mid *= i;
            mid %= 1000000007;
        }
        cout << mid << endl;
    }

    return 0;
}