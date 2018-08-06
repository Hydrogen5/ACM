//True Liars
//并查集
#include <iostream>
#include <cstdio>
using namespace std;
int pre[100000];
int find(int x)
{
    if(pre[x]!=x)
        pre[x]=find(pre[x]);
    return pre[x];
}
void mix(int x,int y)
{
    int px=find(x);
    int py=find(y);
    if(px!=py)
        pre[py] = px;
}
int main()
{
    int n, p1, p2;
    while(cin>>n>>p1>>p2)
    {
        for (int i = 0; i <= n;i++)
            pre[i] = i;
        for (int i = 1; i <= n;i++)
        {
            int a, b;
            cin>>a>>b;
            char s[5];
            cin >> s;
        }
    }
}