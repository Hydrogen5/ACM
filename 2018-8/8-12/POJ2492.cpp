//A Bug's Life 
#include <iostream>
#include <cstdio>
using namespace std;
int pre[4010];
int find(int x)
{
    if(x!=pre[x])
        pre[x] = find(pre[x]);
    return pre[x];
}
int judge(int x,int y)
{
    int px=find(x);
    int py=find(y);
    if(px==py)
        return 0;
    return 1;
}
void merge(int x,int y)
{
    int px=find(x);
    int py=find(y);
    if(px!=py)
        pre[px] = py;
}
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int k=1;k<=2*n;k++)
            pre[k] = k;
        int flag = 1;
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(judge(a,b)||judge(a+n,b+n))
            {
                merge(a + n, b);
                merge(a, b + n);
            }
            else
                flag = 0;
        }
        if(flag==0)
            printf("Scenario #%d:\nSuspicious bugs found!\n", i);
        else
            printf("Scenario #%d:\nNo suspicious bugs found!\n", i);
        if(i<t)
            printf("\n");
    }
}