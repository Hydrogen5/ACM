#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL unsigned long long
string a;
LL p[3];
LL n[3];
LL need[3];
LL ans;
LL r;

int main()
{
	LL T;
	cin >> T;
	while (T--)
	{
		ans = 0;
		cin >> a;
		memset(need, 0, sizeof(need));
		for (LL i = 0; i < a.size(); i++)
		{
			switch (a[i])
			{
			case 'B':need[0]++; break;
			case 'M':need[1]++; break;
			case 'C':need[2]++; break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			cin >> n[i];
		}
		for (int i = 0; i < 3; i++)
		{
			cin >> p[i];
		}
		cin >> r;

		LL t[3];
		for (int i = 0; i < 3; i++)
		{
			if (need[i] == 0 || n[i] == 0)
			{
				t[i] = 0xfffffff3;
			}
			else
			{
				t[i] = n[i] / need[i];
			}
		}
		LL temp;
		temp = min(t[0], min(t[1], t[2]));
		if (temp != 0xfffffff3)
		{
			ans += temp;
			for (int i = 0; i < 3; i++)
			{
				n[i] -= (temp*need[i]);
			}
		}

		while (r > 0 && (!((!n[0]) && (!n[1]) && (!n[2]))))
		{
			for (int i = 0; i < 3; i++)
			{
				if (need[i] > n[i])
				{
					t[i] = need[i] - n[i];
				}
				else
				{
					t[i] = 0;
				}
			}

			if (r >= t[0] * p[0] + t[1] * p[1] + t[2] * p[2])
			{
				r -= t[0] * p[0] + t[1] * p[1] + t[2] * p[2];
				for (int i = 0; i < 3; i++)
				{
					n[i] -= (need[i] - t[i]);
				}
				ans++;
			}
			else
			{
				break;
			}
		}
		ans += (r / (need[0] + need[1] + need[2]));

		cout << ans << endl;
	}

	return 0;
}
