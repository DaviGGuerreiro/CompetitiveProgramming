#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n, k; cin>>n>>k;
    int v1 = (k+1)/2, v2 = k/2;
    int v3 = v1 + 1 + v2 + 1;
    if(v3 > n){cout<<"-1\n"; return;}
    stack<int> p;
    for(int i = 0; i < n - v3; i++){
        if(i%2 == 0) p.push(1);
        else p.push(0);
    }
    while(!p.empty()){
        cout<<p.top(); p.pop();
    }
    for(int i = 0 ; i< v1+1; i++) cout<<0;
    for(int i = 0 ; i< v2 + 1; i++) cout<<1;
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
    //solve();
}