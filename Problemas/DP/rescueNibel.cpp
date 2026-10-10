#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 998244353;
ll n, k;

ll mod_sum(ll a, ll b){
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll mod_mul(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll fexp(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b % 2 == 1) ret = mod_mul(ret, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return ret;
}

void solve(){
    cin>>n>>k;
    vector<ll> entra (n), sai (n);
    for(int i = 0; i<n; i++){
        cin>>entra[i]>>sai[i];
    }
    sort(entra.begin(), entra.end());
    sort(sai.begin(), sai.end());

    ll local = 0;
    ll resposta = 0;

    vector<ll> fatorial (n + 1, 0);
    vector<ll> inv (n + 1, 0);
    fatorial[0] = 1; fatorial[1] = 1;
    for(ll i = 2; i<=n; i++){
        fatorial[i] = mod_mul(fatorial[i-1], i);
    }
    inv[n] = fexp(fatorial[n], MOD-2);
    for(ll i = n-1; i >= 0; i--){
        inv[i] = mod_mul(inv[i+1], i+1);
    }
    int t = 0, y = 0;
    while(t != n){
        if(entra[t] <= sai[y]){ 
            t++;
            if(local >= k - 1){
                ll valor = mod_mul(fatorial[local], inv[k - 1]);
                valor = mod_mul(valor, inv[local - k + 1]);
                resposta = mod_sum(resposta, valor);
            }
            local++;
        }
        else{ y++; local--;}
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}