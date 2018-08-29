#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100005
#define UINT unsigned int

struct ADD
{
	int id;
	UINT mask;
	UINT bit;
}add[MAXN];


int main()
{
	// freopen("d.in", "r", stdin);
	UINT N, M;
	scanf("%u%u", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%x%u", &add[i].mask, &add[i].bit);
		add[i].bit = 32u - add[i].bit;
		add[i].id = i;
	}
	sort(add, add + N, [](ADD a, ADD b) {return a.bit > b.bit; });
	for (UINT i = 0; i < M; i++)
	{
		UINT temp;
		int ans;
		ans = -1;
		scanf("%x", &temp);
		for (UINT i = N - 1; i >= 0; i--)
		{
			if (add[i].bit == 32)
			{
				ans = add[i].id;
				break;
			}
			if (!((temp >> add[i].bit) ^ (add[i].mask >> add[i].bit)))
			{
				ans = add[i].id;
				break;
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}