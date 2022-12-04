// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> bfstopo(int n, vector<int> adj[])
// {
//     vector<int> indegree(n);
//     for (int i = 0; i < n; i++)
//     {
//         for (auto it : adj[i])
//         {
//             indegree[it]++;
//         }
//     }
//     queue<int> q;
//     vector<int> topo;

//     for (int i = 0; i < n; i++)
//     {
//         if (indegree[i] == 0)
//         {
//             q.push(i);
//         }
//     }
//     while (!q.empty())
//     {
//         int cur = q.front();
//         q.pop();
//         topo.push_back(cur);
//         for (auto it : adj[cur])
//         {
//             indegree[it]--;
//             if (indegree[it] == 0)
//             {
//                 q.push(it);
//             }
//         }
//     }
//     return topo;
// }

// void addedge(vector<int> adj[], int u, int v)
// {
//     // int u, v;
//     adj[u].push_back(v);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> adj[n + 1];
//     addedge(adj, 5, 0);
//     addedge(adj, 5, 2);
//     addedge(adj, 2, 3);
//     addedge(adj, 4, 3);
//     addedge(adj, 1, 4);
//     addedge(adj, 1, 0);
//     vector<int> ans = bfstopo(n, adj);
//     for (auto it : ans)
//     {
//         cout << it << " ";
//     }
//     return 0;
// }

// Basically to have a topological sort the graph should be directed acylic graph so that here we are using the property of DAG
// that at least one element in DAG have indegree == 0;
// Intution -> here we push the element having the indegree 0, and traverse through its adjecent nodes if that node having the indegree grater
// than 0 then we siply reduce it by one and if it have 0 indegree we add it to the queue. Here we are implicitly reducing the dependency
// factor of the node by reducing the indegree that means we have reduced one source of the node from where the edge is coming so after it
// become 0 we directly take it into our topo sort.
// this is nothing but Kahn's algorithm

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    vector<int> topo(vector<int> adj[], int n)
    {
        vector<int> indegree(n);
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        vector<int> topo;
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            topo.push_back(cur);
            for (auto it : adj[cur])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return topo;
    }
};
void addedge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}
int main()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    addedge(adj, 0, 1);
    addedge(adj, 2, 1);
    // addedge(adj, 2, 3);
    // addedge(adj, 2, 4);
    // addedge(adj, 4, 3);
    // addedge(adj, 1, 0);
    solution sol;
    vector<int> ans;
    ans = sol.topo(adj, n);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}