#include <bits/stdc++.h>
using namespace std;
void addedge(int u, int v, int wt, vector<pair<int, int>> adj[])
{
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}
void dijkstra(vector<pair<int, int>> adj[], vector<int> &dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        int cur = node.first;
        int dis = node.second;
        for (auto it : adj[cur])
        {
            int nei = it.first;
            int wt = it.second;
            if (wt + dis <= dist[nei])
            {
                pq.push({nei, wt + dis});
                dist[nei] = wt + dis;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        addedge(a, b, w, adj);
    }
    vector<int> dist(n + 1, INT_MAX);
    dijkstra(adj, dist);
    for (auto it : dist)
    {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}