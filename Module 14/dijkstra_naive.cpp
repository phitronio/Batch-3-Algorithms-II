#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> v[N];
int dis[N];
void dijkstra(int s)
{
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int i = 0; i < v[parent].size(); i++)
        {
            pair<int, int> child = v[parent][i];
            int childNode = child.first;
            int childCost = child.second;
            if (dis[parent] + childCost < dis[childNode])
            {
                dis[childNode] = dis[parent] + childCost;
                q.push(childNode);
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dis[i] << endl;
    }
    return 0;
}