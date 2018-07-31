//Bus of Characters 
#include <iostream>
#include <algorithm>
#include <stack>
#define ll long long
using namespace std;
struct node{
    ll wid;
    int code;
} a[200020];
stack<int> S;
char s[400040];
int cmp(node a,node b)
{
    return a.wid < b.wid;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i].code = i;
        cin >> a[i].wid;
    }
    sort(a + 1, a + 1 + n,cmp);
    cin >> s;
    int cnt=1;
    for(int i=0;i<2*n;i++)
    {
        if(s[i]=='0')
        {
            cout<<a[cnt].code<<" ";
            S.push(a[cnt].code);    
            cnt++;
        }
        if(s[i]=='1')
        {
            cout<<S.top()<<" ";
            S.pop();
        }
    }
}