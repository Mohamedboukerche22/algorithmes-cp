#include<bits/stdc++.h>
using namespace std;
void sieve(int n) {
 vector<bool>check(n+1,true);
 vector<int>num(n+1);
check[0]=check[1]=1;
for(int i=2;i*i<=n;++i){
    if(check[i]==true){
        for(int j=i*i;j<=n;j+=i){
            check[j] = false;
        }
    }
}
for(int i=2;i<n;i++){
    if(check[i]){
        cout <<i<<" ";
    }
}
}
int main(){
    int n;
    cin >>n;
    sieve(n);
 }
