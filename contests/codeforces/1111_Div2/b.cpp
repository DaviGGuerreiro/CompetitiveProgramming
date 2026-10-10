#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    ll n, k, m; cin>>n>>k>>m;
    if(k > m){ cout<<"NO\n"; return; }
    cout<<"YES\n";
    ll comeco = m - (k-1); cout<<comeco<<' ';
    for(int i = 1; i < n; i++) cout<<"1 ";
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
    //solve();
}