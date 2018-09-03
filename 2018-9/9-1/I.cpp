//skr
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
char str[2000010];
char ns[4000010];
int res[4000010];
int len;
int nlen;
void change()
{
    ns[0] = '&';
    for (int i = 1; i <= len; i++)
    {
        ns[2 * i - 1] = '$';
        ns[2 * i] = str[i];
    }
    ns[2 * len + 1] = '$';
    ns[2 * len + 2] = '\0';
    nlen = 2 * len + 2;
}
void man()
{
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < nlen; i++)
    {
        res[i] = mx > i ? min(res[2 * id - i], mx - i) : 1;
        while (ns[i + res[i]] == ns[i - res[i]])
            ++res[i];
        if (mx < i + res[i])
        {
            mx = i + res[i];
            id = i;
        }
        if (resLen < res[i])
        {
            resLen = res[i];
            resCenter = i;
        }
    }
}
int main()
{
    scanf("%s", str + 1);
    len = strlen(str + 1);
    change();
    man();
    long long ans=0;
    for(int i=1;i<nlen;i++)
    {
        
    }
    cout << endl;
    return 0;
}