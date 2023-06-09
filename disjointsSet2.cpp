#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class disjoint
{

public:
    vector<int> rank, parent;

    disjoint(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int node)
    {
        if (parent[node] = node)
        {
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    void unionby(int u, int v)
    {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_v == ulp_u)
        {
            return;
        }
        else if (rank[ulp_u] < rank[ulp_v])
        {
            parent[u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[v] = ulp_u;
        }
        else
        {
            parent[v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void print()
    {
        cout << "parent= ";
        for (int i = 0; i <= 6; i++)
        {
            cout << parent[i] << " ";
        }
        cout << endl;
        cout << "rank= ";
        for (int i = 0; i <= 6; i++)
        {
            cout << rank[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    disjoint ds(6);
    ds.unionby(1, 2);
    ds.unionby(2, 3);
    ds.unionby(4, 5);
    ds.unionby(5, 6);
    if (ds.find(1) == ds.find(4))
    {
        cout << "same\n";
    }
    else
    {
        cout << "not same\n";
    }
    ds.unionby(3, 4);
    if (ds.find(3) == ds.find(4))
    {
        cout << "same\n";
    }
    else
    {
        cout << "not same\n";
    }
    ds.find(6);
    ds.print();
    return 0;
}