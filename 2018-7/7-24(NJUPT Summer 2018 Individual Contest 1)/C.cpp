//Curriculum Vitae 
#include <iostream>
#include <cstring>
using namespace std;
int ans[10000];
int s[10000];
int main()
{
    int n;
    cin>>n;
    for (int i = 0; i <n; i++)
        cin >> s[i];
    ans[0] = s[0];
    int len = 1;
    for(int i=1 ; i<n ; i++) 
    {
        if(s[i] >= ans[len-1]) ans[len++] = s[i];
        else 
        {
            int tmp = 0;
            for (int j = 0; j < len;j++)
            if(ans[j]>s[i]) 
            {
                tmp = j;
                break;
            }
            ans[tmp] = s[i];
        }
    }
    cout << len<<endl;
}