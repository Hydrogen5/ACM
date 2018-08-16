//Game
#include <iostream>
#include <cstdio>
using namespace std;
char s[6][6];
int judge(char x)
{
    for(int i=0;i<5;i++)
    {
        for (int j = 0;j<5;j++)
        {
            if(j+2<5&&s[i][j]==x&&s[i][j+1]==x&&s[i][j+2]==x)
                return 1;
            if(i+2<5&&s[i][j]==x&&s[i+1][j]==x&&s[i+2][j]==x)
                return 1;
            if(i+2<5&&j+2<5&&s[i][j]==x&&s[i+1][j+1]==x&&s[i+2][j+2]==x)
                return 1;
            if(i-2>=0&&j+2<5&&s[i][j]==x&&s[i-1][j+1]==x&&s[i-2][j+2]==x)
                return 1;
        }
    }
    return 0;
}
int main()
{
    int Z;
    scanf("%d",&Z);
    while(Z--)
    {
        for(int i=0;i<5;i++)
        {
            scanf("%s", s[i]);
        }
        int fa=0;
        int fb=0;
        fa = judge('A');
        fb = judge('B');
        if(fa==fb)
        puts("draw");
        else
        {
            if(fa==1)
                puts("A wins");
            else
                puts("B wins");
        }
    }
}