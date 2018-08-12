//Is It A Tree?
#include <iostream>
#include <cstdio>
using namespace std;
int flag;
int pre[100010];
int vis[100010];
int find(int x)
{
    if(pre[x]!=x)
        pre[x]=find(pre[x]);
    return pre[x];
}
void merge(int x,int y)
{
    int px=find(x);
    int py=find(y);
    if(px!=py)
        pre[py] = px;
    else
        flag = 1;
}
int main()
{
    int a,b;
    int kase = 1;
    while (cin >> a >> b)
    {
        if(a==-1&&b==-1)
            break;;
        if(a==0&&b==0)
        {
            printf("Case %d is a tree.\n", kase++);
            continue;
        }
        for(int i=1;i<=100000;i++)
        {
            pre[i]=i;
            vis[i] = 0;
        }
        flag = 0;
        merge(a,b);
        while(cin>>a>>b)
        {
            if(a==0&&b==0)
                break;
            merge(a,b);
            vis[a] = 1;
            vis[b] = 1;
        }
        int cnt = 0;
        for(int i=1;i<=100000;i++)
        {
            if(pre[i]==i&&vis[i])
                cnt++;
            if(cnt>1)
            {
                flag = 1;
                break;
            }
        }
        if(flag==1)
            printf("Case %d is not a tree.\n", kase++);
        else
            printf("Case %d is a tree.\n", kase++);
    }
}