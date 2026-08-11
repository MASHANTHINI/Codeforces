#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
vector<int>dp(100001);
vector<int>pre(100001);
int main(){
    int t,k;
    cin>>t>>k;
    dp[0]=1;
    if(k==1){
        dp[1]=2;
    }else
    {
        dp[1]=1;
    }
    for(int i=2;i<=100000;i++){
        if(i-k<0){
            dp[i]=dp[i-1]%mod;
        }else{
            dp[i]=(dp[i-1]+dp[i-k])%mod;
        }
    }
    pre[0]=dp[0];
    for(int i=1;i<=100000;i++){
        pre[i]=(pre[i-1]+dp[i])%mod;
    }
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a-1>=0){
            cout<<(pre[b]-pre[a-1]+mod)%mod<<endl;
        }else{
            cout<<pre[b]<<endl;
        }
    }
}