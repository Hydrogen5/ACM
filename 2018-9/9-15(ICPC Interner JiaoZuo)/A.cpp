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
    int kase;
    scanf("%d", &kase);
    char a[20];
    char c[20] = "jessie";
    while (kase--)
    {
        scanf("%s", a);
        for (int i = 0; i < strlen(a); i++)
            a[i] = tolower(a[i]);

        int flag = 1;
        for (int i = 0; i <= 6; i++)
            if (a[i] != c[i])
            {
                flag = 0;
                break;
            }
        if (strcmp(a, c) == 0)
            printf("Good guy!\n");
        else
            printf("Dare you say that again?\n");
    }
    return 0;
}