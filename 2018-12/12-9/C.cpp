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
int a[105], ans[100];

int main()
{
    int n, m, t = 0, sum = 0, l, r;
    l = r = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n - 1; i += 2)
    {
        a[i] % 2 ? l++ : r++;
        a[i + 1] % 2 ? l++ : r++;
        if (l == r && i != n - 1)
        {
            ans[t++] = abs(a[i + 2] - a[i + 1]);
            l = r = 0;
        }
    }
    sort(ans, ans + t);
    for (int i = 0; i < t; i++)
        if (m - ans[i] >= 0)
            m -= ans[i], sum++;
    cout << sum << endl;
    return 0;
}
