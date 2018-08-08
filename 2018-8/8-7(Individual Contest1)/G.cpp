#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int ans[20][20000];
int two[20];
int main()
{
    int tmp = 2;
    for (int i = 1;i<=15;i++)
    {
        two[i]=tmp-1;
        tmp *= 2;
    }
    ans[1][1] = 0; //1
    // ans[2]="001";//2
    // ans[3] = "0010011";//4
    // ans[4]="0,0,1,0,0,1,1,0,0,0,1,1,0,1,1";//8
    for (int i = 1;i<=16;i++)
    {
        for (int j =1 ; j <= two[i];j++)
            ans[i + 1][j * 2] = ans[i][j];
        int cnt = 0;
        for (int j =1 ; j <= two[i+1];j+=2,cnt++)
            ans[i + 1][j] = cnt%2;
    }
    int T;
    while(cin>>T)
    {
        for (int i = 1; i <= two[T];i++)
            cout << ans[T][i];
        cout << endl;
    }
}