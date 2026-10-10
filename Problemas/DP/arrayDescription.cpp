#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9+7;
ll n, m;

ll mod_sum(ll a, ll b){
    return ((a % MOD) + (b % MOD)) % MOD;
}

void solve(){
    cin>>n>>m;
    vector<ll> vec (n+1);
    for(int i = 1; i<=n; i++) cin>>vec[i];
    vector<vector<ll>> dp (n+1, vector<ll> (m+1,0));
    for(int i = 0; i <= m; i++) dp[0][i] = 1;
    for(int i = 1; i <= n; i++){
        if(vec[i] != 0){
            if(i == 1){ dp[i][vec[i]] = 1; continue; }
            dp[i][vec[i]] = mod_sum(dp[i][vec[i]], dp[i-1][vec[i]-1]);
            dp[i][vec[i]] = mod_sum(dp[i][vec[i]], dp[i-1][vec[i]]);
            if(vec[i] != m) dp[i][vec[i]] = mod_sum(dp[i][vec[i]], dp[i-1][vec[i]+1]);
            continue;
        }

        for(int j = 1; j <= m; j++){
            if(i == 1){ dp[i][j] = 1; continue; }
            dp[i][j] = mod_sum(dp[i][j], dp[i-1][j-1]);
            dp[i][j] = mod_sum(dp[i][j], dp[i-1][j]);
            if(j != m) dp[i][j] = mod_sum(dp[i][j], dp[i-1][j+1]);
        }
    }
    ll resposta = 0;
    for(int i = 1; i<=m; i++) resposta = mod_sum(resposta, dp[n][i]);
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}