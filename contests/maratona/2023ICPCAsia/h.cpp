#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int c; cin>>c;
    vector<int> entrada; int aux;
    while(cin>>aux) entrada.push_back(aux);
    vector<int> v (entrada.size()/2), w (entrada.size()/2);
    for(int i = 0 ; i<entrada.size()/2; i++){
        v[i] = entrada[i];
    }
    for(int i = entrada.size()/2; i < entrada.size(); i++){
        w[i - (entrada.size()/2)] = entrada[i];
    }
    vector<int> resposta (c+1,0);
    for(int i = 0; i < (entrada.size()/2); ++i){
        for(int k = c - w[i]; k >= 0; k--){
            resposta[k + w[i]] = max(resposta[k + w[i]], resposta[k] + v[i]);
        }
    }
    cout<<resposta[c]<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}