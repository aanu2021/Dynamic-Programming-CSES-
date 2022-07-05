//  Time Complexity : O(N*N*MAX(arr))  //


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
    
    int n;
    cin>>n;
    
    vector<int>arr(n);
    
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    
    int maxi=0;
    
    for(int i:arr){
        maxi=max(maxi,i);
    }
    
    int target=(maxi*n);
    
    vector<bool>dp(target+1,false);
    
    
    dp[0]=true;
    
    
    for(int i=0;i<n;i++){
        
        for(int j=target;j>=arr[i];j--){
            
            dp[j]=dp[j] || dp[j-arr[i]];
            
        }
        
    }
    
    int cnt=0;
    
    for(int i=1;i<=target;++i){
        if(dp[i]){
            cnt++;
        }
    }
    
    cout<<cnt<<"\n";
    
    
    for(int i=1;i<=target;++i){
        if(dp[i]){
            cout<<i<<" ";
        }
    }
    
    cout<<"\n";
    
    
    
    return 0;
    
}