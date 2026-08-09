#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int maxval=0;
    int ind=-1;
   map<int,int>dp;
    for(int i=0;i<n;i++){
        dp[arr[i]]=dp[arr[i]-1]+1;
        if(dp[arr[i]]>maxval){
            maxval=dp[arr[i]];
            ind=i;
        }
    }
    cout<<maxval<<endl;
    vector<int>ans;
    ans.push_back(ind+1);
    for(int i=ind-1;i>=0;i--){
        if(arr[i]+1==arr[ind]){
           ans.push_back(i+1);
            ind=i;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto i:ans)
    cout<<i<<" ";
}