#include <bits/stdc++.h>
using namespace std;

#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()
const int N = 2e5 +1;
//const int LOG = 31;
const int LOG = 18;
vector<vector<int>>anc(N,vector<int>(LOG));
vector<int>lvl(N , 0);

int k_th(int a,int b){
    for(int i = 0 ; i< LOG;i++){
        if((b >> i ) & 1){
            a = anc[a][i];
        }
    }
    return a;
}
int LCA(int a,int b){
    if(lvl[a] > lvl[b]){
        swap(a,b);
    }
    b = k_th(b,lvl[b] - lvl[a]);
    if(a == b){
        return a;
    }
    else{
        for(int i = LOG-1;i >=0 ;i--){
            if(anc[a][i] != anc[b][i]){
                a = anc[a][i];
                b = anc[b][i];
            }
        }
        return anc[a][0];
    }
}

int main() {
    fastAOI;
    int t = 1;
    while (t--) {
        int n,q;
        cin >> n >>q;
        vector<vector<int>>adj(n+1);
        /*for(int i = 2;i<=n;i++){
            int a;
            cin >> a;
            anc[i][0] = a;
            lvl[i] = lvl[a] + 1;
        }*/


        for(int i = 0 ; i< n-1 ;i++){
            int u ,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //bfs algo 
        queue<int>qu;
        qu.push(1);
        anc[1][0] = 1;
        vector<bool>visited(n+1,0);
        visited[1] = 1;
        while(!qu.empty()){
            int v = qu.front();
            qu.pop();
            for(int u : adj[v]){
                if(!visited[u]){
                    visited[u] = true;
                    lvl[u] =  lvl[v] + 1;
                    anc[u][0] = v;
                    qu.push(u);
                }
            }
        }

        for(int i = 1;i<LOG;i++){
            for(int j = 1 ; j<= n;j++){
                anc[j][i] = anc[anc[j][i-1]][i-1];
            }
        }
        while(q--){
            int a , b;
            cin >> a >>b;
            //cout<<LCA(a,b)<<"\n";
            cout<<lvl[a]+lvl[b]-(2*lvl[LCA(a,b)])<<"\n";
        }
        
    }
    return 0;
}
