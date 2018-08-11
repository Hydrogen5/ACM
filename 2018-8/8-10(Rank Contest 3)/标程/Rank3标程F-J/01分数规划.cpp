#include <algorithm>
#include  <iostream>
#include   <cstdlib>
#include   <cstring>
#include    <cstdio>
#include    <string>
#include    <vector>
#include     <stack>
#include     <cmath>
#include       <map>
using namespace std;
#define LL			    long long
#define MOD 		    1000000007
#define mod(x)		    (x%MOD)
#define CLR(a,x)        memset(a,x,sizeof(a))
#define FILL(a,n,x)     fill(a,a+n,x)
#define INF 		    0x3fffffff
#define pb 		        push_back
#define WHILE() 	    int T;scanf( "%d", &T );while( T-- )
#define rep( i, l, r ) 	for( int i = l; i <= r; ++i )

int n, k;
const int N = 1000+7;
int A[N], B[N];
int del[N];
int sumA, sumB;
double ans;

void dfs( int index, int cnt ) {
    del[cnt] = index;
    if( cnt == k ) {
        int _sumA = sumA, _sumB = sumB;
        rep( i, 1, cnt ) {
            _sumA -= A[del[i]];
            _sumB -= B[del[i]];
        }
        ans = max( ans, 100.0*_sumA/_sumB );
        return;
    }
    rep( i, index+1, n ) {
        dfs( i, cnt+1 );
    }
}

int main() {
    // 注意：加速cin、cout后不能同时使用cout、printf输出，cin、scanf同理
	ios::sync_with_stdio(false);// 用于加速cin、cout
	cin.tie(0);
    // freopen( ".txt", "r", stdin );
    while( scanf( "%d%d", &n, &k ), !( n == 0 && k == 0 ) ) {
        sumA = sumB = 0;
        rep( i, 1, n ) {
            scanf( "%d", A+i );
            sumA += A[i];
        }
        rep( i, 1, n ) {
            scanf( "%d", B+i );
            sumB += B[i];
        }
        ans = -1;
        rep( i, 1, n ) {
            dfs( i, 1 );
        }
        printf( "%.0f\n", ans );
    }


    return 0;
}
