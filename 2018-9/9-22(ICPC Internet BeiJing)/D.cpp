#include <cstring>
#include <iostream>
using namespace std;

#define LL long long
#define MAX 1000005
LL N, C;
LL sum;
LL a[MAX];
bool vis[MAX];
LL S;
void init()
{
    memset(vis, false, sizeof(vis));
    sum = 0;
    S = 0;
}

bool f(int s)
{
    vis[s] = true;
	int pnow;
	int num;
	num = a[s];
	pnow = s - 1;
	
	if (pnow < 0)pnow = N - 1;
	while (num < 0)
	{
		if (sum == N)return false;
		if (!vis[pnow]) 
		{
			vis[pnow] = true;
			sum++;
		}
		num += a[pnow];
		pnow--;
		if (pnow < 0)pnow = N - 1;
	}
	return true;
}

int main()
{
    LL T;
    cin >> T;
    while (T--)
    {
        cin >> N >> C;
        init();
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
            S += a[i];
            a[i] += C;
        }
        for (int i = 0; i < N; i++)
        {
            LL temp;
            cin >> temp;
            S -= temp;
            a[i] -= temp;
        }
        S += C;
        if (S < 0)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = N - 1; i >= 0; i--)
        {
            if ((!vis[i]) && a[i] < 0)
            {
                f(i);
            }
        }
        int flag = 1;
        for (int i = 0; i < N; i++)
        {

            if (!vis[i])
            {
                cout << i + 1 << endl;
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            continue;
        cout << -1 << endl;
    }
    return 0;
}
