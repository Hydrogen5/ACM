//Euler Function
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define Max 1000005
int main()
{
    int n;
    cin>>n; 
    while(n--)
    {
        int temp;
        scanf("%d", &temp);
        if(temp == 1)
            cout<<5<<endl;
        if(temp >= 2)
            cout<<5+temp<<endl;
    }
    return 0;
}