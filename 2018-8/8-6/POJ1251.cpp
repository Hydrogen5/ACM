//Jungle Roads
#include <iostream>
using namespace std;
int paent[26];
int n;
int edge_num;
struct Edge
{
    int v1, v2, weight;
}edges[100];
int cmp(Edge a,Edge b)
{
    return a.weight > b.weight;
}
int