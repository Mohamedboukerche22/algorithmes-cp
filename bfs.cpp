#include <bits/stdc++.h>
using namespace std;
// bfs algorithm  => finding the shotest path between start node and target node ;

#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

int main() {
    fastAOI;
    int t = 1;
      while (t--) {
        int n,e;
        cin >> n >>e;
        vector<vector<int>>adj(n+5);
        for(int i = 0 ; i<  e ;i++){
          int u,v;
          cin >> u >>v;
          adj[u].push_back(v);
          adj[v].push_back(u);

        }
        int start ,target;
        cin >> start >> target;
        vector<int>dist(n+1,-1),parents(n+1,-1);
        dist[start] = 0;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
          int node = q.front();
          q.pop();
          for(int u : adj[node]){
            if(dist[u] == - 1){
              dist[u] = dist[node] + 1;
              parents[u] = node;
              q.push(u);
            }
          }
        }
        if(dist[target] == -1){
          cout <<"NO PATH FROM HERE ";
        }
        else{
          cout <<"PATH : "<<dist[target]<<"\n";
          vector<int>path;
          for(int v = target; v!=-1; v = parents[v]){
           path.pb(v);
          }
          reverse(path.begin(),path.end());
          for(int i : path){
            cout <<i<<" ";
          }
          cout <<endl;
        }

      }
    return 0;
}
