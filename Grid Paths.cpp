//  Time Complecity : O(N*N)  //


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
    
    int n;
    cin>>n;
    
    vector<vector<char>>grid(n,vector<char>(n));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    
    if(grid[0][0]=='*' || grid[n-1][n-1]=='*'){
        
        cout<<0<<"\n";
        
    }
    
    else{
        
        vector<vector<ll>>dp(n,vector<ll>(n,0LL));
        
        dp[0][0]=1LL;
        
        for(int i=1;i<n;i++){
            
            if(grid[0][i]=='*'){
                dp[0][i]=0LL;
                break;
            }else{
                dp[0][i]=1LL;
            }
            
        }
        
        
        for(int i=1;i<n;++i){
            
            if(grid[i][0]=='*'){
                dp[i][0]=0LL;
                break;
            }else{
                dp[i][0]=1LL;
            }
            
        }
        
        
        for(int i=1;i<n;i++){
            
            for(int j=1;j<n;j++){
                
                if(grid[i][j]=='*'){
                    dp[i][j]=0LL;
                }
                
                else{
                    dp[i][j]=add(dp[i-1][j],dp[i][j-1]);
                }
                
            }
            
        }
        
        cout<<mod(dp[n-1][n-1])<<"\n";
        
    }
    
    return 0;
    
}