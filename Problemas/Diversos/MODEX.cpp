#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll MOD;

ll mod_mul(ll a, ll b){
    return(a % MOD * b % MOD) % MOD;
}

ll fexp(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b%2 == 1) ret = mod_mul(ret,a);
        a = mod_mul(a,a);
        b >>= 1;
    }
    return ret % MOD;
}

void solve(){
    int c; cin>>c;
    ll x, y, n, z;
    for(int i = 0; i<c; i++){
        cin>>x>>y>>n;
        MOD = n;
        z = fexp(x, y);
        cout<<z<<'\n';
    }
    char zero; cin>>zero;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}