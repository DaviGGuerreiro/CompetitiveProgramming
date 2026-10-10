#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int n, q, valor, num;
vector<vector<int>> arvore;
queue<int> folhas;
bool flg;
ll resposta = 0;

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
    int atual = 0, ultimo = -1, tamanho;
    ll impar;

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