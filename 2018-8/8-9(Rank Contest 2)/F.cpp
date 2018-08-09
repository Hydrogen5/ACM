#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
priority_queue <int,vector<int>,greater<int> > que;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        que.push(a);
    }
    int ans = 0;
    for(int i=1;i<=n-1;i++)
    {
        int a=que.top();
        que.pop();
        int b=que.top();
        que.pop();
        ans+=(a+b);
        que.push(a + b);
    }
    printf("%d\n", ans);
}
