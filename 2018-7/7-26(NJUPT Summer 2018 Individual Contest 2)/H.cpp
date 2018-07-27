//Substrings Sort
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct x{
    int a;
    string s;
}b[111];
int cmp(x m,x n)
{
    return m.a < n.a;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin>>b[i].s;
        b[i].a = b[i].s.size();
    }
    sort(b,b+n,cmp);
    for (int i = 0; i < n-1;i++)
    {
        if(b[i+1].s.find(b[i].s)== string::npos)
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    for (int i = 0; i < n;i++)
        cout << b[i].s << endl;
}