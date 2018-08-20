//English Sentence 
#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;
string s[1010];
map<string, int> cnts;
map<string, int> len;
int main() 
{
    int cnt=0;
    while(cin>>s[++cnt])
    {
        if(cnts.count(s[cnt])==0)
            cnts[s[cnt]]=0;
        cnts[s[cnt]]++;
        len[s[cnt]] = s[cnt].length();
    }
    int a=0, b=0;
    for(int i=1;i<=cnt;i++)
    {
        if(cnts[s[i]]>cnts[s[a]]) a=i;
        if(len[s[i]]>len[s[b]])
            b = i;
    }
    cout << s[a] << " " << s[b] << endl;
    return 0;
}