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

bool judge(LL op)
{
    if (op > 10)
    {
        return ptr >= 2;
    }
    if (op > 0)
    {
        return ptr >= 1;
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
        Stack[++ptr] = num[ptrcnt++];
        break;
    case POP:
        ptr--;
        break;
    case INV:
        Stack[ptr] = -Stack[ptr];
        break;
    case DUP:
        Stack[ptr + 1] = Stack[ptr];
        ptr++;
        break;
    case SWP:
        LL t;
        t = Stack[ptr - 1];
        Stack[ptr - 1] = Stack[ptr];
        Stack[ptr] = t;
        break;
    case ADD:
        Stack[ptr - 1] += Stack[ptr];
        ptr--;
        break;
    case SUB:
        Stack[ptr - 1] -= Stack[ptr];
        ptr--;
        break;
    case MUL:
        Stack[ptr - 1] *= Stack[ptr];
        ptr--;
        break;
    case DIV:
        if (!Stack[ptr])
            return false;
        Stack[ptr - 1] /= Stack[ptr];
        ptr--;
        break;
    case MOD:
        if (!Stack[ptr])
            return false;
        int temp;
        temp = 1;
        int t1, t2;
        t1 = Stack[ptr];
        t2 = Stack[ptr - 1];
        if ((t2 / t1) < 0)
            temp = -1;
        Stack[ptr - 1] %= Stack[ptr];
        Stack[ptr - 1] = temp * abs(Stack[ptr - 1]);

        ptr--;
        break;
    }
    if (Stack[ptr] > INF)
        return false;
    return true;
}

void Init()
{
    ptrn = ptr = ptrnow = ptrop = 0;
}

void run(LL now)
{
    ptr = 1;
    ptrcnt = 1;
    Stack[ptr] = init[now];
    for (int i = 1; i <= ptrop; i++)
    {
        if (!ope(OP[i]))
        {
            printf("ERROR\n");
            return;
        }
    }
    if (ptr == 1)
        printf("%I64d\n", Stack[1]);
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
            scanf("%I64d", &init[++ptrnow]);
        }

        for (int i = 1; i <= N; i++)
        {
            run(i);
        }
        printf("\n");
    }
    return 0;
}