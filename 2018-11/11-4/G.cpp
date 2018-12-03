//Bishwock
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
using namespace std;
char a[2][110];
int main()
{
    scanf("%s", a[0]);
    scanf("%s", a[1]);
    int len = strlen(a[0]);
    int i = 0;
    int cnt = 0;
    while (i < len)
    {
        int m = 0, n = 0;
        if (a[0][i] == '0')
            m++;
        if (a[0][i + 1] == '0')
            m++;
        if (a[1][i] == '0')
            m++;
        if (a[1][i + 1] == '0')
            m++;
        if (a[0][i+2] == '0')
            n++;
        if (a[1][i + 2] == '0')
            n++;
        if (m == 4 && n == 2)
        {
            cnt += 2;
            i += 3;
        }
        else
        {
            if (m >= 3)
            {
                cnt++;
                i += 2;
            }
            else
                i++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}