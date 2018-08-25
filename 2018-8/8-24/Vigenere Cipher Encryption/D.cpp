//The Grille
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
string a[1003];
string b[1005];
int main()
{
    ios::sync_with_stdio(0);
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        string ans = "";
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] == 'O')
                    ans += b[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[n - 1 - j][i] == 'O')
                    ans += b[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[n - 1 - i][n - 1 - j] == 'O')
                    ans += b[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[j][n - i - 1] == 'O')
                    ans += b[i][j];
        cout << ans << endl;
    }
    return 0;
}