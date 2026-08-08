#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
 int n;
 cin>>n;
 vector<int>a(n),b(n);
 for(int i=0;i<n;i++)
 cin>>a[i];
 for(int j=0;j<n;j++)
 cin>>b[j];
 vector<vector<int>>dp(n,vector<int>(3,0));
 dp[0][0]=0;
 dp[0][1]=a[0];
 dp[0][2]=b[0];
 for(int i=1;i<n;i++){
    dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
    dp[i][1]=max(dp[i-1][0],dp[i-1][2])+a[i];
    dp[i][2]=max(dp[i-1][0],dp[i-1][1])+b[i];
 }
 cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;
}