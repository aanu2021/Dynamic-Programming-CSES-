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
    
    ll n,target;
    cin>>n>>target;
    
    vector<ll>arr(n);
    
    for(ll i=0;i<n;++i){
        cin>>arr[i];
    }
    
   // sort(arr.begin(),arr.end());
    
    vector<ll>dp(target+1,0LL);
    
    dp[0]=1LL;
    
    for(ll i=0;i<n;++i){
        
        for(ll j=arr[i];j<=target;++j){
            
            dp[j]=add(dp[j],dp[j-arr[i]]);
            
        }
        
    }
    
    cout<<dp[target]<<"\n";
    
    return 0;
    
}