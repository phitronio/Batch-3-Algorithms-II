#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
int parentSize[N];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
int mx = 0;
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            // A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
            mx = max(mx, parentSize[leaderA]);
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
            mx = max(mx, parentSize[leaderB]);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    int cmp = n;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA != leaderB)
        {
            cmp--;
            dsu_union(a, b);
        }
        cout << cmp << " " << mx << endl;
    }
    return 0;
}