//Shattered Cake
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
int main() 
{
    int W;
    scanf("%d",&W);
    int N;
    scanf("%d",&N);
    int sw=0;
    for(int i=0;i<N;i++)
    {
        int w,l;
        scanf("%d%d",&w,&l);
        sw += w * l;
    }
    cout << sw/W<<endl;
    return 0;
}