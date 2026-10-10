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
    ll n, m; cin>>n>>m;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
    return 0;
}