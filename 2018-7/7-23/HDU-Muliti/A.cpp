//Maximum Multiple
//Given an integer n, Chiaki would like to find three positive integers x, y and z such that: n=x+y+z, x∣n, y∣n
//, z∣n and xyz is maximum.
//B17041420
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int judge(int n)
{
    do
    {
        if((n&1)==0) return 0;
        n=n>>1;
    }while(n);
    return 1;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d",&n);
        if(n<3) {cout<<-1<<endl;continue;}
        int tmp=n/3;
        if(n%3==0)
        {
            int k=tmp|n;
            if(!judge(k)) {cout<<-1<<endl;continue;}
            else {cout<<tmp*tmp*tmp<<endl;continue;}
        }
        if(n%3==1)
        {
            int k=tmp|n;
            int k2=(tmp+1)|n;
            if(!judge(k)||!judge(k2)) {cout<<-1<<endl;continue;}
            else {cout<<tmp*(tmp+1)*tmp<<endl;continue;}
        }
        if(n%3==2)
        {
            int k=tmp|n;
            int k2=(tmp+1)|n;
            if(!judge(k)||!judge(k2)) {cout<<-1<<endl;continue;}
            else {cout<<tmp*(tmp+1)*(tmp+1)<<endl;continue;}
        }
    }
}