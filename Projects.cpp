//  Time Complexity : O(N*logN)  //


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


bool static comp(const vector<ll>&x,const vector<ll>&y){
    
    return x[1] < y[1];
    
}

int main(){
    
     
    ll n;
    cin>>n;
    
    vector<vector<ll>>vec(n,vector<ll>(3));
    
    for(ll i=0;i<n;++i){
        cin>>vec[i][0]>>vec[i][1]>>vec[i][2];
    }
    
    sort(vec.begin(),vec.end(),comp);
    
    vector<ll>dp(n,0LL);
    
    dp[0]=vec[0][2];
    
    for(ll i=1;i<n;++i){
        
        ll inc=-1LL,low=0,high=i-1;
        
        ll currprofit=vec[i][2];
        
        while(low<=high){
            
            ll mid=(low+high)/2;
            
            if(vec[mid][1]<vec[i][0]){
                
                inc=mid;
                low=mid+1;
                
            }
            
            else{
                
                high=mid-1;
                
            }
            
        }
        
        if(inc!=-1){
            
            currprofit+=dp[inc];
            
        }
        
        dp[i]=max(dp[i-1],currprofit);
        
    }
    
    cout<<dp[n-1]<<"\n";
    
    return 0;
    
}