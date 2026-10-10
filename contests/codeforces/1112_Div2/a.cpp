#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    vector<int> vec (n);
    int v1 = 2e9, v2 = 0;
    for(int i = 0 ; i<n; i++){
        cin>>vec[i];
        if(i % 2 == 0) v1 = min(v1, vec[i]);
        else v2 = max(v2, vec[i]);
    }
    if(n % 2 == 1){ cout<<"NO\n"; return;}
    if(v1 - 1> v2){cout<<"YES\n"; return;}
    cout<<"NO\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
    //solve();
}