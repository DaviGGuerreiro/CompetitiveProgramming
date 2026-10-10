#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int a, b, x; cin>>a>>b>>x;
    int quantidade = abs(a-b);
    int diferenca = 0, aux = 0;
    while(a != b){
        if(a > b) a /= x;
        else b /= x;
        aux++;
        diferenca = abs(a-b);
        quantidade = min(quantidade, diferenca + aux);
    }
    cout<<quantidade<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}