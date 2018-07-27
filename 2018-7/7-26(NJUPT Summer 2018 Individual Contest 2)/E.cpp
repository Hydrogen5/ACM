//String Typing
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string c;
    cin >> c;
    int num = 1;
    for (int i = 1; i < n; i++)
        if (c.substr(0, i) == c.substr(i, i))
            num = i;
    cout<<n-num+1;
}