#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool cycle(vector<int> adj[], int i, vector<int> vis, int par)
{
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            if (cycle(adj, it, vis, i))
                return true;
        }
        else if (it != par)
        {
            return true;
        }
    }
    return false;
}
bool detect(vector<int> adj[], int v)
{
    vector<int> vis(v + 1, 0);
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            if (cycle(adj, i, vis, -1))
            {
                return true;
            }
        }
    }
    return false;
}
void addedge(vector<int> adj[])
{
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> adj[n + 1];
    while (k--)
    {
        addedge(adj);
    }
    cout << detect(adj, n);
    return 0;
}