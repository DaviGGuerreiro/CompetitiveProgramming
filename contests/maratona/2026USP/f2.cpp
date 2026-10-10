#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int n, q, valor, num, aux2, dist;
vector<vector<int>> arvore;
queue<int> folhas;
bool flg;
ll resposta = 0;

vector<int> pai;

void dfs(int r, int anc){
    for(auto it: arvore[r]){
        if(it != anc){
            pai[it] = r;
            dfs(it, r);
        }
    }
}

void dfs_caminho(int x, int origem, int distancia){
    for(auto it : arvore[x]){
        if(it != origem){
            pai[it] = x;
            if(dist < distancia+1){
                dist = distancia+1;
                aux2 = it;
            }
            dfs_caminho(it, x, distancia+1);
        }
    }
}

void raiz(){
    pai = vector<int> (n, -1); dist = 0;
    dfs_caminho(0, -1, 0);
    pai = vector<int> (n, -1); dist = 0;
    dfs_caminho(aux2, -1, 0);
    int resp = aux2;
    for(int i = 0; i < dist/2; i++){
        resp = pai[resp];
    }
    pai = vector<int> (n, -1); 
    dfs(resp, -1);
}

void solve(){
    cin>>n>>q;
    arvore = vector<vector<int>> (n);
    vector<ll> numero (n, 0);
    vector<int> grau (n,0);
    int a, b;
    for(int i = 0 ; i<n-1; i++){
        cin>>a>>b; a--; b--;
        arvore[a].push_back(b);
        arvore[b].push_back(a);
        grau[a]++; grau[b]++;
    }
    
    for(int i = 0; i<n; i++) if(grau[i] == 1) folhas.push(i);
    vector<pair<int,int>> queries (q);
    for(int i = 0; i<q; i++){
        cin>>queries[i].first; queries[i].second = i;
    }
    sort(queries.begin(), queries.end());

    vector<ll> resultados (q);
    int atual = 0;
    int ultimo = -1;
    ll impar;
    int tamanho; 
    for(auto x : queries){
        int quantidade = x.first;
        int indice = x.second;
        impar = 0;
        if(ultimo == quantidade){
            resultados[indice] = resposta;
            continue;
        }

        while(atual != (quantidade/2)){
            tamanho = folhas.size();
            atual++;
        }

        if(quantidade % 2 == 1){

        }

        resultados[indice] = resposta + impar;
        ultimo = quantidade;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}