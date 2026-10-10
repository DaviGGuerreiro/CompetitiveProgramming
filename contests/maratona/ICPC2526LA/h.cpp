#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    int dias = 0;
    int maximo = 0;
    int aux;
    for(int i = 0 ; i<n; i++){
        cin>>aux;
        if(maximo < aux){
            dias++;
            maximo = aux;
        }
    }
    cout<<dias<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}