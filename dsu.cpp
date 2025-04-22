#include<bits/stdc++.h>
using namespace std;
class DSU {
private:
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);  
        }
        return parent[u];
    }
    void union_sets(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        
        if (root_u != root_v) {
            if (size[root_u] < size[root_v]) {
                swap(root_u, root_v);
            }
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }
    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

int main() {
    int n = 10; 
    DSU dsu(n);

    dsu.union_sets(1, 2);
    dsu.union_sets(2, 3);
    dsu.union_sets(4, 5);

    cout << "1 and 3 are connected: " << (dsu.connected(1, 3) ? "Yes" : "No") << endl;
    cout << "1 and 4 are connected: " << (dsu.connected(1, 4) ? "Yes" : "No") << endl;

    return 0;
}
