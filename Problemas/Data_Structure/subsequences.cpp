#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<long,long>;

struct BIT {
    int n;
    vector<ll> bit;
    // Inicializa a BIT com tamanho n (1-based)
    BIT(int n) : n(n), bit(n + 1, 0) {}
    // Soma 'val' na posicao 'idx'
    void add(int idx, ll val) {
        for (; idx <= n; idx += idx & -idx) 
            bit[idx] += val;
    }
    // Retorna a soma do prefixo [1, idx]
    ll query(int idx) {
        ll sum = 0;
        for (; idx > 0; idx -= idx & -idx) 
            sum += bit[idx];
        return sum;
    }
    // Retorna a soma no intervalo [l, r]
    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void solve(){
    int n, k; cin>>n>>k;
    vector<BIT> tree(k+1, (n));
    vector<int> vec (n+1);
    vector<vector<ll>> dp (k+1, vector<ll> (n+1, 0));
    for(int i = 1; i<=n; i++){ cin>>vec[i]; dp[1][vec[i]]++; tree[1].add(vec[i], 1);} 
    for(int i = 2; i <= k; i++){
        for(int j = i; j <= n; j++){
            dp[i][vec[j]] = tree[i-1].query(1, vec[j]-1);
            tree[i].add(vec[j], dp[i][vec[j]]);
        }
    }
    ll resposta = tree[k].query();
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}