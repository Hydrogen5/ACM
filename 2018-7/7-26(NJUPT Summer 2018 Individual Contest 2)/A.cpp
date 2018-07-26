//Game
#include <iostream>
#include <algorithm>
using namespace std;
int x[11111];
int main()
{
    int n;
    cin >> n;
    for (int i = 1;i<=n;i++)
        cin>>x[i];
    sort(x+1,x+n+1);
    cout << (n % 2 == 0 ? x[n / 2] : x[n / 2 + 1]) << endl;
}