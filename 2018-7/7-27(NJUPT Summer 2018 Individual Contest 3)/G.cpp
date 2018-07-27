//Okabe and Boxes
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;
    int num=1;
    int ans = 0;
    int n;
    cin>>n;
    char str[100];
    for (int i = 0; i < 2 * n;i++)
    {
        cin>>str;
        if(str[0]=='a')
        {
            int x;
            cin>>x;
            s.push(x);
        }
        else
        {
            if(s.empty()) 
            {
                num++;
                continue;
            }
            if(s.top()==num) 
            {
                s.pop();
                num++;
            }
            else
            {
                while(!s.empty()) s.pop();
                ans++;
                num++;
            }
        }
    }
    cout << ans << endl;
}
