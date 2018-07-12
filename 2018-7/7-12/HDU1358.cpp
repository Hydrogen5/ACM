//Period 
//KMP找循环节
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char a[1000010];
int Next[1000010];
int len;
void getNext()
{
    Next[0] = 0;
    Next[1] = 0;
    for (int i = 1; i < len; i++)
    {
        int j=Next[i];
        while(j&&a[i]!=a[j])
            j = Next[j];
        Next[i + 1] = a[i] == a[j] ? j + 1 : 0;
    }
}
int main()
{
    int cnt = 1;
    while(cin>>len&&len!=0)
    {
        scanf("%s",a);
        cout << "Test case #" << cnt++ << endl;
        getNext();
        for (int i = 1; i <= len; i++)
        {
            int tmp = i - Next[i];
            if(Next[i]&&!(i%tmp))
            {
                cout << i << " " << i / tmp << endl;
            }
        }
        cout << endl;
    }
}