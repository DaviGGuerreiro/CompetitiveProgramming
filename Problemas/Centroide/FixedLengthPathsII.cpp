#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int MAXN = 2e5 + 2;

vector<int> tree [MAXN];
vector<int> subtreeSize;
vector<bool> removed;
vector<int> to_clear;
vector<int> distancias;

int k, k1, k2;
ll ans = 0;

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

BIT arvore(MAXN);

//encontrar -> processa -> remove -> decompoe recursivamente.

int get_subtreeSize(int v, int p = -1){
    subtreeSize[v] = 1;
    for(auto it : tree[v]){
        if(it == p || removed[it]) continue;
        subtreeSize[v] += get_subtreeSize(it, v);
    }
    return subtreeSize[v];
}

int get_centroid(int v, int treeSize, int p = -1){
    for(int it : tree[v]){
        if(it == p || removed[it]) continue;
        if(subtreeSize[it] * 2 > treeSize) return get_centroid(it, treeSize, v);
    }
    return v;
}

void get_distances(int v, int p, int dist, vector<int>& distancias){
    if(dist > k2) return;
    distancias.push_back(dist);
    for(int it : tree[v]){
        if(it == p || removed[it]) continue;
        get_distances(it, v, dist + 1, distancias);
    }
}

void process_centroid(int centroid){
    to_clear.clear();
    for(int u : tree[centroid]){
        if(removed[u]) continue;

        distancias.clear();
        get_distances(u, centroid, 1, distancias);

        for(int d : distancias){
            if(k2 - d >= 0){
                ans += arvore.query(k1 - d + 1, k2 - d + 1);
            }
        }

        for(int d : distancias){
            arvore.add(d + 1, 1);
            to_clear.push_back(d);
        }
    }

    for(int d : to_clear){
        arvore.add(d + 1, -1);
    }
}

void decompose(int v){
    int tree_size = get_subtreeSize(v);
    int centroid = get_centroid(v, tree_size);

    process_centroid(centroid);
    removed[centroid] = true;

    for(int it : tree[centroid]){
        if(!removed[it]) decompose(it);
    }
}

void solve(){
    int n; cin>>n>>k1>>k2;
    int a, b;
    for(int i = 0 ; i <n-1; i++){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    if(n == 1){cout<<"0\n"; return;}
    else if(n == 2){((k1 == k2) && (k1 == 1) ? cout<<"1\n" : cout<<"0\n"); return;}
    subtreeSize =  vector<int> (n+1, 0);
    removed = vector<bool> (n+1, false);
    arvore.add(1, 1);
    decompose(1);
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}