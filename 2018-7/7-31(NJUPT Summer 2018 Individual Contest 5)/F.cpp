//Partition 
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans = 0;
    while(n--)
    {
        int num;
        cin >> num;
        ans += num > 0 ? num : (-num);
    }
    cout << ans << endl;
}