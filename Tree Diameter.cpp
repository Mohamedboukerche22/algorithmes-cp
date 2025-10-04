#include <bits/stdc++.h>
using namespace std;

#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()


pair<int,int> dfs(int start,vector<vector<int>>&graph){
  int n = graph.size();
  vector<int>dist(n,-1);
  queue<int>q;
  q.push(start);
  dist[start] = 0;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(auto u : graph[v]){
      if(dist[u] == -1){
        dist[u] = dist[v] +1;
        q.push(u);
      }
    }
  }
  int far = start;
  for(int i = 0 ; i< n ;i++){
    if(dist[i]>dist[far]){
      far = i;
    }
  }
  return {far,dist[far]};
}
int main() {
    fastAOI;
    int t = 1;
    // cin >> t;
    while (t--) {
       int n;
       cin >>n;
       vector<vector<int>>graph(n+1);
       for(int i = 0 ; i< n-1 ;i++){
        int u,v;
        cin >>u >>v;
        graph[u].pb(v);
        graph[v].pb(u);
       }
       auto first = dfs(1,graph);
       auto second = dfs(first.first , graph);
       cout << second.second;
    }
    return 0;
}
