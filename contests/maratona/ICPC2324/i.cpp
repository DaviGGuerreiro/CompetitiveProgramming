#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    bool flg = false;
    ll l = 0, r = 0, aux, resposta = 0;
    ll impar = 0, par = 1;
    for(int i = 0 ; i<n; i++){
        cin>>aux;
        if(aux == 1){
            flg = !flg;
        }
        
        if(flg){
            impar++;
            resposta += par;
            l += par;
        }
        else{
            par++;
            resposta += impar;
            r += impar;
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}