#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k; cin>>n>>k;
    set<int> conjunto;
    map<int, int> quantidade;
    int aux;
    for(int i = 0; i<n; i++){
        cin>>aux;
        quantidade[aux]++;
        conjunto.insert(aux);
    }
    int resposta = 0; conjunto.insert(1e9);
    int gas = 0, ultimo = 0, distancia = 0;
    int percorrido = 0;
    for(auto it : conjunto){
        distancia += it - ultimo;
        if(gas >= distancia){
            if(quantidade[it] > k){
                
            }
        }
        else{
            gas = 0;
            percorrido = 0;
        }
        ultimo = it;
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}