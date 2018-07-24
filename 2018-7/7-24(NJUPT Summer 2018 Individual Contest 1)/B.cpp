//Magic Forest 
#include<iostream>
using namespace std;
int ans[2510];
int main()
{
	ans[1]=0;
    for (int a = 2; a <= 2500;a++)
    {
        ans[a] = ans[a - 1];
        for (int b = 1; b <= a; b++)
        {
            int c=a^b;
            if(c>b&&c>=1&&c<=a&&a+b>c&&a+c>b&&b+c>a)
                ans[a]++;
        }
    }
    int n;
    while(cin>>n)
        cout << ans[n] << endl;
}