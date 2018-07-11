//找新朋友
//欧拉函数（eeeeeeeeeasy)
#include<iostream>
using namespace std;
int phi[50010] = {0};
void phitable()
{
    phi[1]=1;
    for(int i=2;i<=50000;i++)
    {
        if(!phi[i])
        {
            for(int j=i;j<=50000;j+=i)
            {
                if(!phi[j])
                    phi[j] = j;
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}
int main()
{
    phitable();
    int cn;
    cin>>cn;
    while(cn--)
    {
        int x;
        cin>>x;
        cout << phi[x]<<endl;
    }
    return 0;
}