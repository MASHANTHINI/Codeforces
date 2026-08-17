#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    unordered_map<int,int>mp;
    for(auto i:arr)
    mp[i]++;
    int sz=mp.size();
    arr.clear();
    for(auto i:mp){
        arr.push_back(i.first);
    }
    vector<int>dp(sz);
    sort(arr.begin(),arr.end());
    dp[0]=arr[0]*mp[arr[0]];
    for(int i=1;i<sz;i++){
        if(arr[i]==arr[i-1]+1){
            int take=arr[i]*mp[arr[i]];
            if(i-2>=0){
                take+=dp[i-2];
            }
            int nottake=dp[i-1];
            dp[i]=max(take,nottake);
        }else{
            dp[i]=dp[i-1]+arr[i]*mp[arr[i]];
        }
    }
    cout<<*max_element(dp.begin(),dp.end());
}