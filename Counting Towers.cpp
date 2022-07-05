//  Time Complexity : O(2*N) --> O(N)  //


#include<bits/stdc++.h>
using namespace std;


typedef long long ll ;

const ll M = 1e9 + 7;

ll mod(ll a){
    return ((a%M)+M)%M;
}

ll mul(ll a,ll b){
    return mod(mod(a)*mod(b));
}

ll add(ll a,ll b){
    return mod(mod(a)+mod(b));
}

// dp[i][0] --> linked with 2 tiles of width 1 , of (i-1) th level;

// dp[i][1] --> linked woth 1 tile of width 2  , of (i-1) th level;

int main(){
    
    ll N=1000002;
    
    vector<vector<ll>>dp(N+1,vector<ll>(2,0LL));
    
    dp[1][0]=1LL;
    dp[1][1]=1LL;
    
    for(ll i=2;i<=N;++i){
        
        ll op1=add(dp[i-1][0],dp[i-1][1]);
        
        ll op2=dp[i-1][1];
        
        dp[i][1]=add(op1,op2);
        
        ll op3=dp[i-1][0];
        
        ll op4=mul(2LL,dp[i-1][0]);
        
        dp[i][0]=add(add(op1,op3),op4);
        
    }
    
    int t;
    cin>>t;
    
    while(t--){
        
        ll n;
        cin>>n;
        
        cout<<add(dp[n][0],dp[n][1])<<"\n";
        
    }
    
    return 0;
    
}