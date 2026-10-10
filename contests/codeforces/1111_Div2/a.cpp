#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    vector<int> vec(n);
    int z = 0, u = 0;
    for(int i = 0 ; i<n; i++){
        cin>>vec[i];
        if(vec[i] == 1) u++;
        else z++;
    }
    if(n % 2 == 1){ cout<<"NO\n"; return; }
    if(abs(u - z) % 4 != 0){ cout<<"NO\n"; return; }
    cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
}