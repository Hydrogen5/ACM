#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXINT 0x7fffffff
#define N 200009
using namespace std;

struct HIN
{
    char sex;
    int dna, alive, pre;
} hin[N];

int Find(int x) 
{ 
    return hin[x].pre == -x ? x : hin[x].pre = Find(hin[x].pre); 
}

int eve(int &pn)
{
    int m, tm, tf;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &tf);
        if (tf > 0)
        {
            scanf("%d", &tm);
            getchar();
            hin[++(pn)].sex = getchar();
            hin[pn].pre = tm;
            hin[pn].alive = 1;
        }
        else
            hin[-tf].alive = 0;
    }
    return m;
}


void query(int n, int m)
{
    int tp, tn, np = 0, nn = 0, flan = 1, flap = 1;
    for (int i = 1; i <= n; i++)
        if (hin[i].alive)
        {
            if (hin[Find(i)].dna > 0)
            {
                if (flap)
                {
                    flap = 0;
                    tp = i;
                    np++;
                }
                else if (hin[Find(i)].dna != hin[Find(tp)].dna)
                {
                    printf("NO\n");
                    return;
                }
            }
            else
            {
                if (flan)
                {
                    flan = 0;
                    tn = i;
                    nn++;
                }
                else if (hin[Find(i)].dna != hin[Find(tn)].dna)
                    nn++;
            }
        }
    if (nn > 1 || (np && nn))
        printf("POSSIBLY\n");
    else
        printf("YES\n");
}

int main()
{
    freopen("eve.in", "r", stdin);
    freopen("eve.out", "w", stdout);
    int n, m;
    while (scanf("%d", &n) == 1)
    {
        getchar();
        for (int i = 1; i <= n; i++)
        {
            char c = getchar();
            hin[i].sex = c;
            hin[i].dna = -i;
            hin[i].pre = -i;
            hin[i].alive = 1;
            getchar();
        }
        m = eve(n);
        int k, id, dna;
        scanf("%d", &k);
        while (k--)
        {
            scanf("%d %d", &id, &dna);
            hin[Find(id)].dna = dna;
        }
        query(n, m);
    }
    return 0;
}