#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;

ll mod_add(ll a, ll b){
    return (((a % MOD) + (b % MOD)) + MOD) % MOD;
}

ll mod_mul(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

void fact(vector<ll>& factorial){
    factorial[0] = 1;
    factorial[1] = 1;
    for(ll i = 2 ; i < 21; i++){
        factorial[i] = mod_mul(factorial[i-1], i);
    }
}

void solve(){
    ll s; cin>>s;
    vector<ll> factorial (21, 0);
    fact(factorial);
    ll resposta = 0;
    for(ll i = 0; i < (1<<s); i++){
        int quantidade = __builtin_popcountll(i);
        if(quantidade % 2 == 1){
            resposta = mod_add(resposta, -factorial[s-quantidade]);
        }
        else{
            resposta = mod_add(resposta, factorial[s-quantidade]);
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}