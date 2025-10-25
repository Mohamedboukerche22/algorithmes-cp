
/* 
** Bellman–Ford
** point : finding the shortest path with negative weigth
** time Complexity O(V * E)
*/
#include <bits/stdc++.h>
using namespace std;

#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()
const int INF = 1e9;
struct Edge{
  int u,v;
  int w;
};
int main() {
    fastAOI;
    int v,e;
    cin >> v >> e;
    vector<Edge> edges(e);
    

    for(int i = 0; i < e ;i++){
      cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    int src;
    cin >> src;

    vector<int> dist(v,INF) , parent(v,-1);
    dist[src] = 0;
     
    for(int i = 0 ; i< v ;i++){
      bool cc = false;
      for(auto &edge : edges){
        if(dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]){
          dist[edge.v] = dist[edge.u] + edge.w ;
          parent[edge.v] = edge.u;
          cc = true;
        }
      }
      if(!cc){
        break;
      }
    }
    for(auto &e : edges){
      if(dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]){
        cout <<"negative circle\n";
      }
    }
    int target; cin >>target;

      if(dist[target] == INF){
        cout <<"-1\n";
        return 0;
      }
      vector<int>path;
      for(int cur = target ; cur != -1 ;cur = parent[cur]){
        path.pb(cur);
      }
      reverse(all(path));
      for(int j = 0 ; j < sz(path) ;j++){
        cout << path[j]<<" ";
      }
    
    return 0;
}
