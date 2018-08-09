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
    int T=random(1,10);
    printf("%d\n",T);
    while(T--)
    {
        int s=random(10,99);
        for (int i = 1;i<=s;i++)
        {
            int tmp = random(1, 3);
            if(tmp==1) printf("B");
            if(tmp==2) printf("C");
            if(tmp==3) printf("M");
        }
        printf("\n");
        int nb,nc,nm;
        nb = random(1, 100);
        nc = random(1, 100);
        nm = random(1, 100);
        printf("%d %d %d\n", nb, nc, nm);
        nb = random(1, 100);
        nc = random(1, 100);
        nm = random(1, 100);
        printf("%d %d %d\n", nb, nc, nm);
        int r = random(1, 1000000000000);
        printf("%lld\n", r);
    }
    
    return 0;
}