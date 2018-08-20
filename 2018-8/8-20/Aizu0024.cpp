//Physical Experiments
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
    double v;
    while(cin>>v)
    {
        double t = v / 9.8;
        double y = 4.9 * t * t;
        int N = (y + 5) / 5 + 1;
        cout << N << endl;
    }
    return 0;
}