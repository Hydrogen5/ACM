//Xor-Paths
#include <iostream>
#include <cmath>
#include <map>
using namespace std;
int n,m;
long long k;
long long cnt=0;
long long cell[100][100];
map<long long,long long>mid[500];
void dfs(int x,int y,long long cur)
{
    if(x+y==(n+m+2)/2)
    {
        mid[x][cur]++;
        return;
    }
    if(x<n)
        dfs(x + 1, y, cur ^ cell[x+1][y]);
    if (y < m)
        dfs(x, y + 1, cur ^ cell[x][y+1]);
}
void sfd(int x,int y,long long cur)
{
   if(x+y==(n+m+2)/2)
    {
        cnt += mid[x][cur ^ k^cell[x][y]];
        return;
    }
    if(x>1)
        sfd(x-1, y, cur ^ cell[x-1][y]);
    if (y>1)
        sfd(x, y-1, cur ^ cell[x][y-1]);
}
int main()
{
    cin>>n>>m>>k;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++)
            cin>>cell[i][j];
    dfs(1, 1, cell[1][1]);
    sfd(n, m, cell[n][m]);
    cout << cnt << endl;
}