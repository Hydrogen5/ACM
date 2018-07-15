//Detect the Virus 
//AC自动机+模拟解base64
#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
int vis[50000000];
using namespace std;
char s1[50000];
char s2[50000];
char tet[5000000];
char text[500000];
int num, root, len;
struct Node
{
    int cnt;
    int Next[130];
    int fail;
    void init()
    {
        fail=-1;
        memset(Next, -1, sizeof(Next));
        cnt = 0;
    }
} node[500000];
void decode(char s1[],char s2[])
{
    len = strlen(s1);
    while(s1[len-1]=='=')    len--;
    for (int i = 0; i < len;i++)
    {
        if (s1[i] >= 'A'&&s1[i] <= 'Z')
        {
            s1[i] -= 'A';
            continue;
        }
        if (s1[i] >= 'a' && s1[i] <= 'z')
        {
            s1[i]=s1[i]- 'a' + 26;
            continue;
        }
        if (s1[i] >= '0' && s1[i] <= '9')
        {
            s1[i] =s1[i]- '0' + 52;
            continue;
        }
        if (s1[i]== '+')
            s1[i]= 62;
        else
            s1[i] = 63;
    }
    int cnt=0;
    for (int j = 0; j < len;j+=4)
    {
        s2[cnt++] = (s1[j] << 2) | (s1[j + 1] >> 4);
        if(j+2<len) s2[cnt++]=(s1[j+1]<<4)|(s1[j+2]>>2);
        if(j+3<len) s2[cnt++]=(s1[j+2]<<6)|(s1[j+3]);
    }
    s2[cnt] = '\0';
}
void init()
{
    root=0;
    num=0;
    node[root].init();
}
void insert()
{
    int cur=0;
    int p = root;
    while(s2[cur])
    {
        if(node[p].Next[s2[cur]-0]==-1)
        {
            node[++num].init();
            node[p].Next[s2[cur]-0] = num;
        }
        p = node[p].Next[s2[cur]-0];
        cur++;
    }
    node[p].cnt++;
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
                if(cur==root) node[son].fail=root;
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
    int p=root;
    int cur=0;
    int cnt = 0;
    while(text[cur])
    {
        p = node[p].Next[text[cur]-0];
        if(p==-1)
            p = root;
        int tmp=p;
        while(tmp!=root&&node[tmp].cnt)
        {
            if(vis[tmp]==0)
            {
                cnt += node[tmp].cnt;
                vis[tmp] = 1;
            }
            tmp = node[tmp].fail;
        }
        cur++;
    }
    return cnt;
}
int main()
{
    int n;
    while(cin>>n)
    {
        init();
        for (int i = 1; i <= n;i++)
        {
            cin >> s1;
            decode(s1,s2);
            insert();
        }
        build();
        int m;
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            cin >> tet;
            decode(tet, text);
            memset(vis, 0, sizeof(vis));
            cout << search() << endl;
        }
        cout << endl;
    }
}   
