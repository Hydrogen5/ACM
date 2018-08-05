#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+100;
int ch[maxn][27] = {0};
int main()
{
    ios::sync_with_stdio(false);
    int n, q, t;
    cin >> t;
    for(int cnt = 1; cnt <= t; cnt++)
    {
        cout << "Case #" << cnt << ':' << endl;
        memset(ch, 0, sizeof(ch));
        cin >> n >> q;
        string s;
        cin >> s;
        for(int i = 1; i <= s.size(); i++)
        {
            for(int j = 0; j < 26; j++)
            {
                ch[i][j] = ch[i-1][j];
                if(s[i-1]-'A' == j)   ch[i][j]++;
            }
        }
        /*for(int i = 0; i <= s.size(); i++)
        {
            for(int j = 0; j < 26; j++)
                cout << ch[i][j] << ' ';
            cout << endl;
        }*/
        int l, r;
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d", &l, &r);
            for(int j = 0; j < 26; j++)
            {   
                if(ch[r][j]-ch[l-1][j] == 0)  continue;
                else
                {
                    printf("%d\n", ch[r][j]-ch[l-1][j]);
                    break;
                }
            }
        }
    }
    return 0;
}