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




int main(){
    
     
    int n;
    cin>>n;
    
    vector<int>tails;
    
    vector<int>a(n);
    
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    
    tails.push_back(a[0]);
    
    for(int i=1;i<n;++i){
        
        if(tails.back()<a[i]){
            
            tails.push_back(a[i]);
        
            
        }
        
        else{
            
            int idx=lower_bound(tails.begin(),tails.end(),a[i])-tails.begin();
            tails[idx]=a[i];
            
        }
        
    }
    
    cout<<tails.size()<<"\n";
    
    return 0;
    
}