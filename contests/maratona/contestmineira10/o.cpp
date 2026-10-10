#include<bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const ll MOD = 1e9 + 7;

ll mod_add(ll a, ll b){
    return ((a % MOD) + (b % MOD) + MOD) % MOD;
}

ll mod_mul(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

void solve(){
    int n; cin>>n;
    ll x = 0, mult = 1;
    char aux; 
    ll numero, resultado;
    for(int i = 0; i<n; i++){
        cin>>aux>>numero;
        if(aux == '+'){
            x = mod_add(x, numero);
        }
        else if(aux == '*'){
            x = mod_mul(x, numero);
            mult = mod_mul(mult, numero);
        }
        else{
            resultado = mod_add(x, mod_mul(numero, mult));
            cout<<resultado<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}