#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
set<int> a;
set<int> b;
int sa[1010];
int sb[1010];
int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n;i++)
    {
        cin>>sa[i];
        a.insert(sa[i]);
    }
    for (int i = 1; i <= n;i++)
    {
        cin>>sb[i];
        b.insert(sb[i]);
    }
    int cnt=0;
    for (int i = 1;i<=n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            int tmp = sa[i] ^ sb[j];
            if(a.find(tmp)!=a.end()||b.find(tmp)!=b.end())
                cnt++;
        }
    }
    cout << cnt % 2 << endl;
}