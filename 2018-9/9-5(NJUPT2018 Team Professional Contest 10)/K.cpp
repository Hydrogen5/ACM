//Escape Room
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
vector<int> v[100010];
int a[100010];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 100000; i++)
        v[i]
            .clear();
    int Max = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        v[tmp].push_back(i);
        if (tmp > Max)
            Max = tmp;
    }
    int k = n;
    for (int i = 1; i <= Max; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            a[v[i][j]] = k--;
        }
    }
    printf("%d", a[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", a[i]);
    puts("");
    return 0;
}