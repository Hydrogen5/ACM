#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
int main()
{
    int t,p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&p);
        int sum=0;
        float temp=sqrt(p-1);
        for(int i=1;i<=temp;i++)
            if((p-1)%i==0)
            {
                sum++;
                sum+=(i!=temp);
            }
        printf("%d\n",sum);
    }
}