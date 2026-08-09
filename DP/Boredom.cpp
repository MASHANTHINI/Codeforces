#include<bits/stdc++.h>
using namespace std;
#define int long long
int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        unordered_map<int,int>freq;
        for(auto i:nums){
            freq[i]++;
        }
        vector<int>arr;
        for(auto i:freq){
            arr.push_back(i.first);
        }
        int n=arr.size();
        if(n==1)
        return arr[0]*freq[arr[0]];
        sort(arr.begin(),arr.end());
        vector<int>dp(n);
        dp[0]=arr[0]*freq[arr[0]];
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]+1){
                int take=arr[i]*freq[arr[i]];
                if(i>=2){
                    take+=dp[i-2];
                }
                int nottake=dp[i-1];
                dp[i]=max(take,nottake);
            }else
            {
                dp[i]=dp[i-1]+arr[i]*freq[arr[i]];
            }
        }
        return dp[n-1];
 }
signed main(){
  int n;
  cin>>n;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  cout<<deleteAndEarn(v);
}