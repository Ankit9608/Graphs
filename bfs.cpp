// #include <bits/stdc++.h>

// using namespace std;
// class Solution
// {
// public:
//     vector<int> bfsOfGraph(int V, vector<int> adj[])
//     {
//         vector<int> bfs;
//         vector<int> vis(V, 0);
//         queue<int> q;
//         q.push(0);
//         vis[0] = 1;
//         while (!q.empty())
//         {
//             int node = q.front();
//             q.pop();
//             bfs.push_back(node);

//             for (auto it : adj[node])
//             {
//                 if (!vis[it])
//                 {
//                     q.push(it);
//                     vis[it] = 1;
//                 }
//             }
//         }

//         return bfs;
//     }
// };

// void addEdge(vector<int> adj[], int u, int v)
// {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }

// void printAns(vector<int> &ans)
// {
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
// }
// int main()
// {
//     vector<int> adj[5];

//     addEdge(adj, 0, 1);
//     addEdge(adj, 0, 2);
//     addEdge(adj, 0, 3);
//     addEdge(adj, 2, 4);

//     Solution obj;
//     vector<int> ans = obj.bfsOfGraph(5, adj);
//     printAns(ans);
//     cout << endl;

//     return 0;
// }

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(vector<int> adj[], int v)
{
    vector<int> vis(v + 1, 0);
    vector<int> bfs;
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
    vector<int> bfst = bfs(adj, n);
    print(bfst);
    return 0;
}