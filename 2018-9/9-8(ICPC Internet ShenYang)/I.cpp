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
char s[200010];
bool Bit[800010];
bool nbit[800010];
char ans[100010];
int Id;
char word[15];
int num = 0;
struct node
{
    int Next[2];
    int ID;
    void init()
    {
        ID = -1;
        Next[0] = -1;
        Next[1] = -1;
    }
} trie[100000];

void Init()
{
    trie[0].init();
    num = 0;
}
void Insert()
{
    int cur = 0;
    int pos = 0;
    while (word[cur])
    {
        if (trie[pos].Next[word[cur] - '0'] == -1)
        {
            trie[++num].init();
            trie[pos].Next[word[cur] - '0'] = num;
        }
        pos = trie[pos].Next[word[cur] - '0'];
        cur++;
    }
    trie[pos].ID = Id;
}
int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        Init();
        memset(Bit, 0, sizeof(Bit));
        memset(ans, 0, sizeof(ans));
        int n, m;
        scanf("%d%d", &n, &m);
        while (m--)
        {
            scanf("%d", &Id);
            scanf("%s", word);
            Insert();
        }
        scanf("%s", s);
        int len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            int tmp;
            if (s[i] >= 'A' && s[i] < 'Z')
                tmp = s[i] - 'A' + 10;
            else
            {
                if (s[i] >= 'a' && s[i] < 'z')
                    tmp = s[i] - 'a' + 10;
                else
                    tmp = s[i] - '0';
            }
            
            int cnt = 3;
            while (tmp)
            {
                Bit[4 * i + cnt] = tmp % 2;
                cnt--;
                tmp /= 2;
            }
        }
        // for(int i=0;i<4*len;i+=9)
        // {
        //     for(int j=0;j<9;j++)
        //         printf("%d", Bit[i + j]);
        //     printf("\n");
        // }
        int cur = 0;
        for (int i = 0; (i + 9) <= (4 * len); i += 9)
        {
            int cnt1 = 0;
            for (int j = 0; j < 8; j++)
            {
                if (Bit[i + j] == 1)
                    cnt1++;
            }
            if ((cnt1 % 2) != Bit[i + 8])
            {
                for (int j = 0; j < 8; j++)
                    nbit[cur++] = Bit[i + j];
            }
        }
        // for(int i=0;i<cur;i++)
        //         printf("%d", nbit[i]);
        //     printf("\n");
        int al = 0;
        int pos = 0;
        for (int i = 0; i < cur; i++)
        {
            pos = trie[pos].Next[nbit[i]];
            if (trie[pos].ID != -1)
            {
                ans[al++] = (char)(trie[pos].ID);
                pos = 0;
            }
        }

        for(int i=0;i<n;i++)
            printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}