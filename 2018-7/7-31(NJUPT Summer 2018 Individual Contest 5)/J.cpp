//Getting an A
#include <iostream>
#include <algorithm>
using namespace std;
int point[111];
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n;i++)
    {
        cin>>point[i];
        sum += point[i];
    }
    sort(point, point + n);
    int cnt = 0;
    while(sum<4.5*n)
        sum = sum - point[cnt++] + 5;
    cout << cnt << endl;
}
