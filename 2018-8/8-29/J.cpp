//Edge Case
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
#define ll long long
using namespace std;
int a[1000010];
int main()
{
    int x;
    while (scanf("%d", &x) == 1)
    {
        x *= 10000000;
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a+1, a + n+1);
        int flag = 0;
        int pos1, pos2;
        for (int i = 1; i <= n; i++)
        {
            int l = i + 1, r = n, mid = 0;
            int t = x - a[i];
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (t > a[mid])
                    l = mid + 1;
                else if (t < a[mid])
                    r = mid - 1;
                else
                {
                    flag = 1;
                    pos1 = a[i];
                    pos2 = a[mid];
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 0)
            printf("danger\n");
        else
            printf("yes %d %d\n", pos1, pos2);
    }
    return 0;
}