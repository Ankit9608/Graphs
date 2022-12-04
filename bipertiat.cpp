// using dfs
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(int cur, vector<int> adj[], vector<int> colour)
{
    // colour[cur] = 0;
    if (colour[cur] == -1)
    {
        colour[cur] == 0;
    }
    for (auto it : adj[cur])
    {
        if (colour[it] == -1)
        {
            colour[it] = 1 - colour[cur];
            if (!check(it, adj, colour))
            {
                return false;
            }
            else if (colour[it] == colour[cur])
            {
                return false;
            }
        }
    }
    return true;
}
bool bipertiate(vector<int> adj[], int n)
{
    vector<int> colour(n + 1, -1);
    for (int i = 1; i < n; i++)
    {
        if (colour[i] == -1)
        {
            if (!check(i, adj, colour))
            {
                return false;
            }
        }
    }
    return true;
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
    cout << bipertiate(adj, n);
    return 0;
}