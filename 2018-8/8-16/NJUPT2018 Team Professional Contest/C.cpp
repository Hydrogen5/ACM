//Search by template
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char RE[110];
char text[1000010];
struct Node{
    bool x[60];
} node[110];
int ans[1000010];
int lt;
int need;
void pre()
{
    int cnt = 0;
    for(int i=0;i<lt;i++)
    {
        if(RE[i]=='?')
        {
            for(int j=0;j<60;j++)
                node[cnt].x[j] = 1;
            cnt++;
            continue;
        }
        if(RE[i]=='[')
        {
            i++;
            while(RE[i]!=']')
            {
                node[cnt].x[RE[i] - 'A'] = 1;
                i++;
            }
            cnt++;
            continue;            
        }
        if(RE[i]=='{')
        {
            for(int j=0;j<60;j++)
                node[cnt].x[j] = 1;
            i++;
            while(RE[i]!='}')
            {
                node[cnt].x[RE[i] - 'A'] = 0;
                i++;
            }
            cnt++;
            continue;
        }
        node[cnt++].x[RE[i] - 'A'] = 1;
    }
    need = cnt;
}
int solve(int x)
{
    for(int i=0;i<need;i++)
    {
        if(!node[i].x[text[x+i]-'A'])
            return 0;
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        memset(node, 0, sizeof(node));
        scanf("%s",RE);
        lt = strlen(RE);
        pre();
        scanf("%s", text);
        int len=strlen(text);
        int cnt = 0;
        for(int i=0;i<=len-need;i++)
        {
            if(solve(i))
            {
                ans[cnt++] = i + 1;
            }
        }
        if(cnt!=0)
        {
            printf("%d", ans[0]);
            for(int i=1;i<cnt;i++)
                printf(" %d", ans[i]);
            printf("\n");
        }
        else
            printf("no match\n");
    }
}