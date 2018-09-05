//Fibonacci again and again
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
int f[15];
int SG[1010];
int S[1010];
int main()
{
    f[0] = 1;
    f[1] = 2;
    for (int i = 2; i <= 15; i++)
        f[i] = f[i - 1] + f[i - 2];
    memset(SG, 0, sizeof(SG));
    for (int i = 1; i <= 1000; i++)
    {
        memset(S, 0, sizeof(S));
        for (int j = 0; j <= 15 && f[j] <= i; j++)
            S[SG[i - f[j]]] = 1;
        for (int j = 0;; j++)
            if (!S[j])
            {
                SG[i] = j;
                break;
            }
    }
    int n, m, k;
    while (scanf("%d%d%d", &n, &m, &k) == 3&&(n+m+k))
    {
        int flag = SG[n] ^ SG[m] ^ SG[k];
        if (flag)
            printf("Fibo\n");
        else
            printf("Nacci\n");
    }
    return 0;
}