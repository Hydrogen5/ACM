//病毒侵袭 
//AC自动机
//继续受苦
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct Node
{
    int fail;
    int Next[130];
    int cnt;
    int code;
    void init()
    {
        fail=-1;
        memset(Next, -1, sizeof(Next));
        cnt = 0;
        code = 0;
    }
} node[500010];
int root=0;
int num;
char word[210];
char text[10010];
int ans[5];
void init()
{
    num=0;
    root=0;
    node[root].init();
}
void insert(int i)
{
    int cur = 0;
    int p = root;
    while(word[cur])
    {
        if(node[p].Next[word[cur]-0]==-1)
        {
            node[++num].init();
            node[p].Next[word[cur]-0] = num;
        }
        p = node[p].Next[word[cur]-0];
        cur++;
    }
    node[p].cnt=1;
    node[p].code = i;
}
void build()
{
    queue<int> q;
    int root = 0;
    q.push(root);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for (int i = 0;i<130;i++)
        {
            int p = node[cur].fail;
            if(node[cur].Next[i]!=-1)
            {
                int son=node[cur].Next[i];
                if(cur==root)
                    node[son].fail = root;
                else
                    node[son].fail = node[p].Next[i];
                q.push(son);
            }
            else
            {
                if(cur==root)
                    node[cur].Next[i]=root;
                else
                    node[cur].Next[i] = node[p].Next[i];
            }
        }
    }
}
int search()
{
    int cnt=0;
    int cur=0;
    int p = root;
    while(text[cur])
    {
        p=node[p].Next[text[cur]-0];
        if(p==-1)
            p = root;
        int tmp=p;
        while(tmp!=root&&node[tmp].code)
        {
            ans[cnt] = node[tmp].code;
            cnt += node[tmp].cnt;
            tmp = node[tmp].fail;
        }
        cur++;
    }
   
    return cnt;
}
int main()
{
    int N;
    cin>>N;
    init();
    for (int i = 1;i<=N;i++)
    {
       
        cin >> word;
        insert(i);
    }
    build();
    int m;
    int cnt = 0;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin >> text;
        int num = search();
        if(num)
        {
            cnt++;
            printf("web %d:",i);
            sort(ans,ans+num);
            for(int j=0;j<num;j++)
            printf(" %d",ans[j]);
            printf("\n");
        }
    }
    printf("total: %d\n",cnt);
    cin >> N;
}
