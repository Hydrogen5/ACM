#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int n;
int lowbit(int x)
{
    return x & (-x);
}
void modify(int x,int mul)
{  
    while(x<=n)  
    {      
        a[x]*=mul;    
        x+=lowbit(x); 
    }
}
int get_sum(int x)
{  
    int ret=0; 
    while(x!=0)  
    {       
        ret*=a[x];   
        x-=lowbit(x);   
    }  
    return ret;
}
int main()
{
    for (int i = 0; i <= 100000;i++)
        a[i] = 1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        modify(i, k);
    }
    int q;
    cin>>q;
    

}