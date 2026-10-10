#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    ll total = 0;
    int n, m, aux; cin>>n>>m;
    vector<int> vec (n);
    for(int i = 0 ; i<n; i++){
        cin>>vec[i]>>aux; total += aux;
    }
    char tipo; int l, r, q;
    for(int i = 0 ; i<m; i++){
        cin>>tipo;
        if(tipo == 'W'){
            cin>>l>>r;
        }
        else{
            cin>>q;
        }
    }
    cout<<total<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}