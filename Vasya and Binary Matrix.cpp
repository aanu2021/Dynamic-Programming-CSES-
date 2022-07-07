//  Time Complexity : O(N*N*N)  //


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>bestLen;

ll dp[102][102][102];

vector<ll>groups;


ll func(ll i,ll j,ll extra){
    
    if(i>j){
        
        return 0LL;
        
    }
    
    if(dp[i][j][extra]!=-1){
        
        return dp[i][j][extra];
        
    }
    
    ll ans = bestLen[groups[i]+extra] + func(i+1,j,0LL);
    
    for(ll k=i+2;k<=j;k+=2){
        
        ans=max(ans,func(i+1,k-1,0LL) + func(k,j,extra+groups[i]));
        
    }
    
    return dp[i][j][extra] = ans;
    
}


int main(){
     
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
     
         int t=1;
         // cin>>t;
         
         while(t--){
          
           ll n;
           cin>>n;
           
           string s;
           cin>>s;
           
           vector<ll>a(n+1);
           
           for(ll i=1;i<=n;++i){
               cin>>a[i];
           }
           
           bestLen.resize(n+1,0);
           
           bestLen[1]=a[1];
           
           for(ll i=2;i<=n;++i){
               
               bestLen[i]=a[i];
               
               for(ll j=1;j<i;++j){
                   
                   bestLen[i]=max(bestLen[i],a[j]+bestLen[i-j]);
                   
               }
               
           }
           
           for(ll i=0;i<=n;++i){
               for(ll j=0;j<=n;++j){
                   for(ll k=0;k<=n;++k){
                       dp[i][j][k]=-1;
                   }
               }
           }
           
           ll cnt=0LL;
           
           for(ll i=0;i<n;++i){
               
               ll j=i;
               
               while(j<n && s[j]==s[i]){
                   j++;
                   cnt++;
               }
               
               groups.push_back(cnt);
               cnt=0;
               
               i=j;
               i--;
               
           }
           
           n=groups.size();
           
        //   for(ll i=0;i<n;++i){
        //       cout<<groups[i]<<" ";
        //   }cout<<"\n";
           
           
           
           ll ans=func(0,n-1,0);
           
           cout<<ans<<"\n";
          
         }
      
    return 0;
    
}