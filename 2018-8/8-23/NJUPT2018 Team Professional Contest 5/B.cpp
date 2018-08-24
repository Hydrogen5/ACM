//Binary Encoding
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int m, a, b, answer[200], n2[20];
int pown(int x)
{
    int ans = 1;
    for (int i = 0; i < x; i++)
        ans *= 2;
    return ans;
}
void init()
{
    for (int i = 0; i < 20; i++)
        n2[i] = pown(i);
}
int main()
{
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
    init();
    scanf("%d", &m);
    for (int i = 0; i < 15; i++)
        if (m >= n2[i] && m < n2[i + 1])
        {
            a = i;
            break;
        }
    b = n2[a + 1] - m;
    for (int i = 0; i < m; i++)
    {
        memset(answer, 0, sizeof(answer));
        int p = 0;
        int xx;
        if (i >= b)
            xx = i + b;
        else
            xx = i;
        while (xx)
        {
            answer[p] = xx % 2;
            p++;
            xx /= 2;
        }
        if (i < b)
            for (int j = a - 1; j >= 0; j--)
                cout << answer[j];
        else
            for (int j = a; j >= 0; j--)
                cout << answer[j];
        cout << endl;
    }
    return 0;
}