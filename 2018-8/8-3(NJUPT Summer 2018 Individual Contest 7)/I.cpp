//Dima and Text Messages 
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
char sec[100010];
int main()
{
    int m;
    cin >> m;
    string str="<3";
    while(m--)
    {
        string x;
        cin>>x;
        str += x;
        str += "<3";
    }
    cin>>sec;
    int cur=0;
    for (int i = 0; i < strlen(sec);i++)
    {
        if(sec[i]==str[cur])
            cur++;
        if(cur==str.length())
            break;
    }
    if(cur==str.length())
        cout << "yes\n";
    else
        cout << "no\n";
}