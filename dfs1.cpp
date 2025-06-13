#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int goal = 5;
bool found = false;
vector<int> adj[N];   
bool visited[N];       
// Depth-First Search algorithme
void dfs(int node) {
    if(found)
    {
        return;
    }
    visited[node] = true;
    cout << node << " ";
    if(node == goal){
               found = true;
               return;
    }

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            
            dfs(neighbor);
        }
 
   }
}
int main() {
    int  m;
    cin  >> m;
  
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    dfs(1); 

    return 0;
}
