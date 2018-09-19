//Common Subexpression Elimination
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int cur, cnt;
int vis[500100];
struct Node
{
    string n;
    int ha, l, r;
    bool operator<(const Node b) const
    {
        if (ha != b.ha)
            return ha < b.ha;
        if (l != b.l)
            return l < b.l;
        return r < b.r;
    }
} node[50010];
char s[500100];
map<Node, int> dic;
int solve()
{
    int tmp = cnt++;
    node[tmp].n = "";
    node[tmp].ha = 0;
    node[tmp].l=-1;
    node[tmp].r = -1;
    while (isalpha(s[cur]))
    {
        node[tmp].n.push_back(s[cur]);
        node[tmp].ha *= 27;
        node[tmp].ha += s[cur]-'a'+1;
        cur++;
    }
    if (s[cur] == '(')
    {
        cur++;
        node[tmp].l = solve();
        cur++;
        node[tmp].r = solve();
        cur++;
    }
    if(dic.count(node[tmp]))
    {
        cnt--;
        return dic[node[tmp]];
    }
    dic[node[tmp]] = tmp;
    return tmp;
}
void print(int id)
{
    if(vis[id])
        printf("%d", id+1);
    else
    {
        vis[id]=1;
        printf("%s", node[id].n.c_str());   
        if(node[id].l!=-1)
        {
            putchar('(');
            print(node[id].l);
            putchar(',');
            print(node[id].r);
            putchar(')');
        }
    }
}
int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        dic.clear();
        gets(s);
        cur = 0;
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        print(solve());
        puts("");
    }
    return 0;
}