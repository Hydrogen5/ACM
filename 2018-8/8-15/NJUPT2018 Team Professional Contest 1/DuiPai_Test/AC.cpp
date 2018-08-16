#include <cstring>
#include <string> 
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

long long int i, z, n, m, o, t[1000005], zero[1000005];

int main()
{
	scanf("%lld", &z);
	while (z--)
	{
		o = 1;
		t[0] = 0;
		memset(zero, 0, sizeof(zero));
		scanf("%lld%lld", &n, &m);
		for (int i = 1; i <= m; i++)
		{
			scanf("%lld", &t[i]);
			if (t[i] == 0)
			{
				zero[o] = i;
				o++;
			}
		}
		for (i = 1; i <= m; i++)
		{
			if (t[i])
			{
				for (int k = i - 1; k >= 0; k--)
				{
					if (t[k] == t[i] || k == 0)
					{
						int p;
						for (p = k + 1; p<i; p++)
						{
							if (t[p] == 0)
							{
								t[p] = t[i];
								break;
							}
						}
						if (p == i)
						{
							printf("NO\n");
							i = m + 1;
						}
						break;
					}
				}
			}
		}
		if (i == m + 1)
		{
			printf("YES\n");
			for (int w = 1; w<o; w++)
			{
				printf("%lld ", t[zero[w]]);
			}
			printf("\n");
		}
	}
	return 0;
}
