//The Suspects
#include <iostream>
using namespace std;
int fat[30010];
int find(int x)
{
    if(fat[x]!=x)
        fat[x] = find(fat[x]);
    return fat[x];
}
void mix(int a,int b)
{
    int pa=find(a);
    int pb=find(b);
    if(pa!=pb)
        fat[pb] = pa;
}
int main()
{
    int n,m;
    while(cin>>n>>m&&(n||m))
    {
        for(int i=0;i<n;i++)
            fat[i] = i;
        while(m--)
        {
            int x;
            cin>>x;
            if(x>0)
            {
                int a;
                cin >> a;
                for (int i = 1; i < x; i++)
                {
                    int b;
                    cin >> b;
                    mix(a, b);
                }
            }
        }
        int cnt=0;
        for (int i = 0;i<n;i++)
            if(find(i)==fat[0])
                cnt++;
        cout << cnt << endl;
    }
}