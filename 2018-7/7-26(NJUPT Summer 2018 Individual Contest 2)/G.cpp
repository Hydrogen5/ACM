//Caisa and Pylons
#include <iostream>
using namespace std;
int h[100000];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
    int ans = 0;
    int e = 0;
    for (int i= 0; i < n; ++i)
    {
        if (h[i] + e < h[i + 1])
        {
            int t = (h[i + 1] - e - h[i]);
            h[i] += t;
            ans += t;
        }
        e += (h[i] - h[i + 1]);
    }
    cout << ans << endl;

}
