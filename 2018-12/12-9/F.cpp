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
// typedef pair<int, int> pack;
int a[14];
int main()
{
    int n, sum = 0, Min = 1000000;
    cin >> n;
    int t;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (Min > a[i])
        {
            Min = a[i], t = i;
        }
    }
    if (n == 1)
        cout << "-1" << endl;
    else
    {
        if (Min == (sum - Min))
            cout << "-1" << endl;
        else
        {
            cout << 1 << endl
                 << t << endl;
        }
    }
    return 0;
}