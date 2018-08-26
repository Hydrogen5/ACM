//Vigenere Cipher Encryption
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int square[30][30];
void init()
{
    for (int i = 0; i <= 26; i++)
        for (int j = 0; j <= 26; j++)
            square[i][j] = (i + j + 1) % 26;
}
char key[2000];
char text[200000];
char ans[200000];
int main()
{
    init();
    while (cin >> key && key[0] != '0')
    {
        cin >> text;
        int lenk = strlen(key);
        int lent = strlen(text);
        for (int i = 0; i < lent; i++)
        {
            ans[i] = square[key[i % lenk] - 'A'][text[i] - 'A'] + 'A';
        }
        ans[lent] = '\0';
        puts(ans);
    }
    return 0;
}