#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    ll score = 0;
    vector<int> vec (2*n + 1);
    for(int i = 1; i<=2*n; i++){
        cin>>vec[i];
    }
    cout<<score<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
    //solve();
}