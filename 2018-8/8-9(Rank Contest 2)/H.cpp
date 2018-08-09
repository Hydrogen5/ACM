#include<stdio.h>
#define N 15000
#define MOD 10000
int a[N];
int main(void)
{
    int i,n;
    a[0]=0;
    a[1]=1;
    for(i=2;i<N;i++)
        a[i]=(a[i-1]+a[i-2])%MOD;
    scanf("%d",&n);
    printf("%d\n", a[n % N]);
}