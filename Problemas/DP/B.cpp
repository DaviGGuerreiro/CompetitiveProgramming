#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
int n;
vector<vector<ll>> dp;
vector<pair<ll,ll>> vec;
vector<ll> inv;

ll mod_mul(ll a, ll b){
    return((a%MOD)*(b%MOD))%MOD;
}

ll fexp(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b%2 == 1) ret = mod_mul(ret, a);
        a = mod_mul(a,a);
        b >>= 1;
    }
    return ret % MOD;
}

void solve(){
    cin>>n;
    vec = vector<pair<ll,ll>> (n+1);
    vector<ll> intervalos;
    for(int i = 1; i <= n; i++){
        cin>>vec[i].first>>vec[i].second;
        vec[i].first -= i; vec[i].second -= i;
        intervalos.push_back(vec[i].first); intervalos.push_back(vec[i].second + 1);
    }
    sort(intervalos.begin(), intervalos.end());
    intervalos.erase(unique(intervalos.begin(), intervalos.end()), intervalos.end());
    ll tam = intervalos.size() - 1;
    dp = vector<vector<ll>> (n+1, vector<ll> (tam + 1, 0)); // i - > tamanho da seq; j - > blocos
    for(int i = 0 ; i <= tam; i++) dp[0][i] = 1;

    for(ll j = 1; j <= tam; j++){
        ll dist = intervalos[j] - intervalos[j-1];
        for(ll i = 1; i <= n; i++){
            ll s = 0;
            ll ways = 1;

            for(ll c = 1; c <= i; c++){
                ll k = i - c + 1;

                if(vec[k].first > intervalos[j-1] || vec[k].second < intervalos[j] - 1) break;
                ways = (ways % MOD) * ((((dist + c - 1) % MOD) % MOD) * inv[c]) % MOD;

                s += (s + (ways * dp[i-c][j-1])) % MOD;
            }

            dp[i][j] = (dp[i][j-1] + s) % MOD;
        }
    }

    cout<<dp[n][tam]<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    inv = vector<ll> (301, 0);
    for(ll i = 0; i < 301; i++) inv[i] = fexp(i, MOD - 2);
    solve();
}