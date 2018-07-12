//Seek the Name, Seek the Fame
//KMP,既是前缀也是后缀
//从后往前，从len-Next[len]到len-1的作为后缀与前缀相同
#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
using namespace std;
char a[400010];
int Next[400010];
stack<int> ans;
int len;
void getNext()
{
    Next[0] = 0;
    Next[1] = 0;
    for(int i=1;i<len;i++)
    {
        int j=Next[i];
        while(j&&a[i]!=a[j])
            j = Next[j];
        Next[i + 1] = a[i] == a[j] ? j + 1 : 0;
    }
}
int main()
{
    while(cin>>a)
    {
        len=strlen(a);
        getNext();
        int j = Next[len-1];
        while(j)
        {
            ans.push(j+1);
            j = Next[j];
        }
        if(a[0]==a[len-1])
            cout << 1 << " ";
        while(!ans.empty()) 
        {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << len << endl;
    }
}