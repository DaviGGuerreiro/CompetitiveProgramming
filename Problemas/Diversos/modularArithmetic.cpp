#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll MOD2 = 1e9 + 6;

ll mod_add(ll a, ll b){
    return (a % MOD + b % MOD) % MOD;
}
ll mod_sub(ll a, ll b){
    return((a % MOD - b % MOD) + MOD) % MOD;
}
ll mod_mul(ll a, ll b){
    return(a % MOD * b % MOD) % MOD;
}

ll mod_mul2(ll a, ll b){
    return(a % MOD2 * b % MOD2) % MOD2;
}
ll mod_add2(ll a, ll b){
    return (a % MOD2 + b % MOD2) % MOD2;
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
    string a, b;
    char opp;
    cin>>a>>opp>>b;
    vector<ll> primeiro (a.size()), segundo (b.size());
    ll mult; int indice;
    indice = 0, mult = 1;
    for(int i = a.size() - 1; i >= 0; i--){
        primeiro[indice] = mod_mul(mult, a[i] - '0');
        indice++;
        mult = mod_mul(mult, 10ll);
    }
    indice = 0, mult = 1;
    for(int i = b.size() - 1; i >= 0; i--){
        if(opp != '^') segundo[indice] = mod_mul(mult, b[i] - '0');
        else segundo[indice] = mod_mul2(mult, b[i] - '0');
        indice++;
        if(opp != '^') mult = mod_mul(mult, 10ll);
        else mult = mod_mul2(mult, 10ll);
    }
    ll numero1 = 0, numero2 = 0;
    for(int i = 0; i < a.size(); i++){
        numero1 = mod_add(numero1, primeiro[i]);
    }
    for(int i = 0; i < b.size(); i++){
        if(opp != '^') numero2 = mod_add(numero2, segundo[i]);
        else numero2 = mod_add2(numero2, segundo[i]);
    }

    ll resposta = 0;
    if(opp == '+'){
        resposta = mod_add(numero1, numero2);
    }
    else if(opp == '-'){
        resposta = mod_sub(numero1, numero2);
    }
    else if(opp == '*'){
        resposta = mod_mul(numero1, numero2);
    }
    else{
        resposta = fexp(numero1, numero2);
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}