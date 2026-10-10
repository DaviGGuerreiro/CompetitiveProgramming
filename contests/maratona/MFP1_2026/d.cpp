#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

void solve(){
    int n; cin>>n;
    vector<int> vec (n);
    int valor;
    ll total = 0;
    for(int i = 0 ; i<n; i++){
        cin>>vec[i];
        if(i == 0) valor = vec[i];
        else{
            valor = gcd(valor, vec[i]);
        }
        total += vec[i];
    }
    cout<<(total/valor)<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}