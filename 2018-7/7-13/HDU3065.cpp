//病毒侵袭持续中 
//AC自动机
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int cnt[10010];
struct Node
{
    int code;
    int Next[130];
    int fail;
    void init()
    {
        code=0;
        memset(Next,-1,sizeof(Next));
        fail = 0;
    }
} node[100000];
char text[2000010];
char word[1010][55];
int root;
int num;
void init()
{
    root=0;
    num=0;
    node[root].init();
    memset(cnt,0,sizeof(cnt));
}
void insert(int i)
{
    int cur = 0;
    int p = root;
    while(word[i][cur])
    {
        if(node[p].Next[word[i][cur]-0]==-1)
        {
            node[++num].init();
            node[p].Next[word[i][cur] - 0] = num;
        }
        p = node[p].Next[word[i][cur] - 0];
        cur++;
    }
    node[p].code = i;
}
void build()
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < 130;i++)
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
                    node[cur].Next[i] = root;
                else
                    node[cur].Next[i] = node[p].Next[i];
            }
        }
    }
}
void search()
{
    int p=root;
    int cur = 0;
    while(text[cur])
    {
        p = node[p].Next[text[cur] - 0];
        //if(p==-1)
          //  p=root;
        
        int tmp=p;
        while(tmp!=root)
        {
            if(node[tmp].code)
                cnt[node[tmp].code]++;
            tmp = node[tmp].fail;
        }
        cur++;
    }
}
int main()
{
    int N;
    cin>>N;
    init();
    for(int i=1;i<=N;i++)
    {
        cin >> word[i];
        insert(i);
    }
    build();
    cin >> text;
    search();
    for(int i=1;i<=N;i++)
    {
        if(cnt[i])
            cout << word[i] << ": " << cnt[i] << endl;
    }
}