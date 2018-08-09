//小希的迷宫
#include <cstdio>
#include <cstring>
using namespace std;
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
}
int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF&&(a!=-1||b!=-1))
    {
        memset(vis, 0, sizeof(vis));
        if(a==0&&b==0) 
        {
            printf("Yes\n");
            continue;
        }
        vis[a] = 1;
        vis[b] = 1;
        for(int i=1;i<=100000;i++)
            pre[i] = i;
        merge(a,b);
        int flag = 1;
        while(scanf("%d %d",&a,&b)!=EOF)
        {
            vis[a]=1;
            vis[b] = 1;
            if(a==0&&b==0)
                break;
            if(find(a)==find(b))
                flag = 0;
            merge(a, b);
        }
        int cnt = 0;
        for (int i = 1; i <= 100000;i++)
        {
            if(vis[i]&&vis[i]==i)
                cnt++;
            if(cnt>1)
            {
                flag=0;
                break;
            }
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
}