//Keywords Search 
//AC自动机
//灾难啊
#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
char word[55];
char text[1000010];
int root, num;
struct Node
{
    int fail;
    int Next[26];
    int cnt;
    void init()
    {
        fail=-1;
        memset(Next,-1,sizeof(Next));
        cnt = 0;
    }
} node[500010];
void insert()
{
    int cur=0;
    int p = root;
    while(word[cur])
    {
        if(node[p].Next[word[cur]-'a']==-1)
        {
            node[++num].init();
            node[p].Next[word[cur] - 'a'] = num;
        }
        p = node[p].Next[word[cur] - 'a'];
        cur++;
    }
    node[p].cnt++;
}
int search()
{
    int p = root;
    int cnt = 0;
    int cur = 0;
    while(text[cur])
    {
        p = node[p].Next[text[cur] - 'a'];
        if(p==-1)
            p = root;
        int tmp=p;
        while(tmp!=root&&node[tmp].cnt!=-1)
        {
            cnt+=node[tmp].cnt;
            node[tmp].cnt=-1;
            tmp = node[tmp].fail;
        }
        cur++;
    }
    return cnt;
}
void build()
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        for (int i = 0; i < 26;i++)
        {
            if(node[cur].Next[i]!=-1)
            {
                int son = node[cur].Next[i];
                int p = node[cur].fail;
                if(cur==root)
                    node[son].fail=root;
                else
                    node[son].fail = node[p].Next[i];
                q.push(son);
            }
            else
            {
                int p = node[cur].fail;
                if(cur==root)
                    node[cur].Next[i] = root;
                else
                    node[cur].Next[i] = node[p].Next[i];
            }
        }
    }
}

void init()
{
    root = 0;
    num=0;
    node[0].init();
}
int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        init();
        cin>>n;
        for (int i = 1; i <= n;i++)
        {
            cin >> word;
            insert();
        }
        build();
        cin >> text;
        int ans = search();
        cout << ans << endl;
    }
}