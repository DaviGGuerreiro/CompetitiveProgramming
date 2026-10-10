#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, aux; cin>>n;
    int minimo = 8, maximo = -8;
    for(int i = 0; i<n; i++){
        cin>>aux;
        minimo = min(aux, minimo);
        maximo = max(maximo, aux);
    }
    cout<<maximo-minimo+1<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}