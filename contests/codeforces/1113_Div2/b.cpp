#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n, m; cin>>n>>m;
    vector<int> vec (n), v(m);
    for(int i = 0 ; i <n; i++){
        cin>>vec[i];
    }
    for(int i = 0 ; i <m; i++){
        cin>>v[i];
    }
    if(2*m > n){ cout<<"NO\n"; return;}
    sort(vec.begin(), vec.end());
    sort(v.begin(), v.end());
    for(int i = 0 ; i<m; i++){
        if(v[i] < vec[i] || v[i] > vec[n-m+i]){cout<<"NO\n"; return;}
    }
    cout<<"YES\n";
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
    //solve();
}