#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5; 

int parent[N];  int rank_[N];  

void make_set(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank_[i] = 0;
    }
}

int find(int u) {
    if (u != parent[u])
        parent[u] = find(parent[u]);
    return parent[u];
}

void union_sets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        // Union by rank
        if (rank_[root_u] < rank_[root_v]) {
            parent[root_u] = root_v;
        } else if (rank_[root_u] > rank_[root_v]) {
            parent[root_v] = root_u;
        } else {
            parent[root_v] = root_u;
            rank_[root_u]++;
        }
    }
}


int main() {
    int n ; 
    cin >>n;
    make_set(n);

  /*  union_sets(1, 2);
    union_sets(3, 4);
    union_sets(2, 3);*/
    

    // Check if 1 and 4 are connected
    if (find(1) == find(4))
        cout << "1 and 4 are in the same set\n";
    else
        cout << "1 and 4 are in different sets\n";

    return 0;
}
