//Distributing Ballot Boxes
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int a[500010];
inline bool scan_d(int &num)
{
    char in;
    bool IsN = false;
    in = getchar();
    if (in == EOF)
        return false;
    while (in != '-' && (in < '0' || in > '9'))
        in = getchar();
    if (in == '-')
    {
        IsN = true;
        num = 0;
    }
    else
        num = in - '0';
    while (in = getchar(), in >= '0' && in <= '9')
    {
        num *= 10, num += in - '0';
    }
    if (IsN)
        num = -num;
    return true;
}
int main()
{
    int n, b;
    while (scanf("%d%d", &n, &b))
    {
        int ans = 0;
        if (n == -1 && b == -1)
            break;
        int Max = 0;
        for (int i = 1; i <= n; i++)
        {
            scan_d(a[i]);
            Max = max(a[i], Max);
        }
        int l = 1;
        int r = Max;
        while (r >= l)
        {
            int mid = (l + r) / 2;
            int sumb = 0;
            for (int i = 1; i <= n; i++)
                sumb += ceil(a[i] * 1.0 / mid);
            if (sumb > b)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
                ans = mid;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}