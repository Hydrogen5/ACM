//Oulipo 
//KMP
#include<iostream>
#include<cstring>
using namespace std;
char a[1000010], b[10010];
int sa, sb;
int Next[10010];
void getNext()
{
    Next[0] = 0;
    Next[1] = 0;
    for (int i = 1; i < sb;i++)
    {
        int j = Next[i];
        while(j&&b[i]!=b[j])
            j = Next[j];
        Next[i + 1] = b[i] == b[j] ? j + 1 : 0;
    }
}
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        cin>>b>>a;
        sa = strlen(a);
        sb = strlen(b);
        getNext();
        int ans = 0, j = 0;
        for(int i=0;i<sa;i++)
        {
            while(j&&a[i]!=b[j])
                j = Next[j];
            if(a[i]==b[j])
                j++;
            if(j==sb)
               { 
                   ans++;
                   j = Next[j];
               }
        }
        cout << ans << endl;
    }
}