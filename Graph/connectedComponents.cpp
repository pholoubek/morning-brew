#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'componentsInGraph' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY gb as parameter.
 */

/*
	There are  nodes in an undirected graph, and a number of edges
	connecting some nodes. In each edge, the first value will be between  and , i
	nclusive. The second node will be between  and , inclusive. Given a list of edges,
	determine the size of the smallest and largest connected components that have  or more nodes.
	A node can have any number of connections. The highest node value will always be connected to at
	least  other node.
*/

// trick is to use DFS algo and count how many nodes we will visit
void DFS(int n, vector<vector<int>> *graph, vector<bool> *visited, int *ans)
{
	(*visited)[n] = true;
	(*ans)++;

	for (auto i : (*graph)[n])
	{
		if ((*visited)[i] == false)
		{
			DFS(i, graph, visited, ans);
		}
	}
}

vector<int> componentsInGraph(vector<vector<int>> gb, int N)
{
	vector<vector<int>> graph(N * 2 + 1, vector<int>(0));
	vector<bool> visited(N * 2 + 1, false);
	vector<int> results(2);

	// this is to construct the graph from provided edges between nodes
	for (int i = 0; i < N; i++)
	{
		int j = gb[i][0];
		int k = gb[i][1];
		graph[j].push_back(k);
		graph[k].push_back(j);
	}

	// for proper intialization we set "nonsense" values
	int min = 100000;
	int max = -100000;
	for (auto i : graph)
	{
		int ans = 0;
		for (int j : i)
		{
			if (visited[j] == false)
			{
				DFS(j, &graph, &visited, &ans);
			}
		}

		// task asks for min and max num of connected nodes in the graph
		if (ans > max)
			max = ans;

		if (ans < min && ans > 0)
			min = ans;
	}

	results[0] = min;
	results[1] = max;
	return results;
}