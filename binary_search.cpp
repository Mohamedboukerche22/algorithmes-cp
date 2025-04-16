#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin >>n;
vector<int> lol(n);
for(int i=0; i<n; i++){
    cin >> lol[i];
}
int left =0,right = n-1,target = 15;
while(left<=right){
    int mid = (right+left)/2;
    if(lol[mid]==target){
        cout << mid;
        return 0; 
    }
    else if(lol[mid]<target){
        left =mid + 1; 
    }
    else if(lol[mid]>target){
        right = mid -1;
    }
    
}

}
    
