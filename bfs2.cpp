#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(int n, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(n + 1, 0);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            q.push(i);
            vis[i] = 1;
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for (auto it : adj[node])
            {
                if (!vis[it])

                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
    return bfs;
}
void addedge(vector<int> adj[])
{
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void print(vector<int> bfst)
{
    for (auto it : bfst)
    {
        cout << it << " ";
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    while (m--)
    {
        addedge(adj);
    }
    vector<int> bfst = bfs(n, adj);
    print(bfst);
    return 0;
}