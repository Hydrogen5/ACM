//Cyclic Nacklace 
//KMP找循环节，谜一样的cin与scanf(line.27)
#include<iostream>
#include<cstring>
using namespace std;
char a[100010];
int Next[100010];
int len;
void getNext()
{
    Next[0]=0;
    Next[1]=0;
    for (int i = 1; i < len;i++)
    {
        int j = Next[i];
        while(j&&a[i]!=a[i])
            j = Next[j];
        Next[i + 1] = a[i] == a[j] ? j + 1 : 0;
    }
}
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        scanf("%s", a);
        len=strlen(a);
        getNext();
        int tmp=len-Next[len];
        if(len==tmp)
            cout << len << endl;
        else
        {
            if(len%tmp)
                cout << tmp - len % tmp << endl;
            else
            {
                cout << 0 << endl;
            }
        }
    }
}