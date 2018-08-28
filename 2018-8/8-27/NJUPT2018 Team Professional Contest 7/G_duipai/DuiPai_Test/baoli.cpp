#include<cstdio>
#include<cstring>
using namespace std;

#define LL long long
#define MAXN 1000005
inline bool scan_d(LL &num)
{
	char in; bool IsN = false;
	in = getchar();
	if (in == EOF) return false;
	while (in != '-' && (in<'0' || in>'9')) in = getchar();
	if (in == '-') { IsN = true; num = 0; }
	else num = in - '0';
	while (in = getchar(), in >= '0'&&in <= '9') {
		num *= 10, num += in - '0';
	}
	if (IsN) num = -num;
	return true;
}

LL a[MAXN];
LL vis[MAXN];
LL N;

LL ans;

void find(LL be)
{
	LL sum = a[be];
	LL index = be;

	while (sum < 0 && ans>0)
	{
		if (!vis[index])
			ans--;
		vis[be] = 1;

		index--;
		if (index < 0)index = N - 1;
		sum += a[index];
	}
}

int main()
{


	while (scan_d(N)&& N)
	{
	
		for (LL i = 0; i < N; i++)
            scan_d(a[i]);

        int ans=0;
        for(int i=0;i<N;i++)
        {
            int sum=0;
            for(int j=0;j<N;j++)
            {
                int tmp = (i + j)%N;

                sum+=a[tmp];
                if(sum<0)
                {
                    break;
                }
            }
            if(sum>=0)
                ans++;
        }
        printf("%d\n", ans);
    }

	return 0;
}