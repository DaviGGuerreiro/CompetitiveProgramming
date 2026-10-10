#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    vector<ll> vec (n), dp (n, 0);
    vector<ll> v (n+1, 1e9);
    ll answer = 0;
    for(int i = 0 ; i<n; i++){
        cin>>vec[i];
        ll it = lower_bound(v.begin(), v.end(), vec[i]) - v.begin();
        answer = max(answer, it+1);
        v[it] = vec[i];
    }
    cout<<answer<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}