// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// class disjointset
// {
// 	vector<int> parent, rank, size;

// public:
// 	disjointset(int n)
// 	{
// 		rank.resize(n + 1, 0);
// 		size.resize(n + 1);
// 		parent.resize(n + 1);
// 		for (int i = 0; i <= n; i++)
// 		{
// 			size[i] = 1;
// 			parent[i] = i;
// 		}
// 	}
// 	int findUparent(int node)
// 	{
// 		if (node = parent[node])
// 		{
// 			return node;
// 		}
// 		return parent[node] = findUparent(parent[node]);
// 	}

// 	void unionbyrank(int u, int v)
// 	{
// 		int ulp_u = findUparent(u);
// 		int ulp_v = findUparent(v);
// 		if (ulp_u == ulp_v)
// 		{
// 			return;
// 		}
// 		if (rank[ulp_u] < rank[ulp_v])
// 		{
// 			parent[ulp_u] = ulp_v;
// 		}
// 		else if (rank[ulp_u] > rank[ulp_v])
// 		{
// 			parent[ulp_v] = ulp_u;
// 		}
// 		else
// 		{
// 			parent[ulp_v] = ulp_u;
// 			rank[ulp_u]++;
// 		}
// 	}
// };
// int main()
// {
// 	disjointset ds(7);
// 	ds.unionbyrank(1, 2);
// 	ds.unionbyrank(2, 3);
// 	ds.unionbyrank(4, 5);
// 	ds.unionbyrank(6, 7);
// 	ds.unionbyrank(5, 6);
// 	if (ds.findUparent(3) == ds.findUparent(7))
// 	{
// 		cout << "same\n";
// 	}
// 	else
// 	{
// 		cout << "not same\n";
// 	}
// 	ds.unionbyrank(3, 7);
// 	if (ds.findUparent(3) == ds.findUparent(7))
// 	{
// 		cout << "same\n";
// 	}
// 	else
// 	{
// 		cout << "not same\n";
// 	}
// 	return 0;
// }
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class disjointset
{
	vector<int> rank, parent;

public:
	disjointset(int n)
	{
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		for (int i = 0; i <= n; i++)
		{
			parent[i] = i;
		}
	}
	int findUparent(int node)
	{
		if (parent[node] == node)
		{
			return node;
		}
		return parent[node] = findUparent(parent[node]);
	}
	void unionbyrank(int u, int v)
	{
		int ulp_u = findUparent(u);
		int ulp_v = findUparent(v);
		if (parent[ulp_u] == parent[ulp_v])
		{
			return;
		}
		if (rank[ulp_u] < rank[ulp_v])
		{
			parent[ulp_u] = ulp_v;
		}
		else if (rank[ulp_u] > rank[ulp_v])
		{
			parent[ulp_v] = ulp_u;
		}
		else
		{
			parent[ulp_v] = ulp_u;
			rank[ulp_u] += rank[ulp_v] + 1;
		}
	}
	void print()
	{
		cout << "parent= ";
		for (int i = 0; i <= 7; i++)
		{
			cout << parent[i] << " ";
		}
		cout << "\n";
		cout << "rank= ";
		for (int i = 0; i <= 7; i++)
		{
			cout << rank[i] << " ";
		}
		cout << "\n";
	}
};
int main()
{
	disjointset ds(7);
	ds.unionbyrank(1, 2);
	ds.unionbyrank(2, 3);
	ds.unionbyrank(4, 5);
	ds.unionbyrank(6, 7);
	ds.unionbyrank(5, 6);
	if (ds.findUparent(3) == ds.findUparent(7))
	{
		cout << "Same\n";
	}
	else
	{
		cout << "Not Same\n";
	}
	ds.unionbyrank(3, 7);
	if (ds.findUparent(3) == ds.findUparent(7))
	{
		cout << " Same\n";
	}
	else
	{
		cout << "Not Same\n";
	}
	ds.print();
	return 0;
}