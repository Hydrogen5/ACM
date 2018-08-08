#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


//head

double a[MAXN];

void debug()

{

	for(int i=1;i<=10;i++)

	printf("%lf\n",a[i]);

}

void db()

{

	a[0]=log10(1);

	for(int i=1;i<=1000000;i++)

	a[i]=a[i-1]+log10(i);

	//debug();

}

int main()

{

	db();

    int t,i,j;

    int n,k;

    int cas=0;

    scanf("%d",&t);

    while(t--)

    {

    	scanf("%d%d",&n,&k);

    	printf("Case %d: ",++cas);

    	if(n==0)

    	{

    		printf("1\n");

    		continue;

		}

    	double ans;

    	ans=ceil(a[n]/log10(k*1.0));

		printf("%d\n",(int)ans);

    }

    return 0;

}
