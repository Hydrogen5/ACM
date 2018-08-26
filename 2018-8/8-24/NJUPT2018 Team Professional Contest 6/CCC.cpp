//Stack Machine Executor
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
int operations[100005];
char op[10];
int opscnt;
int trans()
{
    if (op[0] == 'N')
        return NUM;
    else if (op[0] == 'P')
        return POP;
    else if (op[0] == 'I')
        return INV;
    else if (op[0] == 'D' && op[1] == 'U')
        return DUP;
    else if (op[0] == 'A')
        return ADD;
    else if (op[0] == 'S' && op[1] == 'W')
        return SWP;
    else if (op[0] == 'S' && op[1] == 'U')
        return SUB;
    else if (op[0] == 'M' && op[1] == 'U')
        return MUL;
    else if (op[0] == 'D' && op[1] == 'I')
        return DIV;
    else if (op[0] == 'M' && op[1] == 'O')
        return MOD;
}
int main()
{
    while (1)
    {
        opscnt = 0;
        scanf("%s", op);
        if (op[0] == 'Q')
            break;
        while (1)
        {
            scanf("%s", op);
            if (op[[0]] == 'E')
                break;
            operations[opscnt++] = trans();
        }
    }
    return 0;
}