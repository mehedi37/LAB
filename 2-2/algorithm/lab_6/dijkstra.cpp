#include <bits/stdc++.h>
using namespace std;

class Graph {
  map<string, vector<pair<string, int>>> adj;

 public:
  void addEdge(string u, string v, int w) {
    if (w != 0) {
      adj[u].push_back({v, w});
      // adj[v].push_back({u, w});
    }
  }

  void shortestPath(string src) {
    map<string, int> dist;
    for (auto &node : adj) {
      dist[node.first] = INT_MAX;
    }
    dist[src] = 0;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
      string u = pq.top().second;
      pq.pop();

      for (auto &edge : adj[u]) {
        string v = edge.first;
        int weight = edge.second;
        if (dist[v] > dist[u] + weight) {
          dist[v] = dist[u] + weight;
          pq.push({dist[v], v});
        }
      }
    }

    cout << "Vertex - \tDistance from Source\n";
    int sum{0};
    for (auto &node : dist) {
      cout << src << "->" << node.first << " \t\t " << node.second << "\n";
      sum += node.second;
    }
  }
};


int main() {
  ifstream input("dijkstra.txt");
  if (!input) {
    cerr << "Unable to open file dijkstra.txt";
    exit(1);
  }

  string line;
  getline(input, line);  // Read the first line with the node names
  istringstream iss(line);
  string nodeName;
  vector<string> nodeNames;
  while (iss >> nodeName) {
    nodeNames.push_back(nodeName);
  }

  // for (auto a: nodeNames) cout << a << " ";
  // cout << endl;

  vector<vector<int>> matrix;
  int value;
  while (getline(input, line)) {
    istringstream iss(line);
    vector<int> row;
    while (iss >> value) {
      row.push_back(value);
    }
    matrix.push_back(row);
  }

  Graph g;

  for (int i = 0; i < nodeNames.size(); ++i) {
    for (int j = 0; j < nodeNames.size(); ++j) {
      g.addEdge(nodeNames[i], nodeNames[j], matrix[i][j]);
    }
  }

  g.shortestPath("S");  // Assuming "S" is the source node

  return 0;
}
