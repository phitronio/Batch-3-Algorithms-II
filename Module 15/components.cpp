#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int dis[N];
bool vis[N];
vector<int> v[N];
vector<int> cmp;
void dfs(int s)
{
    vis[s] = true;
    cmp.push_back(s);
    for (int child : v[s])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i);
            for (int val : cmp)
            {
                cout << val << " ";
            }
            cout << endl;
            cmp.clear();
        }
    }
    cout << cnt << endl;
    return 0;
}