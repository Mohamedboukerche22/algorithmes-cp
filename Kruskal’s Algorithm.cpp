#include <bits/stdc++.h>
using namespace std;
#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()
const int N = 2e5 + 1;

// Minimum Spanning Tree (MST) algorithm
// Kruskal’s Algorithm
// DSU algorithme
struct Edges
{
    int u, v, w;
    // weighted graph
};


class DSU
{
public:
    vector<int> parent, SZ;

    DSU(int n)
    {
        parent.resize(n);
        SZ.resize(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int v)
    {
        if (v != parent[v])
        {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }

    void Union(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (SZ[a] < SZ[b])
            {
                swap(a, b);
            }
            parent[b] = a;
            SZ[a] += SZ[b];
        }
    }
};


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<Edges> edges(m);
    for(auto &e : edges){
        cin >>e.u >> e.v >> e.w;
    }
    
    sort(edges.begin(),edges.end(),[](Edges &a , Edges &b){
        return a.w < b.w ;
    });

    DSU dsu(n+1);

    ll cost = 0;
    int nn = 0;
    for(auto &e : edges){
        if(dsu.find(e.u) != dsu.find(e.v)){
            dsu.Union(e.v,e.u);
            cost += e.w;
            nn++;
        }
    }
    if(nn !=n-1){
        cout <<"IMPOSSIBLE\n";

    }else{
        cout <<cost<<"\n";
    }
    /*
    test 
    in:
      4 4
      3 4 1
      1 2 2 
      2 4 3 
      1 3 4 
    
    out :
        6

      so output will be 6 which is correct 
    */


    // do something
}

int main()
{
    fastAOI;
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
