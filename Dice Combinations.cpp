//  Time Complexity : O(6*N) --> O(N)  //

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


int main(){
    
    ll n;
    cin>>n;
    
    vector<ll>dp(n+1,0LL);
    
    dp[0]=1LL;
    
    for(ll i=1;i<=n;i++){
        
        for(ll j=1;j<=min(6LL,i);j++){
            
            dp[i]=add(dp[i],dp[i-j]);
            
        }
        
    }
    
    cout<<mod(dp[n])<<"\n";
    
    return 0;
    
}