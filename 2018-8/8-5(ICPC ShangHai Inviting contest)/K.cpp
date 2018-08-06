#include<iostream>
#include<cstring>
#include<cstdio>
 
 
using namespace std;
 
 
int T,m,n,x2,y2;
long long int a[110][110],b[110][110];
long long int c[110][110];
int main(){
    scanf("%d",&T);
    int  T1=T;
    while(T--){
        printf("Case %d:\n",T1-T);
        scanf("%d%d%d%d",&m,&n,&x2,&y2);
            for(int i=1;i<=m;i++)
                for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
            for(int i=1;i<=x2;i++)
                for(int j=1;j<=y2;j++) scanf("%lld",&b[i][j]);   
             
        if(x2==n) {    
            for(int i=1;i<=m;i++)   
                for(int j=1;j<=y2;j++) {
                    c[i][j]=0;
                    for(int k=1;k<=n;k++)
                        c[i][j]+=a[i][k]*b[k][j];
                }
            for(int i=1;i<=m;i++){
                printf("%lld",c[i][1]);
                for(int j=2;j<=y2;j++) printf(" %lld",c[i][j]);
                printf("\n");
            }           
        }
         else  printf("ERROR\n");           
    }
     
}