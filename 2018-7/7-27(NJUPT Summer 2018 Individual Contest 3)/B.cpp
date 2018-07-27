//Christmas Spruce
#include <iostream>
#include <vector>
using namespace std;
struct node{
    int next[1000];
    int is_leaf=1;
    int cnt=0;
} od[1010];
int main()
{
    int n;
    cin>>n;
    for (int i = 2; i <= n;i++)
    {
        int num;
        cin>>num;
        od[num].is_leaf = 0;
        od[num].next[od[num].cnt++] = i;
    }
    for(int i=1;i<=n;i++)
    {
        if(od[i].is_leaf)
            continue;
        int cnt=0;
        for(int j=0;j<od[i].cnt;j++)
        {
            if(od[od[i].next[j]].is_leaf)
                cnt++;
        }
        if(cnt<3)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}