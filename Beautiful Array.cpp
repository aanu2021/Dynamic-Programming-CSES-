//  Time Complexity : O(N*2*2) --> O(N)  //


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
     
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
     
         int t=1;
         // cin>>t;
         
         while(t--){
          
           ll n,x;
           cin>>n>>x;
           
           vector<ll>v(n);
           
           for(ll i=0;i<n;++i){
               cin>>v[i];
           }
           
           ll dp[n+2][2][2];

           
           // dp[i][0][0] --> we can't use x anymore , as it was already used before index i.
           
           // dp[i][1][0] --> we can use x , but not from these index.
           
           // dp[i][1][1] --> we can use x as a continuation of subarray ending at index i-1 or starting from index i.
           

           for(ll i=0;i<=n;i++){
               for(ll j=0;j<2;j++){
                   for(ll k=0;k<2;k++){
                       dp[i][j][k]=0LL;
                   }
               }
           }
           
           dp[0][1][0]=v[0];
           dp[0][1][1]=(x*v[0]);
           
           ll ans=max(dp[0][1][0],dp[0][1][1]);
           
           for(ll i=1;i<n;++i){
               
               dp[i][1][0]=max(v[i],v[i]+dp[i-1][1][0]);
               
               dp[i][1][1]=max(x*v[i],x*v[i]+max(dp[i-1][1][1],dp[i-1][1][0]));
               
               dp[i][0][0]=max(v[i],v[i]+max(dp[i-1][0][0],dp[i-1][1][1]));
               
               ans=max(ans,max({dp[i][0][0],dp[i][1][0],dp[i][1][1]}));
               
           }
           
           cout<<max(0LL,ans)<<"\n";
          
         }
      
    return 0;
    
}