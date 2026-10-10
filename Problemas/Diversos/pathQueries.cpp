#include<bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

ll total = 0;
int ultimo = 0;
int n, q;
vector<int> pai, tamanho;

struct Aresta{
    int u, v, peso;
    bool operator<(const Aresta& outro) const {
        return peso < outro.peso;
    }
};

struct Queries{
    int valor, indice;
    bool operator<(const Queries& outro) const {
        return valor < outro.valor;
    }
};

int find(int u){
    if(u == pai[u]) return u;
    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return;
    if(tamanho[u]<tamanho[v]) swap(u,v);

    total += 1LL * tamanho[u] * tamanho[v];
    pai[v] = u;
    tamanho[u] = tamanho[u] + tamanho[v];
}

void solve(){
    cin>>n>>q;
    pai = vector<int> (n+3);
    tamanho = vector<int> (n+3, 1);
    vector<Aresta> arvore (n-1);
    vector<Queries> queries (q);
    vector<ll> resposta (q);
    for(int i = 0; i<=n+2; i++){
        pai[i] = i;
    }
    for(int i = 0; i < n-1; i++){
        cin>>arvore[i].u>>arvore[i].v>>arvore[i].peso;
    }
    for(int i = 0; i<q; i++){
        cin>>queries[i].valor; queries[i].indice = i;
    }
    sort(arvore.begin(), arvore.end());
    sort(queries.begin(), queries.end());
    int j = 0;
    for(int i = 0; i < q; i++){
        while(j < n-1 && arvore[j].peso <= queries[i].valor){
            join(arvore[j].u, arvore[j].v);
            j++;
        }
        resposta[queries[i].indice] = total;
    }
    for(int i = 0; i<q; i++){
        cout<<resposta[i]<<' ';
    }
    cout<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}