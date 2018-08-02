//How Many Answers Are Wrong
#include <iostream>
using namespace std;
int pre[200010];
int sum[200020];
int ans = 0;
int find(int x)
{
    if(pre[x]!=x)
    {
        sum[x] += sum[pre[x]];
        pre[x] = find(pre[x]);
    }
    return pre[x];
}
void mix(int x,int y,int s)
{
    int px = pre[x];
    int py = pre[y];
    if(px==py)
    {
        if(sum[y]!=sum[x]+s) ans++;
    }
    else
    {
        pre[py] = px;
        sum[py] = sum[x] + s - sum[y];
    }
}
int main()
{
    int N,M;
    cin >> N >> M;
    for (int i = 1; i <= N;i++) 
    {
        pre[i] = i;
        sum[i] = 0;
    }
    while(M--)
    {
        int a,b,s;
        cin >> a >> b >> s;
        mix(a, b, s);
    }
    cout << ans << endl;
}