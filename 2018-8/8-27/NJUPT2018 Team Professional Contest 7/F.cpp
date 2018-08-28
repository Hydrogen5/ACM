//Guess the Numbers
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
string str;
int num[100];
stack<int> s;
#define symcmp(x,y) (x=='('||y=='('||((y=='*'||y=='/') && (x=='+'||x=='-')))
#define isph(ch) (ch>='a'&&ch<='z')

string change(string source)
{
	stack<char> symbol;
	string ans;

	for (int i = 0; i < source.size();i++)//i为第一个数字的下标，j为数字后第一个符号
	{
		char ch;
		ch = source[i];
		if (isph(ch))
		{
			ans += ch;
			continue;
		}
		if (ch == ')')
		{
			char top = symbol.top();
			symbol.pop();
			while (top != '(')
			{
				ans += top;
				top = symbol.top();
				symbol.pop();
			}
			continue;
		}

		if (!symbol.empty())
		{
			char top = symbol.top();
			if (!symcmp(top, ch))
			{
				ans += top;
				symbol.pop();
			}
		}
		symbol.push(ch);
	}

	while (!symbol.empty())
	{
		char top = symbol.top();
		symbol.pop();
		ans += top;
	}

	return ans;
}

int cal()
{
    int cnt = 0;
    for (int i = 0; i < str.length(); i++)
    {

        if (str[i] >= 'a' && str[i] <= 'z')
        {
            s.push(num[cnt++]);
        }
        else
        {
            if (str[i] == '+')
            {
                int fir = s.top();
                s.pop();
                int sec = s.top();
                s.pop();
                s.push(fir + sec);
            }
            if (str[i] == '*')
            {
                int fir = s.top();
                s.pop();
                int sec = s.top();
                s.pop();
                s.push(fir * sec);
            }
            if (str[i] == '-')
            {
                int fir = s.top();
                s.pop();
                int sec = s.top();
                s.pop();
                s.push(sec - fir);
            }
        }
    }
    int ans = s.top();
    s.pop();
    return ans;
}
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        int nans;
        cin >> nans;
        if (n == 0 && nans == 0)
            break;
        string sou;
        cin >> sou;
        str = change(sou);
        sort(num, num + n);
        int flag = 0;
        do
        {
            if (cal() == nans)
            {
                flag = 1;
                break;
            }
        } while (next_permutation(num, num + n));
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}