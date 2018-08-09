#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[3];
int n[3];
int p[3];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        char s[110];
        cin >> s;
        memset(a, 0, sizeof(a));
        long long cnt = 0;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='B') a[0]++;
            if(s[i]=='M') a[1]++;
            if(s[i]=='C') a[2]++;
        }
        long long r;
        cin >> n[0] >> n[1] >> n[2];
        cin >> p[0] >> p[1] >> p[2];
        cin >> r;
        while(n[0]!=0||n[1]!=0||n[2]!=0)
        {
            for (int i = 0; i < 3;i++)
            {
                if(n[i]>=a[i])
                    n[i] -= a[i];
                else
                {
                    r -= (a[i] - n[i]) * p[i];
                    n[i] = 0;
                }
            }
            if(r<0)
                break;
            cnt++;
        }
        int com = p[0] * a[0] + p[1] * a[1] + p[2] * a[2];
        if(r<0)
            cout << cnt << endl;
        else
        {
            cnt += r / com;
            cout << cnt << endl;
        }

    }
}