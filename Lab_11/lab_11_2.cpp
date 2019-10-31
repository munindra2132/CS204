#include <bits/stdc++.h>

using namespace std;


struct Edge {
	int src, dest;
};


class Graph
{
public:
	vector<vector<int>> adjList;
  Graph(vector<Edge> const &edges, int N)
	{
		adjList.resize(N);
        for (auto &edge: edges)
		{
			adjList[edge.src].push_back(edge.dest);
			adjList[edge.dest].push_back(edge.src);
		}
	}
};


bool DFS(Graph const &graph, int v, vector<bool> &discovered,vector<int> &color)
{
	for (int u : graph.adjList[v])
	{
		if (!discovered[u])
		{   discovered[u] = true;
            color[u] = !color[v];

			if (!DFS(graph, u, discovered, color))
				return false;
		}
		else if (color[v] == color[u]) {
			return false;
		}
	}

	return true;
}


int main()
{
	int n, m;
	cin >> n >> m;
	int j = n + 1;
	vector<Edge> edges;
	for (int i = 0; i < m; i++)
	{
		int l,k,w;
		cin >>l>> k >> w;
		if (!w % 2)
		{
			Edge a, b;
			a.src = l;
			a.dest = j;
			b.src = j;
			b.dest = k;
			j++;
			edges.push_back(a);
			edges.push_back(b);
	
		}
		else
		{
			Edge a;
			a.src = l;
			a.dest = k;
      edges.push_back(a);
		}
	 }
	Graph graph(edges, j);
	vector<bool> discovered(j);
	vector<int> color(j);
	discovered[0] = true, color[0] = 0;
	if (DFS(graph, 1, discovered, color))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
