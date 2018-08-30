#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, num[1000047];
int main()
{
    int x;

    while (scanf("%d", &x) != EOF)
    {
        memset(num, 0, sizeof(num));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
        }
        sort(num + 1, num + n + 1);
        int ll = x * 10000000, a, b;
        int flag = 0;
        int j = n;
        int i = 1;
        while (i < j)
        {
            if (num[i] + num[j] == ll)
            {
                flag = 1;
                a = num[i];
                b = num[j];
                break;
            }
            else if (num[i] + num[j] < ll)
                i++;
            else if (num[i] + num[j] > ll)
                j--;
        }
        if (flag == 0)
            printf("danger\n");
        else
            printf("yes %d %d\n", a, b);
    }
    return 0;
}
