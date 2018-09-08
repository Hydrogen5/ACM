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
int ma[] = {1, 2, 3, 5, 7, 11, 13, 17, 23, 31, 37, 53, 71, 73, 117, 131, 137, 173, 311, 317};
char n[110];
int bi[1000];
int main()
{
    int cnt = 1;
    for (int i = 1; i < 1000; i++)
    {
        if (i >= ma[cnt])
            cnt++;
        bi[i] = ma[cnt - 1];
    }
    int kase;
    scanf("%d", &kase);
    for (int i = 1; i <= kase; i++)
    {
        int tmp;
        scanf("%s", n);
        printf("Case #%d: ", i);
        if (strlen(n) > 3)
            printf("317\n");
        else
        {
            if (strlen(n) == 3)
            {
                tmp = (n[0] - '0') * 100 + (n[1] - '0') * 10 + (n[2] - '0');
            }
            if (strlen(n) == 2)
            {
                tmp = (n[0] - '0') * 10 + (n[1] - '0') * 1;
            }
            if (strlen(n) == 1)
            {
                tmp = (n[0] - '0');
            }
            printf("%d\n", bi[tmp]);
        }
    }
}