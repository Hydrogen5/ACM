//Garden
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int m,length;
    cin >> m >> length;
    int Min=99999999;
    for (int i = 0; i < m;i++)
    {
        int b;
        cin>>b;
        if(length%b==0)
        {
            Min = min(Min, length / b);
        }
    }
    cout << Min << endl;
}