// Odd Chess
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
int N;
long long cnt = 0;
int chess[2010][2010];
int C[2010];
int B[2010][2];
int M;
void black(int cur, int tot)
{
    if (cur == N)
    {
        cnt++;
        // cnt %= M;
    }
    else
    {
        if (tot == 0)
        {
            for (int i = 0; i < N - 1; i++)
            {
                if (C[cur] == i)
                    continue;
                int ok = 1;
                int flag = 0;
                B[cur][tot] = i;
                for (int j = 0; j < cur; j++)
                    if (i == B[j][0] || i == B[j][1])
                    {
                        if (flag == 1)
                        {
                            ok = 0;
                            break;
                        }
                        flag = 1;
                    }
                if (ok)
                    black(cur, 1);
            }
        }
        else
        {
            for (int i = B[cur][0] + 1; i < N; i++)
            {
                if (C[cur] == i)
                    continue;
                int ok = 1;
                int flag = 0;
                B[cur][tot] = i;
                for (int j = 0; j < cur; j++)
                    if (i == B[j][0] || i == B[j][1])
                    {
                        if (flag == 1)
                        {
                            ok = 0;
                            break;
                        }
                        flag = 1;
                    }
                if (ok)
                    black(cur + 1, 0);
            }
        }
    }
}
void white(int cur)
{
    if (cur == N)
        black(0, 0);
    //递归边界。只要走到了这里，所有皇后必然不冲突
    else
        for (int i = 0; i < N; i++)
        {
            int ok = 1;
            C[cur] = i;
            for (int j = 0; j < cur; j++)
                //尝试把第cur行的皇后放在第i列 //检查是否和前面的皇后冲突
                if (C[cur] == C[j])
                {
                    ok = 0;
                    break;
                }
            if (ok)
                white(cur + 1);
            //如果合法，则继续递归 }
        }
}
int main()
{
    // int t;
    // scanf("%d", &t);
    for(int i=3;i<=2000;i++)
    {
        // scanf("%d", &N);
        N = i;
        cnt = 0;
        white(0);
        printf("%d\n", cnt);
    }
    return 0;
}
