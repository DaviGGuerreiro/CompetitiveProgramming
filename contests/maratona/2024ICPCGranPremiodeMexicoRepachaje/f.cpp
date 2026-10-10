#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    set<int> conjunto;
    int aux;
    for(int i = 0; i < 5; i++){
        cin>>aux;
        conjunto.insert(aux);
    }
    for(int i = 0; i < 4; i++){
        cin>>aux;
        conjunto.erase(aux);
    }
    cout<<(*conjunto.begin())<<'\n';
}   

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}