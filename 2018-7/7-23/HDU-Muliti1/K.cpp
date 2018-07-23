//Time Zone
//简单模拟
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int sgn;
        int a, b, x, y(0);
        string s;
        cin >> a >> b >> s;
        sgn = (s[3] == '+' ? 1 : -1);
        s = s.substr(4);
        if (s.size() > 2) 
        {
            y = s.back() - '0';
            s.pop_back();
            s.pop_back();
        }
        x = stoi(s);

        int m = (a + 24) * 60 + b;

        int c = 80;
        int d = sgn * (x * 10 + y);
        int e = d - c;
        int f = e * 6;
        int g = (m + f) % 1440;

        printf("%02d:%02d\n", g / 60, g % 60);
    }
} 