#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
public:

    void mergesort(vector<int>& arr, int l, int r){
       if(l  >= r){
         return ;
       }
       int m = (l + r)/2;

       vector<int>right,left;
       for (int i = l ; i <= m ; i++){
         left.push_back(arr[i]);
       }
       for(int i = m+1 ; i <= r;i++){
         right.push_back(arr[i]);
       }
       mergesort(right,0,right.size()-1);
       mergesort(left,0,left.size()-1);
       
       int i = 0 ;
       int j = 0 ;
       int k = l;
       while (i < left.size() && j < right.size()) 
       {
         if (left[i] < right[j]) 
         {
           arr[k++] = left[i++];
           
         }
         else 
         {
           arr[k++] = right[j++];
           
         }
         
       }
       while (i < left.size()) 
       {
         arr[k++] = left[i++];
         
       }
       while (j < right.size()) 
       {
         arr[k++] = right[j++];
         
       }


    }
        vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,(int)nums.size()-1);
        return nums;
    }
};
int main (int argc, char *argv[]) {
  int n;
  scanf("%d",&n);
  vector<int>arr(n);
  for (int  i = 0; i < n; i++) 
  {
    scanf("%d",&arr[i]);
  }
  Solution solution;
  vector<int>ans = solution.sortArray(arr);
  for(int t : ans){
    printf("%d ",t);
  }

  return 0;
}
