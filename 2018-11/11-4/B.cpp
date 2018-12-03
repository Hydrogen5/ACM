//IQ Test
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
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (((b - a) == (c - b)) && ((c - b) == (d - c)))
    {
        printf("%d\n", 2 * d - c);
    }
    else
    {
        if((a*c==b*b)&&(b*d==c*c))
        {
            int tmp = d * d / c;
            if(tmp*c==d*d)
                printf("%d\n",tmp);
            else
                printf("42\n");
        }
        else
            printf("42\n");
    }
    return 0;
}