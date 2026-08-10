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
    vector<vector<int>>dp(n,vector<int>(3,LLONG_MAX));
    dp[0][0]=1;
    if(arr[0]==1){
        dp[0][1]=0;
    }else if(arr[0]==2){
        dp[0][2]=0;
    }
    else if(arr[0]==3){
        dp[0][1]=0;
        dp[0][2]=0;
    }
    for(int i=1;i<n;i++){
        dp[i][0]=min({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+1;
        if(arr[i]==1){
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
        }else if(arr[i]==2){
            dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
        }else if(arr[i]==3){
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
        }
    }
    cout<<min({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;
    return 0;

}