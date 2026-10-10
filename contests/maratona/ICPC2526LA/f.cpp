#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    string x, y; cin>>x;
    for(int i = 0; i<10 && i < x.size(); i++){
        y.push_back(x[i]);
    }
    int z = x.size() - y.size();
    ll numero = stoll(y);
    set<ll> conjunto;
    map<ll, int> mapa;
    if(z != 0){
        conjunto.insert(2);
        mapa[2] += z;
        conjunto.insert(5);
        mapa[5] += z;
    }

    for(ll i = 2; i * i <= numero; i++){
        if(numero % i == 0) conjunto.insert(i);
        while(numero % i == 0){
            mapa[i]++;
            numero = numero/i;
        }
    }
    if(numero != 1){
        conjunto.insert(numero);
        mapa[numero] ++;
    }

    cout<<conjunto.size()<<'\n';
    for(auto it : conjunto){
        cout<<it<<' '<<mapa[it]<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}