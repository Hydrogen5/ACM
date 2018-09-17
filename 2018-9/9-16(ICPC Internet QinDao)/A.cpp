#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
int main() 
{
    int kase;
    scanf("%d", &kase);
    while(kase--)
    {
        int n,m;
        scanf("%d%d", &n, &m);
        if(m==0)
        {
            printf("0 0\n");
        }
        else
        {
            if(n==m)
                printf("%d %d\n", m, m);
            else
            {
                float tmp = (float)((float)m / (n - m + 1));
                printf("%d %d\n", m,(int)ceil(tmp));
            }
        }
    }
    return 0;
}