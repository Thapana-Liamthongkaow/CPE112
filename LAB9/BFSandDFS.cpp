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
