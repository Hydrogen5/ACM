//Unique Encryption Keys
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
map<int, int> p;
int a[1000010];
int Next[1000010];
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) == 2)
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        p.clear();
        memset(Next, 0, sizeof(Next));
        Next[n + 1] = n + 1;
        for (int i = n; i >= 1; i--)
        {
            Next[i] = Next[i + 1];
            if (p.find(a[i]) != p.end())
                Next[i] = min(Next[i], p[a[i]]);
            p[a[i]] = i;
        }
        while (m--)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            if (r < Next[l])
                printf("OK\n");
            else
                printf("%d\n", a[Next[l]]);
        }
        puts("");
    }
    return 0;
}