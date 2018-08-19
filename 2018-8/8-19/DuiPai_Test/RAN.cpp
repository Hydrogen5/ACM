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
    while(Z--)
    {
        int k = random(15, 19);
        while(k--)
        {
            char a;
            a = random('a', 'd');
            printf("%c", a);
        }
        printf("\n");
    }
}