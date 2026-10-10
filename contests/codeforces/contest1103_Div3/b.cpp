#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k; cin>>n>>k;
    string s; cin>>s;
    for(int i = 0; i<n; i++){
        if(i-k >= 0 && s[i-k] == '1'){
            s[i-k] = '0';
            if(s[i] == '1') s[i] = '0';
            else s[i] = '1';
        }
    }
    for(const auto it : s){
        if(it == '1'){
            cout<<"NO"<<'\n';
            return;
        }
    }
    cout<<"YES"<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}