/* C++ Program of undirected graph traversal, both Breadth-first search and Depth-first Search with a given starting node.
Given that the sequence of connection like this:
0 -> 1
0 -> 2
1 -> 3
1 -> 4
2 -> 4
The sequence of connection will run down from top to bottom. That is, node 1 will connect to node 3 before connecting to node 4
After that we will provide a starting node, For example if we start at node 0, the sequence of Depth-first search will be: 0 1 3 4 2 and sequence of Breadth-first search traversal will be: 0 1 2 3 4
Your task is to determine the sequence of both traversal

Input
The input consists of several lines
First Line:
An integer n determine the number of edges.
Next n line:
The pair of connected vertex.
Final line:
An integer
x states the starting node.

Output
The output consists of two lines
First line:
A sequence of Depth-first search traversal.
Second line:
A sequence of Breadth-first search traversal.

Example of input and output
Input
5
0 1
0 2
1 3
1 4
2 4
0

Output
0 1 3 4 2
0 1 2 3 4

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<vector<int>> &adj, int u, int v)
{
  adj[u].push_back(v);
  adj[v].push_back(u); // Since it's undirected graph
}

// Depth First Search (DFS) traversal
void DFSUtil(vector<vector<int>> &adj, int v, vector<bool> &visited)
{
  visited[v] = true;
  cout << v << " ";

  // Recur for all the vertices adjacent to this vertex
  for (int i = 0; i < adj[v].size(); ++i)
  {
    int neighbor = adj[v][i];
    if (!visited[neighbor])
    {
      DFSUtil(adj, neighbor, visited);
    }
  }
}

// DFS traversal of the graph
void DFS(vector<vector<int>> &adj, int v)
{
  vector<bool> visited(adj.size(), false);

  // Mark the current node as visited and print it
  DFSUtil(adj, v, visited);
}

// Breadth First Search (BFS) traversal
void BFS(vector<vector<int>> &adj, int v)
{
  vector<bool> visited(adj.size(), false);
  queue<int> q;

  // Mark the current node as visited and enqueue it
  visited[v] = true;
  q.push(v);

  while (!q.empty())
  {
    v = q.front();
    q.pop();
    cout << v << " ";

    // Explore all adjacent nodes
    for (int i = 0; i < adj[v].size(); ++i)
    {
      int neighbor = adj[v][i];
      if (!visited[neighbor])
      {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<vector<int>> adj(n); // Adjacency list representation

  // Read edge connections
  for (int i = 0; i < n; i++)
  {
    int u, v;
    cin >> u >> v;
    addEdge(adj, u, v);
  }

  int startingNode;
  cin >> startingNode;

  // DFS
  DFS(adj, startingNode);
  cout << endl;

  // BFS
  BFS(adj, startingNode);
  cout << endl;

  return 0;
}
