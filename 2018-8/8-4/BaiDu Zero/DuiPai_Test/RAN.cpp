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
        int n=random(1,100);
        int q=random(1,100);
        printf("%d %d\n",n,q);
        for(int i=0 ; i<n ; ++i)
        {
            printf("%c",random('A','Z'));
        }
        printf("\n");
        for(int i=0;i<q;i++)
        {
            int l=random(1,n-1);
            int r = random(l + 1, n);
            printf("%d %d\n", l, r);
        }
    }
    return 0;
}