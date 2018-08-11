#include<bits/stdc++.h>
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
    int N,Q;
    N=random(1,50);
    Q=random(1,50);
    printf("%d %d\n",N,Q);
    for(int i=1;i<N;i++)
    {
        long long x = random(1, 100);
        printf("%lld ", x);
    }
    printf("%lld\n", random(1, 100));
    while(Q--)
    {
        if(random(1,2)==1)
        {
            printf("Q ");
            int l = random(1, N);
            int r = random(l, N);
            printf("%d %d\n", l, r);
        }
        else
        {
            printf("C ");
            int l = random(1, N);
            int r = random(l, N);
            int d = random(-100, 100);
            printf("%d %d %d\n", l, r,d);
        }
    }
}