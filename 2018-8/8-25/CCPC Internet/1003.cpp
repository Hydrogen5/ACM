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
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int p;
        scanf("%d", &p);
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < p; j++)
            {
                if (j != 0)
                    printf(" ");
                printf("%d", (i + j) % p);
            }
            printf("\n");
        }
        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < p; j++)
            {
                if (j != 0)
                    printf(" ");
                printf("%d", (i * j) % p);
            }
            printf("\n");
        }
    }
    return 0;
}