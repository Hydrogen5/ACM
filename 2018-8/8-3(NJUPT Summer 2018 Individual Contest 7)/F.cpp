//MUH and Cube Walls
#include <iostream>
using namespace std;
int a[200010],b[200010];
int Next[200010];
int sa, sb;
void getNext()
{
    Next[0]=0;
    Next[1]=0;
    for(int i = 1; i < sb;i++)
    {
        int j = Next[i];
        while(j&&b[i]!=b[j])
            j = Next[j];
        Next[i + 1] = b[i] == b[j] ? j + 1 : 0;
    }
}
int main()
{
    int n,w;
    cin>>n>>w;
    sa = n - 1;
    sb = w - 1;
    int x,y;
    cin >> x;
    for (int i = 0; i < sa;i++)
    {
        cin>>y;
        a[i]=y-x;
        x = y;
    }
    cin >> x;
    for (int i = 0; i < sb;i++)
    {
        cin>>y;
        b[i]=y-x;
        x = y;
    }
    getNext();
    if(n==1) 
    {
        if(w==1)
            cout<<1<<endl;
        else
            cout << 0 << endl;
    }
    else if(w==1)
        cout << n << endl;
    else
    {
        int ans = 0, j = 0;
        for(int i=0;i<sa;i++)
        {
            while(j&&a[i]!=b[j])
                j = Next[j];
            if(a[i]==b[j])
                j++;
            if(j==sb)
            { 
            ans++;
            j = Next[j];
            }
        }
        cout << ans << endl;
    }
}