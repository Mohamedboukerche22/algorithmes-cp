#include<bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
#define Algerian ios::sync_with_stdio(0);
#define OI cin.tie(NULL);
vector<long long>dp(1e7,0);
/*int f(int n){
    if(n==0)return n;
    else if(n==1)return n;
    else {
        return f(n-2)+f(n-1);
    }
}*/
int main(){
    Algerian OI
    dp[0]= 0;dp[1]=1;
    int n;
    cin >>n;
    //cout <<f(n);
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout <<dp[n]%MOD;
    return 0;
}
