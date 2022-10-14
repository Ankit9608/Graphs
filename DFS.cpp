// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// void dfshelp(int i, vector<int> adj[], vector<int> &temp, vector<int> &vis)
// {
//     temp.push_back(i);
//     vis[i] = 1;
//     for (auto it : adj[i])
//     {
//         if (!vis[i])
//         {
//             dfshelp(it, adj, temp, vis);
//         }
//     }
// }
// vector<int> dfs(vector<int> adj[], int v)
// {
//     vector<int> temp;
//     vector<int> vis(v + 1, 0);
//     for (int i = 1; i <= v; i++)
//     {

//         dfshelp(i, adj, temp, vis);
//     }
// }
// void addedge(vector<int> adj[])
// {
//     int u, v;
//     cin >> u >> v;
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     vector<int> adj[n + 1];
//     while (k--)
//     {
//         addedge(adj);
//     }
//     vector<int> dfst;
//     dfst = dfs(adj, n);
// }

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void dfshelp(vector<int> &vis, vector<int> adj[], vector<int> &temp, int i)
{
    temp.push_back(i);
    vis[i] = 1;
    for (auto it : adj[i])
    {
        if (!vis[it])
        {
            dfshelp(vis, adj, temp, it);
        }
    }
}
vector<int> dfs(vector<int> adj[], int v)
{
    vector<int> vis(v + 1, 0);
    vector<int> temp;
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            dfshelp(vis, adj, temp, i);
        }
    }
    return temp;
}
void addedge(vector<int> adj[])
{
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printdfs(vector<int> dfst)
{
    for (auto it : dfst)
    {
        cout << it << " ";
    }
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
    vector<int> dfst = dfs(adj, n);
    printdfs(dfst);
    return 0;
}