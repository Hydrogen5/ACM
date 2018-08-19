//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<ctime>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))

stringstream ss;

int main( int argc, char *argv[] )
{ 
    int seed=time(NULL);
    if(argc > 1)//如果有参数
    {
        ss.clear();
        ss<<argv[1];
        ss>>seed;//把参数转换成整数赋值给seed
    }
    srand(seed);
    //以上为随机数初始化，请勿修改
    //random(a,b)生成[a,b]的随机整数

    //以下写你自己的数据生成代码 
    int Z;
    Z=random(1,40);
    printf("%d\n",Z);
    while(Z--)
    {
        int n,m;
        n = random(1, 1000);
        m=random(1,1000);
        printf("%d %d\n", n, m);
        printf("0");
        for(int i=2;i<=m;i++)
        {
            int k=random(1,2);
            if(k==1)
                printf(" 0");
            else
            {
                int k=random(1,n);
                printf(" %d", k);
            }
        }
        printf("\n");
    }
}