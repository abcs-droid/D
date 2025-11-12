#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class BellmanFord
{
private:
	int V;					   // Number of vertices
	vector<vector<int>> edges; // Store edges as {u, v, weight}
public:
	BellmanFord(int vertices)
	{
		V = vertices;
	}

	// Function to add an edge to the graph
	void addEdge(int u, int v, int weight)
	{
		edges.push_back({u, v, weight});
	}

	// Bellman-Ford Algorithm to find shortest paths
	vector<int> bellmanFord(int src)
	{
		// Initialize distances from src to all vertices as INFINITE
		vector<int> dist(V, INT_MAX);
		dist[src] = 0; // Distance from source to itself is 0
		// Relax all edges |V| - 1 times
		for (int i = 1; i <= V - 1; ++i)
		{
			for (auto edge : edges)
			{
				int u = edge[0];
				int v = edge[1];
				int weight = edge[2];
				if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				{
					dist[v] = dist[u] + weight;
				}
			}
		}
		// Check for negative weight cycles
		for (auto edge : edges)
		{
			int u = edge[0];
			int v = edge[1];
			int weight = edge[2];
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
			{
				cout << "Graph contains negative weight cycle" << endl;
				return {}; // Return empty if cycle is detected
			}
		}
		return dist; // Return the shortest distances
	}
	// Function to print the shortest distances from the source
	void printShortestPaths(vector<int> dist, int src)
	{
		cout << "Shortest distances from vertex " << src << ":" << endl;
		for (int i = 0; i < V; ++i)
		{
			if (dist[i] == INT_MAX)
			{
				cout << "INF ";
			}
			else
			{
				cout << dist[i] << " ";
			}
		}
		cout << endl;
	}
};
int main()
{
	int V, E;
	cout << "Enter the number of vertices: ";
	cin >> V;
	cout << "Enter the number of edges: ";
	cin >> E;
	BellmanFord graph(V);
	cout << "Enter the edges (u, v, weight): " << endl;
	for (int i = 0; i < E; ++i)
	{
		int u, v, weight;
		cin >> u >> v >> weight;
		graph.addEdge(u, v, weight);
	}
	int source;
	cout << "Enter the source vertex: ";
	cin >> source;
	vector<int> dist = graph.bellmanFord(source);
	if (!dist.empty())
	{
		graph.printShortestPaths(dist, source);
	}
	return 0;
}
