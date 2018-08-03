//食物链
//pre[1-n]同类，pre[n+1-2n]他吃他的pre
#include <iostream>
#include <cstdio>
using namespace std;
int pre[7010000];
int find(int x)
{
    if(x==pre[x]) return x;
    return pre[x]=find(pre[x]);
}
void mix(int x,int y)
{
    int px = find(x);
    int py = find(y);
    pre[px] = py;
}   
int main()
{
    int n,m;
    
        for(int i=0;i<=3*n;i++) pre[i] = i;
        int ans = 0;
        while(m--)
        {
            int D, a, b;
            scanf("%d %d %d",&D,&a,&b);
            if(a>n||b>n) ans++;
            else
            {
                if(D==1)
                {
                    if(find(a)==find(b+n)||find(a)==find(b+2*n))
                        ans++;
                    else
                    {
                        mix(a,b);
                        mix(a+n,b+n);
                        mix(a + 2 * n, b + 2 * n);
                    }
                }
                else 
                {
                    if (a == b || find(a) == find(b) || find(a) == find(b + n))
                            ans++;
                    else
                    {
                        mix(a, b + 2 * n);
                        mix(a+n,b);
                        mix(a+2*n,b+n);
                    }
                }
            }
            
        }
        cout << ans << endl;
}