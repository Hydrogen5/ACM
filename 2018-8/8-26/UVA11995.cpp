//I Can Guess the Data Structure!
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
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        priority_queue<int> pq;
        queue<int> q;
        stack<int> s;
        int f1 = 1, f2 = 1, f3 = 1;
        int cnt = 0;
        while (n--)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (a == 1)
            {
                pq.push(b);
                q.push(b);
                s.push(b);
            }
            if (a == 2)
            {
                if (s.top() != b)
                    f1 = 0;
                if (q.front() != b)
                    f2 = 0;
                if (pq.top() != b)
                    f3 = 0;
                s.pop();
                q.pop();
                pq.pop();
            }
        }
        if (f1)
            cnt++;
        if (f2)
            cnt++;
        if (f3)
            cnt++;
        if (cnt > 1)
            puts("not sure");
        else if (cnt == 0)
            puts("impossible");
        else
        {
            if (f1)
                puts("stack");
            if (f2)
                puts("queue");
            if (f3)
                puts("priority queue");
        }
    }
    return 0;
}