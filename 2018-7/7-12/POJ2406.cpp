//Power Strings 
//还是他妈的KMP找循环节
#include<iostream>
#include<cstring>
using namespace std;
char a[1000010];
int Next[1000010];
int len;
void getNext()
{
    Next[0]=0;
    Next[1]=0;
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
    while(cin>>a&&a[0]!='.')
    {
        len=strlen(a);
        getNext();
        if(len%(len-Next[len])==0)
            cout << len/(len - Next[len]) << endl;
        else
            cout << 1 << endl;
    }
}