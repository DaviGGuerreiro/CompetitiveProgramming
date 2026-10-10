#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    vector<ll> vec (n);
    ll total = 0;
    for(int i = 0; i<n; i++){
        cin>>vec[i];
        total += vec[i];
    }
    ll diferenca = total;
    ll local;
    for(int mask = 1; mask < (1<<n); mask++){
        local = 0;
        for(int j = 0; j<n; j++){
            if(mask & (1<<j)){
                local += vec[j];
            }
        }
        diferenca = min(diferenca, abs(total - (local*2)));
    }
    cout<<diferenca<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}