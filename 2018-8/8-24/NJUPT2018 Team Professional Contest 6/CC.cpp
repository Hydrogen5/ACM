//Stack Machine Executor
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
#define LL long long
#define MAXNN 1005
#define MAXO 100005
#define MAXN 100005
#define INF 1000000000

#define NUM 0
#define POP 1
#define INV 2
#define DUP 3
#define SWP 11
#define ADD 12
#define SUB 13
#define MUL 14
#define DIV 15
#define MOD 16

LL OP[MAXO];
LL Stack[MAXNN];
LL init[MAXN];
LL num[MAXO];
LL ptrn;
LL ptrcnt;
LL ptr;
LL ptrnow;
LL ptrop;
stack<LL> s;
bool judge(LL op)
{
    if (op > 10)
    {
        return s.size() >= 2;
    }
    if (op > 0)
    {
        return s.size() >= 1;
    }
    return true;
}

bool ope(LL op)
{
    if (!judge(op))
    {
        return false;
    }

    switch (op)
    {
    case NUM:
        s.push(num[ptrcnt++]);
        break;
    case POP:
        s.pop();
        break;
    case INV:
        LL num = s.top();
        s.pop();
        s.push(-num);
        break;
    case 3:
        s.push(s.top());
        break;
    case 4:
        LL top, sec;
        top = s.top();
        s.pop();
        sec = s.top();
        s.pop();
        s.push(top);
        s.push(sec);
        break;
    case ADD:
        top = s.top();
        s.pop();
        sec = s.top();
        s.pop();
        s.push(top + sec);
        break;
    case SUB:
        top = s.top();
        s.pop();
        sec = s.top();
        s.pop();
        s.push(sec - top);
        break;
    case MUL:
        top = s.top();
        s.pop();
        sec = s.top();
        s.pop();
        s.push(top * sec);
        break;
    case DIV:
        if (s.top()==0)
            return false;
        top = s.top();
        s.pop();
        sec = s.top();
        s.pop();
        s.push(sec / top);
        break;
    case MOD:
        if (s.top()==0)
            return false;
        int temp;
        LL mid;
        temp = 1;
        int t1, t2;
        t1 = s.top();
        s.pop();
        t2 = s.top();
        if ((t2 / t1) < 0)
            temp = -1;
        mid = t2 / t1;
        mid = temp * abs(mid);
        s.push(mid);
        break;
    }
    if (s.top() > INF)
        return false;
    return true;
}

void Init()
{
    ptrn = ptr = ptrnow = ptrop = 0;
}

void run()
{
    ptr = 1;
    ptrcnt = 1;
    for (int i = 1; i <= ptrop; i++)
    {
        if (!ope(OP[i]))
        {
            printf("ERROR\n");
            return;
        }
    }
    if (s.size() == 1)
        printf("%lld\n", s.top());
    else
        printf("ERROR\n");
}

int main()
{
    char ch[5];
    while (true)
    {
        Init();
        scanf("%s", ch);
        if (ch[0] == 'Q')
            break;
        if (strcmp(ch, "NUM") == 0)
        {
            OP[++ptrop] = 0;
            scanf("%I64d", &num[++ptrn]);
        }
        if (strcmp(ch, "POP") == 0)
        {
            OP[++ptrop] = 1;
            ;
        }
        if (strcmp(ch, "INV") == 0)
        {
            OP[++ptrop] = 2;
            ;
        }
        if (strcmp(ch, "DUP") == 0)
        {
            OP[++ptrop] = 3;
            ;
        }
        if (strcmp(ch, "SWP") == 0)
        {
            OP[++ptrop] = 11;
            ;
        }
        if (strcmp(ch, "ADD") == 0)
        {
            OP[++ptrop] = 12;
            ;
        }
        if (strcmp(ch, "SUB") == 0)
        {
            OP[++ptrop] = 13;
            ;
        }
        if (strcmp(ch, "MUL") == 0)
        {
            OP[++ptrop] = 14;
            ;
        }
        if (strcmp(ch, "DIV") == 0)
        {
            OP[++ptrop] = 15;
            ;
        }
        if (strcmp(ch, "MOD") == 0)
        {
            OP[++ptrop] = 16;
            ;
        }

        while (true)
        {
            scanf("%s", ch);
            if (ch[0] == 'E')
                break;
            if (strcmp(ch, "NUM") == 0)
            {
                OP[++ptrop] = 0;
                scanf("%I64d", &num[++ptrn]);
                continue;
            }
            if (strcmp(ch, "POP") == 0)
            {
                OP[++ptrop] = 1;
                continue;
            }
            if (strcmp(ch, "INV") == 0)
            {
                OP[++ptrop] = 2;
                continue;
            }
            if (strcmp(ch, "DUP") == 0)
            {
                OP[++ptrop] = 3;
                continue;
            }
            if (strcmp(ch, "SWP") == 0)
            {
                OP[++ptrop] = 11;
                continue;
            }
            if (strcmp(ch, "ADD") == 0)
            {
                OP[++ptrop] = 12;
                continue;
            }
            if (strcmp(ch, "SUB") == 0)
            {
                OP[++ptrop] = 13;
                continue;
            }
            if (strcmp(ch, "MUL") == 0)
            {
                OP[++ptrop] = 14;
                continue;
            }
            if (strcmp(ch, "DIV") == 0)
            {
                OP[++ptrop] = 15;
                continue;
            }
            if (strcmp(ch, "MOD") == 0)
            {
                OP[++ptrop] = 16;
                continue;
            }
        }
        int N;
        scanf("%I64d", &N);
        for (int i = 0; i < N; i++)
        {
            while (s.size())
                s.pop();
            LL num;
            scanf("%lld", &num);
            s.push(num);
            run();
        }
        printf("\n");
    }
    return 0;
}