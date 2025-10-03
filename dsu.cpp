#include <bits/stdc++.h>
using namespace std;

#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

int parent[100005];
int find(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}
void unions(int a,int b){
    a = find(a);
    b = find(b);
    if(a != b)parent[b] = a;
}
int main() {
    fastAOI;
    int t = 1;
    // cin >> t;
    while (t--) {
       int n,m;
       cin >> n>>m;
       for(int i = 1 ; i<n+1;i++){
        parent[i] = i;
       }
       for(int i = 0 ; i< m ;i++){
        int a,b;
        cin >>a>>b;
        unions(a,b);
       }
       int count = 0;
       for(int i = 1;i<=n;i++){
        if(find(i) == i)count++;
       }
       cout<<count;
    }
    return 0;
}
