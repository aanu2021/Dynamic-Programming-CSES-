//  Time Complexity : O(N*target)  //

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
    
    int n,target;
    cin>>n>>target;
    
    vector<int>dp(target+1,1e9);
    
    dp[0]=0;
    
    vector<int>arr(n);
    
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    
    for(int i=0;i<n;++i){
        
        for(int j=arr[i];j<=target;++j){
            
            dp[j]=min(dp[j],dp[j-arr[i]]+1);
            
        }
        
    }
    
    if(dp[target]>=1e9){
        cout<<-1<<"\n";
    }else{
        cout<<dp[target]<<"\n";
    }
    
    return 0;
    
}