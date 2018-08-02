//How Many Answers Are Wrong
#include <iostream>
using namespace std;
int pre[200010];
int ranks[200020];
int ans = 0;
int find(int x)
{
    if (x == pre[x])
		return x;
	int t = pre[x];
	pre[x] = find(pre[x]);
	ranks[x] += ranks[t];       
	return pre[x];
}
void mix(int x,int y,int s)
{
    int px = find(x);
    int py = find(y);
    if(px==py)
    {
        if(ranks[y]!=ranks[x]+s) ans++;
    }
    else
    {
        pre[py] = px;
        ranks[py] = ranks[x] + s - ranks[y];
    }
}
int main()
{
    int N,M;
    while(cin >> N >> M)
    {
        for (int i = 0; i <= N;i++) 
        {
            pre[i] = i;
            ranks[i] = 0;
        }
        ans = 0;
        while(M--)
        {
            int a,b,s;
            cin >> a >> b >> s;
            mix(a, b+1, s);
        }
        cout << ans << endl;
    }
}