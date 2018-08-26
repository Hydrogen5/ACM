//Stack Machine Programmer
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
#define fabs(x) ((x) > 0 ? (x) : -(x)) 
#define zero(x)(fabs(x) < 1e-10)
struct mat
{
    int n, m;
    double data[MAXN][MAXN];
};
int mul(mat &c, const mat &a, const mat &b)
{
    int i, j, k;
    if (a.m != b.n)
        return 0;
    c.n = a.n, c.m = b.m;
    for (i = 0; i < c.n; i++)
        for (j = 0; j < c.m; j++)
            for (c.data[i][j] = k = 0; k < a.m; k++)
                c.data[i][j] += a.data[i][k] * b.data[k][j];
    return 1;
}
int inv(mat &a)
{
    int i, j, k, is[MAXN], js[MAXN];
    double t;
    if (a.n != a.m)
        return 0;
    for (k = 0; k < a.n; k++)
    {
        for (t = 0, i = k; i < a.n; i++)
            for (j = k; j < a.n; j++)
                if (fabs(a.data[i][j]) > t)
                    t = fabs(a.data[is[k] = i][js[k] = j]);
        if (zero(t))
            return 0;
        if (is[k] != k)
            for (j = 0; j < a.n; j++)
                t = a.data[k][j], a.data[k][j] = a.data[is[k]][j], a.data[is[k]][j] = t;
        if (js[k] != k)
            for (i = 0; i < a.n; i++)
                t = a.data[i][k], a.data[i][k] = a.data[i][js[k]], a.data[i][js[k]] = t;
        a.data[k][k] = 1 / a.data[k][k];
        for (j = 0; j < a.n; j++)
            int main()
            {

                return 0;
            }