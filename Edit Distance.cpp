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
    
    string s1,s2;
    cin>>s1>>s2;
    
    int m=s1.length();
    int n=s2.length();
    
    s1="*"+s1;
    s2="*"+s2;
    
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    
    for(int i=1;i<=m;i++){
        dp[i][0]=i;
    }
    
    for(int i=1;i<=n;i++){
        dp[0][i]=i;
    }
    
    for(int i=1;i<=m;i++){
        
        for(int j=1;j<=n;j++){
            
            if(s1[i]==s2[j]){
                
                dp[i][j]=dp[i-1][j-1];
                
            }
            
            else{
                
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                
            }
            
        }
        
    }
    
    cout<<dp[m][n]<<"\n";
    
    return 0;
    
}