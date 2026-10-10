#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    string t; cin>>t;
    int tamanho = (t.size() + 2)/3;
    vector<int> vec (tamanho, 0);
    int indice = t.size() - 1;
    ll resposta = 0;
    ll mult;
    bool flg = true;
    for(int i = tamanho-1 ; i >= 0; i--){
        mult = 1;
        for(int j = 0; j < 3; j++){
            if(indice >= 0){
                vec[i] += (mult*(t[indice] - '0'));
            }
            mult *= 10;
            indice--;
        }
        if(flg){
            resposta += vec[i];
        }
        else{
            resposta -= vec[i];
        }
        flg = !flg;
    }
    resposta = abs(resposta);
    cout<<resposta<<' ';
    if(resposta % 13 == 0){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int tent; cin>>tent; 
    while(tent--) solve();
}