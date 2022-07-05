//  Time Complexity : O(N*W)  //


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
    
    int n,W;
    cin>>n>>W;
    
    vector<int>wt(n);
    
    for(int i=0;i<n;++i){
        cin>>wt[i];
    }
    
    vector<int>val(n);
    
    for(int i=0;i<n;++i){
        cin>>val[i];
    }
    
    vector<int>dp(W+1,0);
    
    for(int i=0;i<n;i++){
        
        for(int j=W;j>=wt[i];j--){
            
            dp[j]=max(dp[j],dp[j-wt[i]]+val[i]);
            
        }
        
    }
    
    cout<<dp[W]<<"\n";
    
    return 0;
    
}