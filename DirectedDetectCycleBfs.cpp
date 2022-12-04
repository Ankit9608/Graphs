// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// bool check(vector<int> adj[], int cur, vector<int> vis, vector<int> dfsvis)
// {
//     // if (vis[cur] == 0)
//     vis[cur] = 1,
//     dfsvis[cur] = 1;
//     for (auto it : adj[cur])
//     {
//         if (vis[it] == 0)
//         {
//             vis[it] = 1;
//             dfsvis[it] = 1;
//             if (check(adj, it, vis, dfsvis))
//             {
//                 return true;
//             }
//             else if (dfsvis[it] == 1 && vis[it])
//             {
//                 return true;
//             }
//         }
//         // dfsvis[it] = 0;
//     }
//     dfsvis[cur] = 0;
//     return false;
// }
// bool cycle(vector<int> adj[], int n)
// {
//     vector<int> vis(n + 1, 0);
//     vector<int> dfsvis(n + 1, 0);
//     for (int i = 1; i <= n; i++)
//     {
//         vis[i] = 0;
//         dfsvis[i] = 0;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (vis[i] == 0)
//         {
//             if (check(adj, i, vis, dfsvis))
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// void addedge(vector<int> adj[])
// {
//     int u, v;
//     cin >> u >> v;
//     adj[u].push_back(v);
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
//     cout << cycle(adj, n) << endl;
//     return 0;
// }

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    bool check(int cur, vector<int> adj[], vector<int> vis, vector<int> dfsvis)
    {
        vis[cur] = 1;
        dfsvis[cur] = 1;
        for (auto it : adj[cur])
        {
            if (!vis[it])
            {
                if (check(it, adj, vis, dfsvis))
                {
                    return true;
                }
                else if (dfsvis[it])
                {
                    return true;
                }
            }
        }
        dfsvis[cur] = 0;
        return false;
    }
    bool iscycle(vector<int> adj[], int n)
    {
        vector<int> vis(n);
        vector<int> dfsvis(n);
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            dfsvis[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if (check(i, adj, vis, dfsvis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
void addedge(vector<int> adj[], int u, int v)
{
    // int u,v;
    // cin>>u>>v;
    adj[u].push_back(v);
}
int main()
{
    int n;
    vector<int> adj[n];
    addedge(adj, 0, 1);
    addedge(adj, 1, 2);
    addedge(adj, 1, 5);
    addedge(adj, 2, 3);
    addedge(adj, 3, 4);
    addedge(adj, 4, 0);
    addedge(adj, 4, 1);
    solution obj;
    if (obj.iscycle(adj, n))
    {
        cout << "Cycle detected\n";
    }
    else
    {
        cout << "No cycle detected\n";
    }
    return 0;
}
