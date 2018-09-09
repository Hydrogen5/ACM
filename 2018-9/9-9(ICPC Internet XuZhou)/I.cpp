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
char str[1000010];
int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n;
        char z;
        cin >> n >> z;
        cin >> str;
        int ans = 0;
        int i;
        for (i = 0; i < n; i++)
        {
            int tmp = abs((int)(z - str[i]));
            if (tmp > 0)
            {
                if (tmp < 10)
                    ans += 1;
                else
                    ans += 2;
                break;
            }
        }
        if (i == n)
            printf("1\n");
        else
        {
            ans += (n - i - 1) * 2;
            printf("%d\n", ans);
        }
    }
    return 0;
}