#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define CLR(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
#define LL long long
int main()
{
	int dp[5011];
	char str[5011];
	scanf ("%s",str+1);
	str[0] = '@';
	int l = strlen(str);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2 ; i < l ; i++)
	{
		dp[i] = i + 1;
		for (int j = 1 ; j <= i ; j++)
		{
			bool flag = true;		//从j到i是否是回文串
			int st = j;
			int endd = i;
			while (endd >= st)
			{
				if (str[endd] != str[st])
				{
					flag = false;
					break;
				}
				endd--;
				st++;
			}
			if (flag)
				dp[i] = min (dp[i] , dp[j-1] + 1);
		}
	}
	printf ("%d\n",dp[l-1]);
	return 0;
}
