//Comparing answers
//傻逼题
//hash?还是算什么别的优化
//原先一次(n*n)x(n*n)矩阵乘法
//优化过后为三次(1*n)x(n*n)
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a1[1010][1010];
int a2[1010][1010];
int n;
int vec[1010];//压缩向量
int mid1[1010];//a1*vec压缩结果
int mid2[1010];//a2*vec压缩结果
int fin1[1010];//mid1*a1压缩结果
int check()
{
    for (int i = 1;i<=n;i++)
        vec[i] = 271931 % i;
    for (int i = 1; i <= n;i++)
        for (int j = 1;j<=n;j++)
            mid1[i] += vec[j] * a1[j][i];
    for (int i = 1; i <= n;i++)
        for (int j = 1;j<=n;j++)
            mid2[i] += vec[j] * a2[j][i];
    for (int i = 1; i <= n;i++)
        for (int j = 1;j<=n;j++)
            fin1[i] += mid1[j] * a1[j][i];
    for (int i = 1; i <= n;i++)
       if(fin1[i]!=mid2[i])
           return 0;
    return 1;
}

int main()
{
    while(cin>>n&&n!=0)
    {
        for(int i=1;i<=n;i++)
            for (int j = 1; j <= n;j++)
                scanf("%d", &a1[i][j]);
        for(int i=1;i<=n;i++)
            for (int j = 1; j <= n;j++)
                scanf("%d", &a2[i][j]);        
        int flag = check();
        if(flag) puts("YES");
        else
            puts("NO");

    }
}