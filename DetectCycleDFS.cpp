// // #include <iostream>
// // #include <bits/stdc++.h>
// // using namespace std;
// // bool cycle(vector<int> adj[], int i, vector<int> vis, int par)
// // {
// //     vis[i] = 1;
// //     for (auto it : adj[i])
// //     {
// //         if (!vis[it])
// //         {
// //             if (cycle(adj, it, vis, i))
// //                 return true;
// //         }
// //         else if (it != par)
// //         {
// //             return true;
// //         }
// //     }
// //     return false;
// // }
// // bool detect(vector<int> adj[], int v)
// // {
// //     vector<int> vis(v + 1, 0);
// //     for (int i = 1; i <= v; i++)
// //     {
// //         if (!vis[i])
// //         {
// //             if (cycle(adj, i, vis, -1))
// //             {
// //                 return true;
// //             }
// //         }
// //     }
// //     return false;
// // }
// // void addedge(vector<int> adj[])
// // {
// //     int u, v;
// //     cin >> u >> v;
// //     adj[u].push_back(v);
// //     adj[v].push_back(u);
// // }
// // int main()
// // {
// //     int n, k;
// //     cin >> n >> k;
// //     vector<int> adj[n + 1];
// //     while (k--)
// //     {
// //         addedge(adj);
// //     }
// //     cout << detect(adj, n);
// //     return 0;
// // }

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// bool check(vector<int> &vis, vector<int> adj[], int i, int par)
// {
//     vis[i] = 1;
//     for (auto it : adj[i])
//     {
//         if (!vis[it])
//         {
//             if (check(vis, adj, it, i))
//             {
//                 return true;
//             }
//             else if (par != it)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// bool detect(vector<int> adj[], int n)
// {
//     vector<int> vis(n + 1, 0);
//     for (int i = 1; i <= n; i++)
//     {
//         if (!vis[i])
//         {
//             if (check(vis, adj, i, -1))
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
//     cout << detect(adj, n);
// }

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> vis, vector<int> adj[], int cur, int par)
{
    vis[cur] = 1;
    for (auto it : adj[cur])
    {
        if (vis[it] == 0)
        {
            if (check(vis, adj, it, cur))
            {
                return true;
            }
        }
        else if (par != it)
        {
            return true;
        }
    }
    return false;
}
bool cycle(vector<int> adj[], int n)
{
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            if (check(vis, adj, i, -1))
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
    cout << cycle(adj, n);

    return 0;
}