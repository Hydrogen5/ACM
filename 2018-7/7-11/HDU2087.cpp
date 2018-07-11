//剪花布条 
//KMP模板
#include <iostream>
#include<cstring>
using namespace std;
char a[1010],b[1010];
int sa,sb;
int Next[1010];
void getNext()
{
    Next[0]=0;
    Next[1]=0;
    for(int i = 1; i < sb;i++)
    {
        int j = Next[i];
        while(j&&b[i]!=b[j])
            j = Next[j];
        Next[i + 1] = b[i] == b[j] ? j + 1 : 0;
    }
}
int main()
{
    while(cin>>a)
    {
        if(a[0]=='#')
            break;
        cin >> b;
        sa=strlen(a);
        sb=strlen(b);
        getNext();
        int j = 0, ans = 0;
        for (int i = 0; i < sa;i++)
        {
            while(j&&a[i]!=b[j])
                j = Next[j];
            if(a[i]==b[j])
                j++;
            if(j==sb)
            {
                ans++;
                j = 0;
            }
        }
        cout << ans << endl;
    }
}