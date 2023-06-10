#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void addedge(int u, int v, int wt, vector<pair<int, int>> adj[])
{
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}
void dijkstraSet(vector<int> &dist, vector<pair<int, int>> adj[])
{
    set<pair<int, int>> st;
    st.insert({0, 0});
    dist[0] = 0;
    while (!st.empty())
    {
        auto it = *(st.begin());
        st.erase(it);
        int node = it.first;
        int dis = it.second;
        for (auto bt : adj[node])
        {
            int nei = bt.first;
            int wt = bt.second;
            if (dist[nei] > wt + dis)
            {
                if (dist[nei] != 1e9)
                {
                    st.erase({nei, dist[nei]});
                }
                st.insert({nei, wt + dis});

                dist[nei] = wt + dis;
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int a, b, k;
        cin >> a >> b >> k;
        addedge(a, b, k, adj);
    }
    vector<int> dist(n, 1e9);
    dijkstraSet(dist, adj);
    for (auto it : dist)
    {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}