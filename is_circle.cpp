//using bfs checking if graph is a circle 
#include <bits/stdc++.h>
using namespace std;

#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

bool is_circle(int n, vector<vector<int>>&adj){
  vector<int>visited(n,0);
  for(int i = 0 ; i< n ;i++){
    if(!visited[i]){
      queue<pair<int,int>>q;
      q.push({i,-1});
      visited[i] = 1;
      while(!q.empty()){

        pair<int,int> pii = q.front();

        int u = pii.first;
        int parent = pii.second;
        q.pop();
        for(int v : adj[u]){
          if(!visited[v]){
            visited[v] = 1;
            q.push({v,u});
          }
          else if (v != parent){
            return true;
          }
        }
      }
    }
  }
  return false;
}

int main() {
    fastAOI;
    int t = 1;
    while (t--) 
    {
      int n,e;
      cin >>n >>e;
      vector<vector<int>>adj(n+2);
      for(int i = 0 ; i< e ;i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
      }
      if(is_circle(n,adj)){
        cout <<"YES";
      }
      else{
        cout <<"NO";
      }
       
    }
    return 0;
}
