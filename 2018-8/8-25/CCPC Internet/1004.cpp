#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define random(a, b) ((a) + rand() % ((b) - (a) + 1))
using namespace std;
int T, n, a, b, c;
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
    scan_d(T);
    while(T--)
    {
        scan_d(n);
        scan_d(a);
        if (n > 2 || n == 0)
        {
            printf("-1 -1\n");
            continue;
        }
        else
        {
            if (n == 1)
            {
                printf("1 %d\n", a+1);
            }
            else
            {
                if (a % 2 == 1)
                {
                    int mid = a * a;
                    b = mid / 2;
                    c = b + 1;
                }
                else
                {
                    int mid = a * a;
                    mid /= 2;
                    c = mid / 2 + 1;
                    b = c - 2;
                }
                printf("%d %d\n", b, c);
            }
        }
    }
    return 0;
}