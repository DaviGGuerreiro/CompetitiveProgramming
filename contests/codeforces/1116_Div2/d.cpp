#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 998244353;
const int maxn = 1e6 + 1;
ll fat[maxn];
ll invfat[maxn];

ll mod_mul(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD;
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

void precompute(){
    fat[0] = 1; invfat[0] = 1;
    for(int i = 1; i < maxn; i++){
        fat[i] = mod_mul(fat[i-1], i);  
    }
    invfat[maxn - 1] = fexp(fat[maxn - 1], MOD - 2);
    for(int i = maxn - 2; i >= 1; i--){
        invfat[i] = mod_mul(invfat[i+1], (i + 1));
    }
}

ll combinacao(ll n, ll k){
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    ll r = mod_mul(fat[n], invfat[k]);
    r = mod_mul(r, invfat[n - k]);
    return r;
}

void solve(){
    int n; cin>>n;
    int z = 0, u = 0;
    int k = 1, k0, k1;
    vector<char> vec (n);
    for(int i = 0 ; i < n; i++){
        cin>>vec[i];
        if(vec[i] == '0') z++;
        else u++;
        if(i > 0){
            if(vec[i] != vec[i-1]) k++;
        }
    }
    if(z == 0 || u == 0){ cout<<1<<'\n'; return;}

    if(vec[0] == '0'){
        k0 = ((k+1)/2);
        k1 = (k/2);
    }
    else{
        k1 = ((k+1)/2);
        k0 = (k/2);
    }
    ll resposta = mod_mul(combinacao(z-1, k0-1), combinacao(u-1, k1-1));
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    precompute();
    int t; cin>>t; while(t--) solve();
    //solve();
}