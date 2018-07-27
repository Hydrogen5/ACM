//Useful Decomposition
#include <iostream>
using namespace std;
int m[1000000]={0};
int leaves[1000000] = {0};
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        m[x]++;
        m[y]++;
    }
    int cnt = 0;
    int root = 0;
    int tmp = 0;
    for (int i = 1;i<=n;i++)
    {
        if(m[i]>=3)
        {
            cnt++;
            root = i;
        }
        if(m[i]==1)
        {
            leaves[tmp++] = i;
        }
        
    }
    if(cnt>=2)
    {
        cout << "No\n";
        return 0;
    }
    cout<<"Yes\n";
    if (root == 0)
        cout<<1<<endl<<leaves[0]<<" "<<leaves[1]<<endl;
    else
    {
        cout<<tmp<<endl;
        for(int i=0; i<tmp; i++)

                cout<<root<<" "<<leaves[i]<<endl;
    }
}   