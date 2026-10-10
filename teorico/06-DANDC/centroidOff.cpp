#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int MAXN = 2e5 + 2;
int n, q;

vector<int> to_clear;
vector<int> distancias;

vector<int> tree [MAXN];
int subtreeSize [MAXN];
int removed [MAXN];

int freq[MAXN];
int grau [MAXN];

int max_k = 0;
int queries[20];
ll ans[20];

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

void get_distances(int v, int p, int dist, int max_k){
    if(dist > max_k) return;
    if(grau[v] == 1) distancias.push_back(dist);
    for(int it : tree[v]){
        if(it == p || removed[it]) continue;
        get_distances(it, v, dist + 1, max_k);
    }
}

void process_centroid(int centroid){
    to_clear.clear();

    for(int u : tree[centroid]){
        if(removed[u]) continue;

        distancias.clear();
        get_distances(u, centroid, 1, max_k);

        for(int d : distancias){
            for(int i = 0; i < q; i++){
                int k = queries[i];
                if(k - d >= 0){
                    ans[i] += freq[k - d];
                }
            }
        }

        for(int d : distancias){
            freq[d]++;
            to_clear.push_back(d);
        }
    }

    for(int d : to_clear){
        freq[d] = 0;
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
    cin>>n>>q;
    int a, b;
    for(int i = 0 ; i <n-1; i++){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        grau[a]++; grau[b]++;
    }

    for(int i = 0 ; i < q; i++){
        cin >> queries[i];
        max_k = max(max_k, queries[i]);
    }

    if(n == 2){
        for(int i = 0; i < q; i++){
            if(queries[i] == 1) cout << "1\n";
            else cout << "0\n";
        }
        return;
    }

    decompose(1);

    for(int i = 0; i < q; i++){
        cout << ans[i] << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    for(int i = 0 ; i<MAXN; i++) grau[i] = 0;
    solve();
}