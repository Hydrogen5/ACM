//Painter's Problem
#include <iostream>
using namespace std;
char x[25][25],pt[25][25];
int p[25][25],cg[25][25];
int n;
void init()
{
     for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            pt[i][j] = p[i][j];
    
}
void chg(int x,int y)
{
    pt[x][y] ^= 1;
    pt[x - 1][y] ^= 1;
    pt[x + 1][y] ^= 1;
    pt[x][y - 1] ^= 1;
    pt[x][y + 1] ^= 1;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin >> n;
        for(int i=0;i<n;i++)
            cin >> x[i];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                p[i+1][j+1] = x[i][j] == 'y' ? 1 : 0;
        int Min = n * n+1;
        for (int k = 0;k<(2<<n);k++)
        {
            int sum = 0;
            init();
            for(int i=1;i<=n;i++)
            {
                cg[1][i] = (k >> (i-1)) & 1;
                if(cg[1][i])
                {
                    chg(1, i);
                    sum++;
                }
            }
            for(int i = 2; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    if(!pt[i - 1][j])
                    {
                        cg[i][j] = 1;
                        sum++;
                        chg(i, j);
                    }
            int mark = 0;
            for(int j = 1; j <= n; j++)
                if(!pt[n][j]) mark = 1;
            if(!mark && sum < Min) Min = sum;
        }
        if(Min != n*n + 1)
            cout << Min << endl;
        else cout<<"inf\n";

    }
}