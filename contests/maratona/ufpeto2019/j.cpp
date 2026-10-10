#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

template<typename T>
struct SegTree {
    int N;
    const T NEUTRAL = 0;
    vector<T> seg;
    SegTree(const vector<T> &vec) : N(vec.size()), seg(4 * vec.size(), NEUTRAL) {
        build(vec, 1, 0, N-1);
    }

    T join(const T &vl, const T &vr) {
        return max(vl, vr); 
    }

    void build(const vector<T> & vec, int v, int l, int r){
        if(l == r){
            seg[v] = vec[l];
            return;
        }
        int m = (l + r) / 2;
        build(vec, 2 * v, l, m);
        build(vec, 2 * v + 1, m+1, r);
        seg[v] = join(seg[2*v], seg[2*v + 1]);
    }
    void update(int v, int tl, int tr, int pos, T new_val){
        if(tl == tr){
            seg[v] = new_val;
            return;
        }
        int tm = (tl + tr)/2;
        if(pos <= tm){
            update(2*v,tl,tm,pos,new_val);
        }
        else{
            update(2*v + 1,tm+1,tr,pos,new_val);
        }
        seg[v] = join(seg[2*v], seg[2*v + 1]);
    }
    T query(int v, int L, int R, int l, int r, int val){
        if(L > r || R < l || seg[v] <= val) return -1;
        if(L == R) return L;
        int m = (L+R)/2;
        int res = query(2 * v, L, m, l, r, val);
        if(res != -1) return res;
        return query(2*v +1, m+1,R, l, r, val);
    }
    T query(int L, int R, int val){
        return query(1, 0, N-1, L, R, val);
    }
};

void solve(){
    int n; cin>>n;
    vector<int> casas (n);
    vector<int> diferencas (n, 0);
    for(int i = 0; i < n; i++) cin>>casas[i];
    for(int i = 1; i < n; i++) diferencas[i] = abs(casas[i] - casas[i-1]);
    SegTree arvore(diferencas);
    int q; cin>>q;
    int tipo, a1, a2;
    for(int i = 0 ; i < q; i++){
        cin>>tipo>>a1>>a2;
        if(tipo == 1){
            if(n == 1) continue;
            casas[a1-1] = a2;
            if(a1 != 1){
                diferencas[a1-1] = abs(casas[a1-1] - casas[a1-2]);
                arvore.update(1, 0, n-1, a1-1, diferencas[a1-1]);
            }
            if(a1 != n){
                diferencas[a1] = abs(casas[a1] - casas[a1-1]);
                arvore.update(1, 0, n-1, a1, diferencas[a1]);
            }
        }
        else{
            if(n == 1){ cout<<1<<'\n'; continue; }
            if(a1 == n){ cout<<n<<'\n'; continue; }
            int r = arvore.query(a1, n-1, a2);
            if(r == -1){ cout<<n<<'\n'; continue; }
            cout<<r<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}