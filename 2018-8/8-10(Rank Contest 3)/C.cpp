#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char s[300010];
int main()
{
    int n;
    long long a, b;
    cin>> n >> a >> b;
    cin >> s;

    int cnt = 0;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            if (flag == 0)
            {
                cnt++;
                flag = 1;
            }
        }
        if (s[i] == '1')
            flag = 0;
        }
    if(a>b)
        cout << cnt * b << endl;
    else
        cout << (cnt - 1) * a + b << endl;
}