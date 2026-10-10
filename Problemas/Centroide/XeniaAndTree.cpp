#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int MAXN = 2e5 + 1;

vector<int> tree [MAXN];
vector<int> subtreeSize;
vector<bool> removed;

int menor [MAXN];
int pai [MAXN];
int centroidTree [MAXN];
bool cor [MAXN];

int k1, k2;
ll ans = 0;

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

void process_centroid(int centroid){
    
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
    int n, q; cin>>n>>q;
    int a, b;
    for(int i = 0 ; i <n-1; i++){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    subtreeSize =  vector<int> (n+1, 0);
    removed = vector<bool> (n+1, false);
    decompose(1);
    cor[1] = true;
    for(int i = 0 ; i < q; i++){
        cin>>k1>>k2;
        if(k1 == 1){

        }
        else{

        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    for(int i = 0 ; i<MAXN; i++){ menor[i] = 1e9; pai[i] = -1; cor[i] = false;}
    solve();
}