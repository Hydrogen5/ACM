#include <iostream>
#define MOD 10000
using namespace std;
int a[1000000];
int main()
{
    a[0] = 0;
    a[1] = 1;
    int n;
    for (int i = 2; i < 900000; i++)
        a[i] = (a[i - 1] + a[i - 2]) % MOD;
    while (scanf("%d", &n) && n != -1)
        printf("%d\n", a[n]);
    return 0;

}