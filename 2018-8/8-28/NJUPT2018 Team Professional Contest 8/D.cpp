//Longest Prefix Match
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
int root, num;
int prefix;
struct Node
{
    int Next[2];
    int cnt;
    void init()
    {
        cnt = -1;
        Next[0] = -1;
        Next[1] = -1;
    }
} node[5000100];
void init()
{
    root = 0;
    num = 0;
    node[0].init();
}
void insert(unsigned int prefix, int len, int id)
{
    int p = root;
    for (int i = 0; i <= len - 1; i++)
    {
        if (node[p].Next[(prefix >> (31 - i) & 1)] == -1)
        {
            node[++num].init();
            node[p].Next[((prefix >> (31 - i)) & 1)] = num;
        }
        p = node[p].Next[(prefix >> (31 - i) & 1)];
        if (i == len - 1)
        {
            node[p].cnt = id;
        }
    }
}
int search(unsigned int prefix)
{
    int ans = -1;
    int p = root;
    for (int i = 0; i <= 31; i++)
    {

        if (node[p].cnt != -1)
        {
            ans = node[p].cnt;
        }
        p = node[p].Next[(prefix >> (31 - i) & 1)];
        if (node[p].Next[(prefix >> (31 - i) & 1)] == -1)
            return ans;
    }
    return ans;
}
int main()
{
    // freopen("d.in", "r", stdin);
    int x, y;
    scanf("%d %d", &x, &y);
    init();
    unsigned int a;
    int len;
    int flag = -1;
    for (int i = 0; i < x; i++)
    {
        scanf("%x %d", &a, &len);
        insert(a, len, i);
        if (len == 0)
            flag = i;
    }
    for (int i = 0; i < y; i++)
    {
        scanf("%x", &a);
        int ans = search(a);
        printf("%d\n", ans == -1 ? flag : ans);
    }
    return 0;
}