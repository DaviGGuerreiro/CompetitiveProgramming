#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 998244353;

ll mod_add(ll a, ll b){
    return (a % MOD + b % MOD) % MOD;
}

ll mod_sub(ll a, ll b){
    return((a % MOD - b % MOD) + MOD) % MOD;
}

ll mod_mul(ll a, ll b){
    return(a % MOD * b % MOD) % MOD;
}

ll fexp(ll a, ll b){ // num a, primo b - 2 (1e9 + 7 - 2)
    ll ret = 1;
    while(b){
        if(b%2 == 1) ret = mod_mul(ret,a);
        a = mod_mul(a,a);
        b >>= 1;
    }
    return ret % MOD;
}

void solve(){
    ll resposta = 0;
    ll n, m, s; cin>>n>>m>>s;
    vector<ll> fatorial (n + 1 + s); fatorial[0] = 1;
    vector<ll> invfat (n + s + 1); invfat[0] = 1;
    for(ll i = 1; i <= n + s; i++){
        fatorial[i] = (fatorial[i-1] * i) % MOD;
    }
    invfat[n+s] = fexp(fatorial[n+s], MOD - 2);
    for(ll i = n+s-1; i >= 1; i--){
        invfat[i] = (invfat[i+1] * (i + 1)) % MOD;
    }
    ll aux = s; ll combina;
    ll stars; stars = mod_mul(fatorial[n + s - 1], mod_mul(invfat[s], invfat[n - 1]));
    resposta = mod_add(resposta, stars);
    for(ll i = 1; i <= n; i ++){
        combina = mod_mul(fatorial[n], mod_mul(invfat[i], invfat[n-i]));
        aux -= (m+1);
        if(aux >= 0){
            stars = mod_mul(fatorial[aux + n - 1], mod_mul(invfat[aux], invfat[n - 1]));
            if(i % 2 == 0) resposta = mod_add(resposta, mod_mul(stars, combina));
            else resposta = mod_sub(resposta, mod_mul(stars, combina));
        }
        else break;
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
    return 0;
}