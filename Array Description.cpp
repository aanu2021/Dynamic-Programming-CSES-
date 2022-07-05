//  Time Complexity : O(N*M)  //


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
    
    ll n,m;
    cin>>n>>m;
    
    vector<ll>arr(n);
    
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,0LL));
    
    if(arr[0]==0){
        
        for(ll i=1;i<=m;i++){
            
            dp[0][i]=1LL;
            
        }
        
    }
    
    else{
        
        dp[0][arr[0]]=1LL;
        
    }
    
    
    for(ll i=1;i<n;++i){
        
        if(arr[i]==0){
            
            for(ll j=1;j<=m;j++){
                
                ll left=(j-1>=1 ? dp[i-1][j-1] : 0LL);
                ll right=(j+1<=m ? dp[i-1][j+1] : 0LL);
                
                dp[i][j]=add(left,right);
                
                dp[i][j]=add(dp[i][j],dp[i-1][j]);
                
            }
            
        }
        
        else{
            
            ll currval=arr[i];
            
            ll left=(currval-1>=1 ? dp[i-1][currval-1] : 0LL);
            ll right=(currval+1<=m ? dp[i-1][currval+1] : 0LL);
            
            dp[i][currval]=add(left,right);
            
            dp[i][currval]=add(dp[i][currval],dp[i-1][currval]);
            
        }
        
    }
    
    ll sum=0LL;
    
    for(ll i=1;i<=m;i++){
        
        sum=add(sum,dp[n-1][i]);
        
    }
    
    cout<<mod(sum)<<"\n";
    
    return 0;
    
}