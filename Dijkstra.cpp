#include <bits/stdc++.h>
using namespace std;

#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()


const ll INF = 1e18;
int main() {
    fastAOI;
    int t = 1;
    // cin >> t;
    while (t--) {
        ll n,m;
        cin >>n >>m;
        vector<vector<pair<ll,ll>>>adj(n+1);
        for(int i = 0 ;i<m;i++){
            ll a,b,w;
            cin >>a>>b>>w;
            adj[a].push_back({b,w});
            // this if it undirrected adj[b].push_back({a,w});
        }
        vector<ll>dist(n+1,INF);
       priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;


        dist[1] = 0;
        pq.push({0,1});
        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();
            if(d != dist[u])continue;
            for(auto [v,w] :adj[u]){
                if(dist[u]+w<dist[v]){
                    dist[v] =dist[u]+w;
                    pq.push({dist[v], v});
                }
            }
        }
           for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    }

    return 0;
}
