// given a source and a target node with undirected weighted graph find the shortest path between the source and
// destination

// the parent array  only stores the minimum distance from the source to destination it does not give the
// shortest path between any two node but give only between the source and destination
// also dijkstra algorithm is usful only for the source to all node shortest path and it is not applecable
// for the negative weight cyclic graph because the wt always gets reduced at the time of updation
// in the distance array and we will stuck in infinet loop
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
void addedge(int u, int v, int wt, vector<pair<int, int>> adj[])
{
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}
vector<int> printshortestpath(int n, vector<pair<int, int>> adj[], vector<int> dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.first;
        int dis = it.second;
        for (auto bt : adj[node])
        {
            if (dist[bt.first] > dis + bt.second)
            {
                dist[bt.first] = dis + bt.second;
                parent[bt.first] = node;
                pq.push({bt.first, bt.second + dis});
            }
        }
    }
    return parent;
}
int main()
{
    int n, m;
    std::cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        std::cin >> u >> v >> wt;
        addedge(u, v, wt, adj);
    }
    vector<int> dist(n, 1e9);
    // vector<int> parent(n);

    vector<int> ans = printshortestpath(n, adj, dist);
    int src, dest;
    std::cout << "Enter the source and deist\n";
    std::cin >> src >> dest;
    int idx = dest;
    for (int i = 0; i < n; i++)
    {
        std::cout << ans[i] << " ";
    }
    std::cout << "\n";
    vector<int> list;
    // cout << ans[dest] << "\n";
    if (ans[dest] == dest)
    {
        // cout << dest << " " << ans[dest] << "\n";
        std::cout << "-1" << endl;
    }
    while (ans[idx] != idx)
    {
        list.push_back(ans[idx]);
        idx = ans[idx];
    }
    // list.push_back(src);

    reverse(list.begin(), list.end());
    list.push_back(dest);
    // list.push_back(dest);
    for (auto it : list)
    {
        std::cout << it << " ";
    }

    return 0;
}