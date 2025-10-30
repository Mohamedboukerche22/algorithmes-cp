#include <bits/stdc++.h>
using namespace std;

#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

int lis1(vector<int>& arr){
    // so fu**ing slow O(n^2)
    int n = arr.size();
    vector<int>dp(n+1,1);
    for(int i = 0 ; i< n ;i++){
        for(int j = 0 ; j< i ;j++){
            if(arr[i]>arr[j]){
              dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    return *max_element(all(dp));
}

int lis(vector<int>&arr){
    // the fastest O(n log n)
    int n = sz(arr);
    vector<int>tt;

    for(int i : arr){
        auto it = lower_bound(all(tt),i);
        if(it == tt.end()){
            tt.push_back(i);
        }else{
            *it = i;
        }
    }
    return sz(tt);

}

int main() {
    fastAOI;
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >>n;
        vector<int>arr(n);
        for(int &i :arr){
            cin >>i;
        }
        cout<<lis(arr);
    }
    return 0;
}
