#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

void solve(){
    ll resposta = 0;
    int n, aux; cin>>n;
    map<int,int> freq;
    pair<int,int> aux2 = {0,0};
    ll total = 0;
    for(int i = 0; i<n; i++){
        cin>>aux;
        freq[aux]++;
        if(aux2.first < freq[aux]){
            aux2.first = freq[aux];
            aux2.second = aux;
        }
        total += aux;
    }
    if(aux2.first > ((n+1)/2) + (n % 2 == 0)){
        ll dif = max(2, n - aux2.first + 2);
        total -= (aux2.first * aux2.second);
        total += aux2.second * dif;
    }
    cout<<total<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}