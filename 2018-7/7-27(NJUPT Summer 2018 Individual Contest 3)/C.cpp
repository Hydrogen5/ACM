#include<iostream>
#include <vector>
using namespace std;
int cnt = 0;
int n, m;
struct node
{
    int has_cat;
    int falg=0;
    vector<int> a;
}t[1000010];
void dfs(int cur,int f)
{
    int k;
    if(t[cur].falg) return;
    if(t[cur].a.size()==1&&cur!=1) cnt++;
    for(int i=0;i<t[cur].a.size();i++)
    {
        k = t[cur].a[i];
        t[cur].falg = 1;
        if(t[k].has_cat&&f+1>m) continue;
        if(t[k].has_cat)
            dfs(k,f+1);
        else
            dfs(k,0);
        t[cur].falg = 0;
    }
}
int main()
{
    cin >> n >> m;
    cnt = 0;
    for (int i = 1; i <= n; i++)
        cin >> t[i].has_cat;
    for (int i = 1; i < n ; i++)
    {
        int j, k;
        cin >> j >> k;
        t[j].a.push_back(k);
        t[k].a.push_back(j);
    }
    dfs(1,t[1].has_cat);
    cout<<cnt<<endl;
    return 0;

}