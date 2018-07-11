//Number Sequence
//KMP模板，eeeeeasy
#include<iostream>
using namespace std;
int sa,sb;
int a[1000010],b[10010];
int Next[10010];
void getNext()
{
    Next[1] = 0;
    Next[0] = 0;
    for (int i = 1; i < sb;i++)
    {
        int j=Next[i];
        while(j&&b[j]!=b[i])
            j = Next[j];
        Next[i + 1] = b[j] == b[i] ? j + 1 : 0;
    }
}
int main()
{
    int N;
    cin>>N;
    while(N--)
    {

        cin>>sa>>sb;
        for (int i = 0; i < sa;i++)
            cin >> a[i];
        for (int i = 0; i < sb;i++)
            cin >> b[i];
        getNext();
        int ans = -1, j = 0;
        for (int i = 0; i < sa;i++)
        {
            while(j&&a[i]!=b[j])
                j = Next[j];
            if(a[i]==b[j])
                j++;
            if(j==sb)
            {
                ans = i - sb + 2;
                break;
            }
        }
        cout << ans << endl;
    }
}