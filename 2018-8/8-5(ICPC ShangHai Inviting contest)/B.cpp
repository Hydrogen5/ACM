#include <iostream>
#include <cstdio>
using namespace std;
int a[100000];
int main()
{
    int T;
    scanf("%d",&T);
    for(int k=1;k<=T;k++)
    {
        int N;
        scanf("%d",&N);
        int sum=0;
        int cnt=0;
        for(int i=1;i<=N/2;i++)
        {
            if(N%i==0)
            {
                a[cnt++]=i;
                sum+=i;
            }   
        }   
        if(sum==N)
        {
            printf("Case %d: %d = %d",k,N,a[0]);
            for(int i=1;i<cnt;i++)
                printf(" + %d",a[i]);
            cout<<endl;
        }
        else
            printf("Case %d: Not perfect.\n",k);
             
    }   
}