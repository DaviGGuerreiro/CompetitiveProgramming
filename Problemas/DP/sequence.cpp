#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long long;

void solve(){
    int n; cin>>n;
    vector<ll> a (n+1), b (n+1);
    vector<vector<ll>> dp (n+1, vector<ll> (n+1, 0));
    for(int i = 1; i<=n; i++){
        cin>>a[i]; b[i] = a[i];
    }
    sort(b.begin() + 1, b.end());

    for(int i = 1; i <= n; i++){
        ll min_prev = 1e18;
        for(int j = 1; j<= n; j++){
            min_prev =  min(min_prev, dp[i-1][j]);

            dp[i][j] = abs(a[i] - b[j]) + min_prev;
        }
    }
    ll resposta = 1e18;
    for(int i = 1; i <= n; i++){
        resposta = min(resposta, dp[n][i]);
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}