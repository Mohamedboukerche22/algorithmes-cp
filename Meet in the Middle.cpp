#include <bits/stdc++.h>
using namespace std;

#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

int main() {
    fastAOI;
    int t = 1;
    // cin >> t;
    while (t--) {
       int s,n;
       cin >>n >>s;
       vector<int>a(n);
       for(int &i:a){
        cin >>i;
       }
       int mid = n/2;

       vector<ll>l,r;

       // half n°1:
       for(int mask = 0 ; mask < (1 << mid);mask++){
        ll sum = 0;
        for(int i = 0 ; i < mid;i++){
          if(mask & (1 << i)){
            sum += a[i];
          }
          
        }l.pb(sum);
       }

       //half n°2
       for(int mask = 0 ; mask < (1 << (n-mid));mask++){
        ll sum = 0;
        for(int i = 0 ; i < (n-mid);i++){
          if(mask & (1 << i)){
            sum += a[mid + i];
          }
          
        }r.pb(sum);
       }

       sort(all(r));
       ll ans = 0;
       for(ll x:l){
         ll remain = s-x;
          auto range = equal_range(all(r),remain);
          ans += (range.second - range.first);
       }
       cout<<ans<<"\n";

    }
    return 0;
}
