//小希的迷宫
#include <cstdio>
using namespace std;
int pre[100010];
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
        if(a==0&&b==0) 
        {
            printf("Yes\n");
            continue;
        }
        for(int i=1;i<=100000;i++)
            pre[i] = i;
        merge(a,b);
        int flag = 1;
        while(scanf("%d %d",&a,&b)!=EOF)
        {
            if(a==0&&b==0)
            {
                if(flag)
                    printf("Yes\n");
                else
                    printf("No\n");
                break;
            }
            if(find(a)==find(b))
                flag = 0;
            merge(a, b);
        }
    }
}