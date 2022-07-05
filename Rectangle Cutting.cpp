//  Time  Complexity : O(m*n*max(m,n))  //


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
    
    int a,b;
    cin>>a>>b;
    
    vector<vector<int>>dp(a+1,vector<int>(b+1,1e9));
    
    for(int i=1;i<=a;++i){
        
        for(int j=1;j<=b;++j){
            
            if(i==j){
                
                dp[i][j]=0;
                
            }
            
        }
        
    }
    
    
    for(int i=1;i<=a;++i){
        
        for(int j=1;j<=b;++j){
            
            if(i==j){
                continue;
            }
            
            int ans=1e9;
            
            for(int k=1;k<i;k++){
                
                ans=min(ans,1+dp[k][j]+dp[i-k][j]);
                
            }
            
            for(int k=1;k<j;k++){
                
                ans=min(ans,1+dp[i][k]+dp[i][j-k]);
                
            }
            
            dp[i][j]=ans;
            
        }
        
    }
    
    cout<<dp[a][b]<<"\n";
    
    return 0;
    
}