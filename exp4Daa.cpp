#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class TSP
{
private:
	int n;					  // Number of cities
	vector<vector<int>> dist; // Distance matrix
	int minCost = INT_MAX;	  // Minimum cost found
	vector<int> bestPath;	  // Best path found
	// Helper function to calculate the lower bound (minimum cost estimate) for a partial path
	int calculateLowerBound(const vector<int> &path, const vector<bool> &visited)
	{
		int bound = 0;
		for (int i = 0; i < n; ++i)
		{
			if (visited[i])
			{
				int minEdge = INT_MAX;
				for (int j = 0; j < n; ++j)
				{
					if (i != j && !visited[j])
					{
						minEdge = min(minEdge, dist[i][j]);
					}
				}
				bound += minEdge;
			}
		}
		return bound;
	}
	// Recursive function to explore paths using Branch and Bound
	void branchAndBoundUtil(vector<int> &path, vector<bool> &visited, int currentCost, int level)
	{
		if (level == n)
		{
			int totalCost = currentCost + dist[path[level - 1]][path[0]];
			if (totalCost < minCost)
			{
				minCost = totalCost;
				bestPath = path;
				bestPath.push_back(path[0]); // Complete the cycle
			}
			return;
		}
		for (int i = 0; i < n; ++i)
		{
			if (!visited[i])
			{
				path.push_back(i);
				visited[i] = true;
				int lowerBound = calculateLowerBound(path, visited);
				if (currentCost + lowerBound < minCost)
				{
					branchAndBoundUtil(path, visited, currentCost + dist[path[level - 1]][i], level + 1);
				}
				visited[i] = false;
				path.pop_back();
			}
		}
	}

public:
	TSP(int cities, const vector<vector<int>> &distance) : n(cities), dist(distance) {}
	void solve()
	{
		vector<int> path = {0}; // Start from city 0
		vector<bool> visited(n, false);
		visited[0] = true;
		branchAndBoundUtil(path, visited, 0, 1);
	}
	void printSolution()
	{
		cout << "Minimum Cost: " << minCost << endl;
		cout << "Optimal Path: ";
		for (int city : bestPath)
		{
			cout << city << " ";
		}
		cout << endl;
	}
};
int main()
{
	int n;
	cout << "Anurag Kanhed\n";
	cout << "307A028\n";
	cout << "72307409H\n";
	cout << "Enter the number of cities: ";
	cin >> n;
	vector<vector<int>> dist(n, vector<int>(n));
	cout << "Enter the distance matrix:" << endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> dist[i][j];
		}
	}
	TSP tsp(n, dist);
	tsp.solve();
	tsp.printSolution();
	return 0;
}
