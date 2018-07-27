//Two Buttons
#include <iostream>
#include <queue>
using namespace std;
int n, m;

struct node
{
    int step, val;
}a,b,c;
int vis[20005]={0};
queue<node> q;
int main()
{

    cin >> n >> m;
    if (m <= n)
    {
        cout << n - m << endl;
        return 0;
        }
        a.step=0;
        a.val = n;
        q.push(a);

        int ans = 0;
        while (!q.empty()) {

            a = q.front();
            q.pop();

            if(a.val == m){
                ans = a.step;
                break;
            }

            if(a.val <= 0)
                continue;

            if (vis[a.val]) {
                continue;
            }

            if(a.val > m)
            {
                b.step=a.step+1;
                b.val = a.val - 1;
                q.push(b);
                continue;
            }

            vis[a.val] = 1;

            b.step=a.step+1;
            b.val = a.val*2;
            c.step=a.step+1;
            c.val = a.val - 1;
            q.push(node(b));
            q.push(node(c));
        }

        cout<<ans<<endl;
}