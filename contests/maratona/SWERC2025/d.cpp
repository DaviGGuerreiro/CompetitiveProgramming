#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    map<int,int> conjuntos;
    int x;
    for(int i = 0; i< n; i++){
        cin>>x;
        conjuntos[x]++;
    }
    ll resposta = 0;
    for(auto [chave, valor]: conjuntos){
        if(chave != valor){
            if(chave > valor) resposta += valor;
            else resposta += (valor - chave);
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}