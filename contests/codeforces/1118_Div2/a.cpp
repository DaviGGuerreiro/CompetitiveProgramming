#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    ll r1, r2;
    cin>>r1; r2 = r1;
    for(int i = 0; i< n-1; i++) cin>>r2;
    r1 = gcd(r1, r2);
    cout<<r1<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
}