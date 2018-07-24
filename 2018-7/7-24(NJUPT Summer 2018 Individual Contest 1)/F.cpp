//Alena And The Heater 
#include <iostream>
#include <algorithm>
using namespace std;
int a[100100];
char b[100010];
int findmin(int i)
{
    int minx=a[i];
    minx = min(minx, a[i - 1]);
    minx = min(minx, a[i - 2]);
    minx = min(minx, a[i - 3]);
    minx = min(minx, a[i - 4]);
    return minx;
}
int findmax(int i)
{
    int maxx=a[i];
    maxx = max(maxx, a[i - 1]);
    maxx = max(maxx, a[i - 2]);
    maxx = max(maxx, a[i - 3]);
    maxx = max(maxx, a[i - 4]);
    return maxx;
}
int all4b(int cur)
{
    if(b[cur-1]==b[cur-2]&&b[cur-2]==b[cur-3]&&b[cur-3]==b[cur-4])
    {
        if(b[cur-1]=='0') return 0;
        else
            return 1;
    }
    else
        return -1;
}
int main()
{
    int n;
    cin>>n;
    for (int i = 0;i<n;i++)
        cin >> a[i];
    cin >> b;
    int minl = -99990, maxr = 99999;
    for (int i = 4;i<n;i++)
    {
        if(b[i]!=b[i-1])
        {
            if(b[i]=='1')
                minl = max(minl, findmax(i) + 1);
            else
                maxr = min(maxr, findmin(i) - 1);
        }
    }
    cout << minl << " " << maxr << endl;
}