#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 998244353;
ll n, k;

ll mod_mul(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll mod_add(ll a, ll b){
    return ((a % MOD) + (b % MOD)) % MOD;
}

void solve(){
    cin>>n>>k;
    vector<ll> vec (1, k);
    ll sobra;
    for(ll i = 2 ; i <= k; i++){
        vector<ll> novo (i, 0);
        sobra = k % i;
        for(ll j = 0 ; j < i; j++){
            novo[j] = mod_mul
        }
        swap(vec, novo);
    }
    ll resposta = 0;
    for(auto it : vec){
        resposta = mod_add(resposta, it);
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}