//最长回文
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[110010];
char ns[220020];
int point[220020];
int len;
void init()
{
    ns[0]='*';
    ns[1] = '#';
    for(int i=0;i<len;i++)
    {
        ns[i*2+2]=s[i];
        ns[i * 2 + 3] ='#';
    }
    len = len * 2 + 2;
    ns[len] = '\0';
}
void manacher()
{
    int maxright=0;
    int id;
    for(int i=1;i<len;i++)
    {
        if (i < maxright)   
            point[i]=min(point[2*id-i],maxright-i);
        else
            point[i] = 1;
        while(ns[i-point[i]]==ns[i+point[i]])
            point[i]++;
        if(i+point[i]>maxright)
        {
            id=i;
            maxright = i + point[i];
        }

    }

}
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        memset(ns, 0, sizeof(ns));
        memset(point, 0, sizeof(point));
        len=strlen(s);
        init();
        int ans = -1;
        manacher();
        for(int i = 0; i <= len; i++)
        {
            ans = max(ans, point[i]);
        }
        printf("%d\n", ans-1);
    }
}