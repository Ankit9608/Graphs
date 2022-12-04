// using bfs traversal
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(int i, vector<int> adj[], vector<int> vis)
{
    queue<int> q;
    q.push(i);
    vis[i] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto it : adj[cur])
        {
            if (vis[it] == -1)
            {

                q.push(it);
                vis[it] = 1 - vis[cur];
            }
            else if (vis[it] == vis[cur])
            {
                return false;
            }
        }
    }
    return true;
}
bool bitpertiat(vector<int> adj[], int n)
{
    vector<int> vis(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == -1)
        {
            if (check(i, adj, vis))
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
    cout << bitpertiat(adj, n);
    return 0;
}