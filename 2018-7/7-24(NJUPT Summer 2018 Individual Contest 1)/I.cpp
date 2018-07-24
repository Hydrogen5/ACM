//Seat Arrangements 
#include <iostream>
using namespace std;
char x[2010][2010];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i = 0; i < n;i++)
        cin >> x[i];
    int ans = 0;
    for (int i = 0; i < n;i++)
    {
        int cnt = 0;
        for (int j = 0; j < m;j++)
        {
            if(x[i][j]=='.')
                cnt++;
            else cnt=0;
            if(cnt>=k)
                ans++;
        }
    }
    for (int i = 0; i < m;i++)
    {
        int cnt = 0;
        for (int j = 0; j < n;j++)
        {
            if(x[j][i]=='.')
                cnt++;
            else
                cnt = 0;
            if(cnt>=k)
                ans++;
        }
    }
    if(k==1)
        cout << ans / 2 << endl;
    else
        cout << ans << endl;
}