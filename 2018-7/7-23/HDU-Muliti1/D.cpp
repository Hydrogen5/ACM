//Distinct Values
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int ar[100000000];
struct request{
    int l,r;
} r[1000100];
int cmp(request a,request b)
{
    if(a.l<b.l) return 1;
    if(a.l==b.l)
        return a.r > b.r;
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i = 1;i<=n;i++) ar[i]=1;
        for (int i = 0; i < m;i++)
            scanf("%d%d",&r[i].l, &r[i].r);
        sort(r, r + m, cmp);
        for(int i=0;i<m;i++)
        {
            if(r[i-1].r>=r[i].r)
            {
                continue;
            }
            if(r[i-1].r>=r[i].l)
            {
                ar[r[i-1].r+1]=1;
                for (int j = r[i - 1].r + 2; j <= r[i].r;j++)
                    ar[j] = ar[j - 1] + 1;
            }
            else
            {
                for (int j = r[i].l + 1; j <= r[i].r;j++)
                    ar[j] = ar[j - 1] + 1;
            }
        }
        for(int i=1;i<n;i++)
        cout<<ar[i]<<" ";
        cout << ar[n] << endl;
    }
}