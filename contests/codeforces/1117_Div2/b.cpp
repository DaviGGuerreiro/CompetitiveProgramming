#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n, m; cin>>n>>m;
    vector<int> vec (n), v (m);
    ll v1 = 0, v2 = 0;
    for(int i = 0 ; i <n; i++){
        cin>>vec[i];
        if(i != 0) v1 += abs(vec[i] - vec[i-1]) + 1;
    }
    v1 += vec[n-1];
    for(int i = 0 ; i <m; i++){
        cin>>v[i];
        if(i != 0) v2 += abs(v[i] - v[i-1]) + 1;
    }
    v2 += v[m-1];
    if(v1 >= v2) cout<<"1\n";
    else cout<<"2\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
}