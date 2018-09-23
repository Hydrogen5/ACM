//Saving Tang Monk II
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
int N, M;
char maze[110][110];
int dirx[] = {-1, 1, 0, 0};
int diry[] = {0, 0, -1, 1};
int vis[105][105][6];

struct Node
{
    int x, y;
    int cntB;
    int step;

} node;

bool operator<(const Node &a, const Node &b)
{
    if (a.step != b.step)
        return a.step < b.step;
    else
        if(a.x + a.y != b.x + b.y)
        return a.x + a.y < b.x + b.y;
        else
            return a.cntB > b.cntB;
}
int main()
{
    while (scanf("%d%d", &N, &M) == 2 && N + M)
    {
        for (int i = 0; i < N; i++)
            scanf("%s", maze[i]);
        memset(vis, 0, sizeof(vis));
        Node s;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (maze[i][j] == 'S')
                {
                    s.x = i;
                    s.y = j;
                }
            }
        }
        s.step = 0;
        s.cntB = 0;
        priority_queue<Node> q;
        int flag = 0;
        q.push(s);
        Node a, b;
        while (q.size())
        {
            a = q.top();
            q.pop();
            if (vis[a.x][a.y][a.cntB])
                continue;
            vis[a.x][a.y][a.cntB] = 1;
            if (maze[a.x][a.y] == 'B')
            {
                if (a.cntB < 5)
                    a.cntB++;
            }
            if (maze[a.x][a.y] == '#')
            {
                if (a.cntB == 0)
                    continue;
                a.cntB--;
                a.step++;
            }
            if (maze[a.x][a.y] == 'P')
            {
                a.step--;
            }
            if (maze[a.x][a.y] == 'T')
            {
                flag = 1;
                printf("%d\n", a.step);
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                b.x = a.x + dirx[i];
                b.y = a.y + diry[i];
                b.step = a.step + 1;
                b.cntB = a.cntB;
                if (b.x < 0 || b.x >= N || b.y < 0 || b.y >= M)
                    continue;
                q.push(b);
            }
        }
        if (!flag)
            printf("-1\n");
    }
    return 0;
}