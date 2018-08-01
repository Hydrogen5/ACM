//Sudoku 
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int sudoku[10][10];
int row[10];
int col[10];
int squ[10];
int cnt[512];
int num[512];
void init()
{
    memset(sudoku, 0, sizeof(sudoku));
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    memset(squ, 0, sizeof(squ));
}
int g(int x,int y)
{
    return x / 3 * 3 + y / 3;
}
void flip(int x,int y,int z)
{
    row[x]^=(1<<z);
    col[y]^=(1<<z);
    squ[g(x, y)] ^= (1 << z);
}
int dfs(int now)
{
    if(now==0)
        return 1;
    int temp=10;
    int x;
    int y;
    for (int i = 0; i < 9;i++)
        for (int j = 0; j < 9;j++)
        {
            if(sudoku[i][j])
                continue;
            int val = row[i] & col[j] & squ[g(i, j)];
            if(!val)
                return 0;
            if(cnt[val]<temp)
            {
                temp=cnt[val];
                x = i;
                y = j;
            }
        }
        int val=row[x] & col[y] & squ[g(x, y)];
        for (; val;val-=val&-val)
        {
            int z = num[val & -val];
            flip(x,y,z);
            if(dfs(now-1))
                return 1;
            flip(x, y, z);
        }
        return 0;
}
int main()
{
    for (int i = 0; i < 1 << 9; i++)
		for (int j = i; j; j -= j&-j) 
			cnt[i]++;
	for (int i = 0; i < 9; i++)
		num[1 << i] = i;
    int n;
    cin>>n;
    while(n--)
    {
        init();
        char a[15];
        for(int i=0;i<9;i++)
        {
            cin >> a;
            for (int j = 0; j < 9;j++)
                sudoku[i][j] = a[j] - '0';
        }
        int tot = 0;
        for (int i = 0; i < 9;i++)
        {    
            for (int j = 0; j < 9;j++)
            {
                if(!sudoku[i][j])
                    tot++;
                else
                    flip(i, j, sudoku[i][j]);
            }
        }
        dfs(tot);
        for (int i = 0; i < 9;i++)
        {
            for (int j = 0; j < 9;j++)
                cout << sudoku[i][j];
            cout << endl;
        }
    }
}