// // // // // Detect the cycle is present in graph or not
// // // // #include <iostream>
// // // // #include <bits/stdc++.h>
// // // // using namespace std;
// // // // bool cycle(int v, vector<int> adj[], int s, vector<int> &vis)
// // // // {
// // // //     queue<pair<int, int>> q;
// // // //     vis[s] = 1;

// // // //     q.push({s, -1});
// // // //     while (!q.empty())
// // // //     {
// // // //         int node = q.front().first;
// // // //         int par = q.front().second;
// // // //         q.pop();
// // // //         if (!vis[node])
// // // //         {
// // // //             // vis[node] = 1;
// // // //             for (auto it : adj[node])
// // // //             {
// // // //                 if (!vis[it])
// // // //                 {
// // // //                     q.push({it, node});
// // // //                     vis[it] = 1;
// // // //                 }
// // // //                 else if (it != par)
// // // //                 {
// // // //                     return true;
// // // //                 }
// // // //             }
// // // //         }
// // // //     }

// // // //     return false;
// // // // }

// // // // bool detect(vector<int> adj[], int v)
// // // // {
// // // //     vector<int> vis(v + 1, 0);
// // // //     for (int i = 1; i <= v; i++)
// // // //     {
// // // //         if (!vis[i])
// // // //         {
// // // //             // vis[i] = 1;
// // // //             if (cycle(v, adj, i, vis))
// // // //             {
// // // //                 return true;
// // // //             }
// // // //         }
// // // //     }
// // // //     return false;
// // // // }
// // // // void addedge(vector<int> adj[])
// // // // {
// // // //     int u, v;
// // // //     cin >> u >> v;
// // // //     adj[u].push_back(v);
// // // //     adj[v].push_back(u);
// // // // }
// // // // int main()
// // // // {
// // // //     int n, k;
// // // //     cin >> n >> k;
// // // //     vector<int> adj[n + 1];
// // // //     while (k--)
// // // //     {
// // // //         addedge(adj);
// // // //     }
// // // //     // for(int i=1;i<n;i++){

// // // //     // }
// // // //     cout << detect(adj, n);
// // // //     return 0;
// // // // }

// // // #include <iostream>
// // // #include <bits/stdc++.h>
// // // using namespace std;

// // // void addege(vector<int> adj[])
// // // {
// // //     int u, v;
// // //     cin >> u >> v;
// // //     adj[u].push_back(v);
// // //     adj[v].push_back(u);
// // // }
// // // bool cycle(vector<int> &vis, int s, vector<int> adj[], int v)
// // // {
// // //     queue<pair<int, int>> q;
// // //     q.push({s, -1});
// // //     vis[s] = 1;
// // //     while (!q.empty())
// // //     {
// // //         int node = q.front().first;
// // //         int par = q.front().second;
// // //         q.pop();
// // //         for (auto it : adj[node])
// // //         {
// // //             if (!vis[it])
// // //             {
// // //                 q.push({it, node});
// // //                 vis[it] = 1;
// // //             }
// // //             else if (it != par)
// // //             {
// // //                 return true;
// // //             }
// // //         }
// // //     }
// // //     return false;
// // // }
// // // bool detect(vector<int> adj[], int n)
// // // {
// // //     vector<int> vis(n + 1, 0);
// // //     for (int i = 1; i <= n; i++)
// // //     {
// // //         if (!vis[i])
// // //         {
// // //             if (cycle(vis, i, adj, n))
// // //             {
// // //                 return true;
// // //             }
// // //         }
// // //     }
// // //     return false;
// // // }
// // // int main()
// // // {
// // //     int n, k;
// // //     cin >> n >> k;
// // //     vector<int> adj[n + 1];
// // //     while (k--)
// // //     {
// // //         addege(adj);
// // //     }
// // //     cout << detect(adj, n);
// // //     return 0;
// // // }

// // #include <iostream>
// // #include <bits/stdc++.h>
// // using namespace std;
// // bool cycle(vector<int> adj[], vector<int> &vis, int i, int v)
// // {
// //     queue<pair<int, int>> q;
// //     q.push({i, -1});
// //     vis[i] = 1;
// //     while (!q.empty())
// //     {
// //         int node = q.front().first;
// //         int par = q.front().second;
// //         q.pop();
// //         for (auto it : adj[node])
// //         {
// //             if (!vis[it])
// //             {
// //                 q.push({it, node});
// //                 vis[it] = 1;
// //             }
// //             else if (par != it)
// //             {
// //                 return true;
// //             }
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
// //             if (cycle(adj, vis, i, v))
// //             {
// //                 return true;
// //             }
// //         }
// //     }
// //     return false;
// // }
// // void edge(vector<int> adj[])
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
// //         edge(adj);
// //     }
// //     cout << detect(adj, n);
// //     return 0;
// // }
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// bool cycle(int i, vector<int> adj[], vector<int> vis)
// {
//     queue<pair<int, int>> q;
//     q.push({i, -1});
//     vis[i] = 1;
//     while (!q.empty())
//     {
//         int node = q.front().first;
//         int par = q.front().second;

//         q.pop();
//         for (auto it : adj[node])
//         {
//             if (!vis[it])
//             {
//                 q.push({it, node});
//                 vis[it] = 1;
//             }
//             else if (par != it)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// bool detect(vector<int> adj[], int v)
// {
//     vector<int> vis(v + 1, 0);
//     for (int i = 1; i <= v; i++)
//     {
//         if (!vis[i])
//         {
//             if (cycle(i, adj, vis))
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
bool check(vector<int> adj[], vector<int> vis, int i)
{
    queue<pair<int, int>> q;
    q.push({i, -1});
    vis[i] = 1;
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push({it, node});
                vis[it] = 1;
            }
            else if (par != it)
            {
                return true;
            }
        }
    }
    return false;
}
bool detect(vector<int> adj[], int n)
{
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (check(adj, vis, i))
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