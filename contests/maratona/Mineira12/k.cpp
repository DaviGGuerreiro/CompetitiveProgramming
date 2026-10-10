#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<long,long>;

void solve(){
    int n; cin>>n;
    int a, b;
    set<pair<int,int>> conjunto;
    for(int i =0 ;i<n; i++){
        cin>>a>>b;
        conjunto.insert({a,b});
    }
    int t = 0;
    cout<<conjunto.size()<<'\n';
    for(auto it: conjunto){
        cout<<it.first + (t * it.second)<<' '<<t<<'\n';
        t++;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}