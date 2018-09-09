#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
map<pair<int, int>, int> m;
set<pair<int, int>> s[2];
int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int k;
        scanf("%d", &k);
        if (k == 0)
            printf("0\n");
        else
        {
            int a, b;
            int Max = 1;
            s[0].clear();
            m.clear();
            for (int i = 1; i <= k; i++)
            {
                int ks;
                scanf("%d", &ks);
                s[i % 2].clear();
                while (ks--)
                {
                    scanf("%d%d", &a, &b);
                    if (m.find(make_pair(a, b)) == m.end())
                        m[make_pair(a, b)] = 1;
                    s[i % 2].insert((make_pair(a, b)));
                }
                set<pair<int, int>>::iterator it = s[i % 2].begin();

                for (; it != s[i % 2].end(); it++)
                {
                    if (s[(i - 1) % 2].find(*it) != s[(i - 1) % 2].end())
                    {
                        m[*it]++;
                        Max = max(Max, m[*it]);
                    }
                    else
                        m[*it] = 1;
                }
            }
            printf("%d\n", Max);
        }
    }
    return 0;
}