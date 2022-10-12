// constuct graph using adjecency matrix
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int adj[n + 1][n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			adj[i][j] = 0;
		}
	}
	int m;
	cin >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}
	// cout << adj[0][1];
	return 0;
}