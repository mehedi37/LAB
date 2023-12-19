#include <bits/stdc++.h>
using namespace std;

class Tree {
 public:
  int V;                       // Number of vertices
  vector<vector<int>> adj;    // Adjacency list

  Tree(int vertices) : V(vertices), adj(vertices) {}

  void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // Greedy algorithm for tree vertex splitting
  int greedySplit() {
    int root = findCentroid();
    return root;
  }

 private:
  // Find the centroid of the tree
  int findCentroid() {
    vector<int> subtreeSizes(V, 0);
    vector<bool> visited(V, false);

    // Perform a depth-first search to compute subtree sizes
    dfs(0, subtreeSizes, visited);

    // Find the centroid
    int centroid = 0;
    int minSubtreeSize = V;
    for (int i = 0; i < V; ++i) {
      int subtreeSize = V - subtreeSizes[i];
      for (int neighbor : adj[i]) {
        subtreeSize = max(subtreeSize, subtreeSizes[neighbor]);
      }

      if (subtreeSize < minSubtreeSize) {
        minSubtreeSize = subtreeSize;
        centroid = i;
      }
    }
    return centroid;
  }

  // Depth-first search to compute subtree sizes
  int dfs(int node, vector<int> &subtreeSizes, vector<bool> &visited) {
    visited[node] = true;
    subtreeSizes[node] = 1;

    for (int neighbor : adj[node]) {
      if (!visited[neighbor]) {
        subtreeSizes[node] += dfs(neighbor, subtreeSizes, visited);
      }
    }

    return subtreeSizes[node];
  }
};

int main() {
  ifstream inputFile("tvs.txt");
  if (!inputFile.is_open()) {
    cerr << "Error opening file 'tvs.txt'" << endl;
    return 1;
  }

  vector<pair<int, int>> edges;     // Store edges in a vector
  int vertices, u, v;


  while (!inputFile.eof()) {
    inputFile >> u >> v;
    edges.emplace_back(u, v);       // Store the edges
  }
  vertices = edges.size() + 1;   // +1  because the vertices are numbered from 1 to n, not from 0 to n-1

  inputFile.close();

  Tree tree(vertices);

  // Add edges to the tree
  for (const auto &edge : edges) {
    tree.addEdge(edge.first, edge.second);
  }

  // Process the single graph
  int root = tree.greedySplit();
  cout << "Root of split tree: " << root << endl;

  return 0;
}
