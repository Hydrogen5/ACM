//Regular Convex Polygon
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
const double pi = acos(-1);
int mo(double a, double b)
{
    return fmod(a, b) < 1e-7 || fabs(fmod(a, b) - b) < 1e-7;
}
inline bool scan_lf(double &num)
{
    char in;
    double Dec = 0.1;
    bool IsN = false, IsD = false;
    in = getchar();
    if (in == 'E')
        return false;
    if (in == EOF)
        return false;
    while (in != '-' && in != '.' && (in < '0' || in > '9'))
        in = getchar();
    if (in == '-')
    {
        IsN = true;
        num = 0;
    }
    else if (in == '.')
    {
        IsD = true;
        num = 0;
    }
    else
        num = in - '0';
    if (!IsD)
    {
        while (in = getchar(), in >= '0' && in <= '9')
        {
            num *= 10;
            num += in - '0';
        }
    }
    if (in != '.')
    {
        if (IsN)
            num = -num;
        return true;
    }
    else
    {
        while (in = getchar(), in >= '0' && in <= '9')
        {
            num += Dec * (in - '0');
            Dec *= 0.1;
        }
    }
    if (IsN)
        num = -num;
    return true;
}

int main()
{
    double x1, x2, x3, y1, y2, y3;
    while (scan_lf(x1))
    {
        scan_lf(y1);
        scan_lf(x2);
        scan_lf(y2);
        scan_lf(x3);
        scan_lf(y3);
        double a, b, c, ta, tb, tc;
        a = hypot(x1 - x2, y1 - y2);
        b = hypot(x3 - x2, y3 - y2);
        c = hypot(x1 - x3, y1 - y3);
        ta = acos((b * b + c * c - a * a) / (2 * b * c));
        tb = acos((a * a + c * c - b * b) / (2 * a * c));
        tc = acos((a * a + b * b - c * c) / (2 * a * b));
        ta = ta * 2;
        tb = tb * 2;
        tc = tc * 2;
        // double weix;
        // double weiy;
        // weix = (x1 + x2 + x3) / 3;
        // weiy = (y1 + y2 + y3) / 3;
        // double an1 = acos(1.0 - 0.5 * ((hypot((weix - x1) , (weiy - y1)) / ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))));
        // double an2 = acos(1.0 - 0.5 * (((weix - x1) * (weix - x1) + (weiy - y1) * (weiy - y1)) / ((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3))));
        // double an3 = acos(1.0 - 0.5 * (((weix - x1) * (weix - x1) + (weiy - y1) * (weiy - y1)) / ((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2))));
        for (int i = 3; i <= 1000; i++)
        {
            double tmp = 2 * pi / i;
            if (mo(ta, tmp) && mo(tb, tmp) && mo(tb, tmp))
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}