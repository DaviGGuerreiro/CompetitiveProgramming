#include<bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;


template<typename T>
struct SegTree {
    int N;
    const T NEUTRAL = 1e9;
    vector<T> seg;
    SegTree(const vector<T> &vec) : N(vec.size()), seg(4 * vec.size(), NEUTRAL) {
        build(vec, 1, 0, N-1);
    }

    T join(const T &v1, const T &v2){
        return min(v1, v2);
    }

    void build(const vector<T> & vec, int v, int l, int r){
        if(l == r){
            seg[v] = vec[l];
            return;
        }
        int m = (l+r)/2;
        build(vec, 2 * v, l, m);
        build(vec, 2 * v + 1, m+1, r);
        seg[v] = join(seg[2*v], seg[2*v + 1]);
    }
    void update(int v, int tl, int tr, int pos, int new_val){
        if(tl == tr){
            seg[v] = new_val;
            return;
        }
        int tm = (tl+tr)/2;
        if(pos <= tm){
            update(2 * v, tl, tm, pos, new_val);
        }
        else{
            update(2 * v + 1, tm+1, tr, pos, new_val);
        }
        seg[v] = join(seg[2*v], seg[2*v + 1]);
    }
    T query(int v, int L, int R, int l, int r){
        if(L > r || R < l) return NEUTRAL;
        if(L >= l && R <= r) return seg[v];
        int m = (L+R)/2;
        return join(query(2*v, L, m, l, r), query(2*v +1, m+1, R, l, r));
    }
    T query(int L, int R){
        return query(1, 0, N-1, L, R);
    }
};

void solve(){
    int n; cin>>n;
    vector<char> vec (n);
    for(int i = 0; i<n; i++) cin>>vec[i];
    vector<int> distancias;
    vector<int> pdistancias;
    int tamanho = 1; int ptamanho = 0;
    for(int i = 1; i<n; i++){
        if(vec[i] == vec[i-1]) tamanho++;
        else{
            ptamanho += tamanho;
            distancias.push_back(tamanho);
            pdistancias.push_back(ptamanho);
            tamanho = 1;
        }
    }
    distancias.push_back(tamanho); ptamanho += tamanho;
    pdistancias.push_back(ptamanho);
    int tamanho_tree = (distancias.size() + 1)/2;
    vector<int> aux (tamanho_tree, 1e9); aux[aux.size() - 1] = 0;
    SegTree Tree(aux);
    for(int i = distancias.size()-3; i>=0; i -= 2){
        int alcance = lower_bound(pdistancias.begin(), pdistancias.end(), distancias[i] + pdistancias[i]) - pdistancias.begin();
        if(alcance % 2 == 1) alcance--;
        int indice = (i)/2;
        int ate = (alcance)/2;
        int busca = Tree.query(indice, ate);
        Tree.update(1, 0, tamanho_tree-1, indice, busca+1);
    }
    int r = Tree.query(0,0);
    if(r == 1e9) cout<<-1<<'\n';
    else cout<<r<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}