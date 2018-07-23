//Triangle Partition
//这算啥？思维？几何？
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct point{
    int x;
    int y;
    int pos;
}p[30010];

int cmp(point a , point b)
{
    if(a.x<b.x) return 1;
    else if(a.x==b.x) return a.y<b.y;
    else return 0;
}

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i = 0; i < 3*n; i++)
        {
            cin>>p[i].x>>p[i].y;
            p[i].pos = i;
        }
        sort(p, p+3*n, cmp);
        for(int i = 0; i < 3*n; i++)
        {
            cout<<p[i].pos+1;
            if((i+1)%3==0&&i!=3*n-1) cout<<endl;
            else cout<<" ";
        }
    }
    return 0;
} 