#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

const int MAXN = 2e5 + 3;
ll fatorial[MAXN];

ll mod_sum(ll a, ll b){
    return (((a % MOD) + (b % MOD)) + MOD) % MOD;
}

ll mod_mul(ll a, ll b){
    return (((a % MOD) * (b % MOD))) % MOD;
}

void fator(){
    fatorial[0] = fatorial[1] = 1;
    for(ll i = 2; i <= 2e5; i++){
        fatorial[i] = mod_mul(fatorial[i-1], i);
    }
}

void solve(){
    int n; cin>>n;
    ll resposta = 0;
    vector<ll> vec (n);
    vector<ll> psum (n+1, 0);
    for(int i = 0; i<n; i++) cin>>vec[i];
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    for(int i = 1 ; i<=n; i++) psum[i] = psum[i-1] + vec[i-1];
    ll valor, multiplicador = fatorial[n-2], aux = 1;
    for(int i = n-1; i>=1; i--){
        multiplicador = fatorial[i - 1];
        valor = mod_mul(vec[i], i);
        valor = mod_sum(psum[i], -valor);
        valor = mod_mul(valor, mod_mul(multiplicador, aux));
        aux = mod_mul(aux, i);
        resposta = mod_sum(resposta, valor);
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    fator();
    int t; cin>>t; while(t--) solve();
}