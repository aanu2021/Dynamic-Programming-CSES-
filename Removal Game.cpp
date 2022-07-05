//  Time Complexity : O(N*N)  //


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

ll modPow(ll a,ll b){
    
    if(b==0){
        return 1LL;
    }
    
    if(b==1){
        return a;
    }
    
    ll res=1LL;
    
    while(b){
        
        if(b%2==1){
            res=mul(res,a);
        }
        
        b/=2;
        a=mul(a,a);
        
    }
    
    return res;
    
}

ll inv(ll a){
    return modPow(a,M-2);
}


int main(){
    
    ll n;
    cin>>n;
    
    vector<ll>a(n);
    
    for(ll i=0;i<n;++i){
        cin>>a[i];
    }
    
    
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,0LL));
    
    for(ll i=0;i<n;i++){
        dp[i][i]=a[i];
    }
    
    for(ll i=0;i<n-1;++i){
        dp[i][i+1]=max(a[i]-a[i+1],a[i+1]-a[i]);
    }
    
    for(ll L=3;L<=n;L++){
        
        for(ll i=0;i<n-L+1;i++){
            
            ll j=i+L-1;
            
            dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
            
        }
        
    }
    
    
    ll diff=dp[0][n-1];
    
    ll sum=accumulate(a.begin(),a.end(),0LL);
    
    ll ans=(sum+diff)/2LL;
    
    cout<<ans<<"\n";
    
    return 0;
    
}