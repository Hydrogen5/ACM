//Comparing answers
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a1[1010][1010];
int Right[1010][1010];
int a2[1010][1010];
int n;
int mul[15][15];
int check(int i,int j)
{
    int tmp=0;
    for (int k = 1;k<=n;k++)
    {
        tmp += mul[a1[i][k]][a1[k][j]];
    }
    if(tmp==a2[i][j])
        return 1;
    else
        return 0;
}
void init()
{
    for (int i = 0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
            mul[i][j] = i * j;
    }
}
int main()
{
    init();
    while(cin>>n&&n!=0)
    {
        for(int i=1;i<=n;i++)
            for (int j = 1; j <= n;j++)
                scanf("%d", &a1[i][j]);
        for(int i=1;i<=n;i++)
            for (int j = 1; j <= n;j++)
                scanf("%d", a2[i][j]);        
       
        int flag = 1;
        for(int i=1;i<=n;i++)
            for (int j = 1; j <= n;j++)
                if(!check(i,j))
                    {
                        flag = 0;
                        break;
                    }
                
        if(flag) puts("YES");
        else
            puts("NO");

    }
}