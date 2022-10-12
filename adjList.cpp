#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(int v, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(v + 1, 0);
    queue<int> q;
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            q.push(i);
            vis[i] = 1;
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            bfs.push_back(cur);
            for (auto it : adj[cur])
            {
                if (!vis[it])
                {
                    q.push(it);
                    vis[cur] = 1;
                }
            }
        }
    }
    return bfs;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    while (m--)
    {
        int u, v; //, wt;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> bfst;
    bfst = (n, adj[n + 1]);
    vector<int>::iterator it;
    for (it = bfst.begin(); it != bfst.end(); it++)
    {
        cout << *it << " ";
    }

    // for (int i = 0; i < n + 1; i++)
    // {
    //     for (int j = 0; j < n + 1; j++)
    //     {
    //         cout << adj[i][j] << " ";
    //     }
    // }
    // for (auto it : adj)
    // {
    //     for (auto z : it)
    //     {
    //         cout << z << " ";
    //     }
    // }
    return 0;
}