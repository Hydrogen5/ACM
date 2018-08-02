//How Many Tables 
#include <iostream>
#include <cstring>
using namespace std;
int pre[1010];
int vis[1010];
int find(int x)
{
    if(x!=pre[x])
        pre[x] = find(pre[x]);
    return pre[x];
}
void mix(int a,int b)
{
    int pa=find(a);
    int pb=find(b);
    if(pa!=pb)
        pre[pb] = pa;
}
int main()
{  
    int T;
    cin>>T;
    while(T--)
    {
        int N,M;
        cin>>N>>M;
        for(int i=1;i<=N;i++)
            pre[i] = i;
        memset(vis, 0, sizeof(vis));
        while(M--)
        {
            int a,b;
            cin>>a>>b;
            mix(a, b);
        }
        int cnt=0;
        for(int i=1;i<=N;i++)
        {
            if(!vis[find(i)])
            {
                cnt++;
                vis[find(i)] = 1;
            }
        }
        cout << cnt<<endl;
    }
}