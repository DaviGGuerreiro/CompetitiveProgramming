#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int resposta = 0, aux;
    int n, m; cin>>n>>m;
    vector<int> vec (n);
    map<int, int> mapa;
    for(int i = 0 ; i < n; i++){
        cin>>vec[i];
        mapa[vec[i]]++;
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i<n; i++){
        aux = upper_bound(vec.begin(), vec.end(), vec[i]) - vec.begin();
        resposta = max(resposta, mapa[vec[i]] + n - aux + mapa[2*vec[i]]);
        if(vec[i] % 2 == 0) resposta = max(resposta, (mapa[vec[i]]*2) + );
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
}