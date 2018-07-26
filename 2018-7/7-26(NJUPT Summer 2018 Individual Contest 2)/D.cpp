//Romaji
#include <iostream>
#include <cstring>
using namespace std;
char s[100000];
int main()
{
    cin>>s;
    int len=strlen(s);
    for (int i = 0; i < len;i++)
    {
        if(!(s[i]=='a'||s[i]=='o'||s[i]=='u'||s[i]=='i'||s[i]=='e'||s[i]=='n'))
        {
            if(!(s[i+1]=='a'||s[i+1]=='o'||s[i+1]=='u'||s[i+1]=='i'||s[i+1]=='e'))
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
}