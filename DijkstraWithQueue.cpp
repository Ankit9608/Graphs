#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(int u, int v, int wt, vector<pair<int, int>> adj[])
{
    pair<int, int> pr = make_pair(u, wt);
    adj[v].push_back(pr);
    pair<int, int> br = make_pair(v, wt);
    adj[u].push_back(br);
}
void dijkstraqueue(vector<pair<int, int>> adj[], vector<int> &dist)
{
    queue<pair<int, int>> q;
    pair<int, int> pr = make_pair(0, 0);
    dist[0] = 0;
    q.push(pr);
    while (!q.empty())
    {
        // sjk
        // sk
        auto it = q.front();
        q.pop();
        int node = it.first;
        int dis = it.second;
        for (auto br : adj[node])
        {
            // mlmlm
            // mkmk
            int nei = br.first;
            int wt = br.second;
            if (dist[nei] > dis + wt)
            {
                pair<int, int> pr = make_pair(nei, dis + wt);
                q.push(pr);
                dist[nei] = dis + wt;
            }
        }
    }
    // ll
}
int main()
{
    int n, m;
    std::cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b, wt;
        std::cin >> a >> b >> wt;
        addedge(a, b, wt, adj);
    }
    vector<int> dist(n, 1e9);
    dijkstraqueue(adj, dist);
    for (auto it : dist)
    {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}