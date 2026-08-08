#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
 int n;
 cin>>n;
if(n%2==1){
    cout<<0<<endl;
    return 0;
}
vector<int>dp(n/2,0);
dp[0]=2;
for(int i=1;i<n/2;i++){
    dp[i]=dp[i-1]*2;
}
cout<<dp[(n/2-1)]<<endl;
}