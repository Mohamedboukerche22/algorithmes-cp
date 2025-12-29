#include <bits/stdc++.h>
using namespace std;
#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()
const int N = 2e5 +1;
 
// opitimized version 
// Path Compression
// Union by Size

int parent[N], SZ[N];

void make_set(int v){
    parent[v] = v;
    SZ[v] = 1;
}

int find(int v){
    if(v != parent[v]){
        parent[v] = find(parent[v]);
    }
    return parent[v];
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b){
        if(SZ[a] < SZ[b]){
            swap(a,b); 
        }
        parent[b] = a;
        SZ[a] += SZ[b];
    }


}

void solve(){
       int n,m;
       cin >> n>>m;
       vector<vector<int>>adj(m+1);
       for(int i = 0 ; i< n ;i++){
        int u,v;
        cin >>u >>v;
        adj[u].pb(v);
        adj[u].pb(v);
       }
       int a,b;
       cin >>a >>b;
       Union(a,b);
       // do something
      
 
}
 
int main() {
    fastAOI;
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
