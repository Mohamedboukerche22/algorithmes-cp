#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];   
bool visited[N];       
// Depth-First Search algorithme
void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

// Breadth-First Search
void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
int main() {
    int n, m;
  // n =nodes
  //m =edges
    cin >> n >> m;
  
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // if undirected
    }

    cout << "DFS: ";
    dfs(1); 
    // or
    //dfs(0);
    for (int i = 0; i <= n; i++) visited[i] = false;

    cout << "\nBFS: ";
    bfs(1);

    return 0;
}
