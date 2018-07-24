//Adjacent Replacements
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i = 1;i<n;i++)
    {
        int a;
        cin>>a;
        cout << a - (a - 1) % 2<<" ";
    }
    int a;
    cin>>a;
    cout << a - (a - 1) % 2 << endl;
}