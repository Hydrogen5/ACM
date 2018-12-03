//Fly, freebies, fly! 
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
using namespace std;
int a[110];
int main() 
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    a[n] = 100000;
    sort(a,a+n+1);
    int Max=0;
    int T;
    scanf("%d",&T);
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(a[j]>a[i]+T)
            {
                Max = max(Max, j - i);
                break;
            }
        }
    }
    printf("%d", Max);
    return 0;
}