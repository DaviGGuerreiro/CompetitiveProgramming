#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n, t; cin>>n>>t;
    map<string, int> mapa;
    string atual = "";
    int fatual = 0;
    string aux;
    for(int i = 0; i<n; i++){
        cin>>aux;
        int j;
        for(j = 0; j<t; j++){
            if(aux[j] == '*') break;
        }
        for(int k = 0; k<26; k++){
            aux[j] = 'a' + k;
            mapa[aux]++;
            if(atual == ""){
                atual = aux;
                fatual = 1;
            }
            else if(mapa[aux] > fatual || (mapa[aux] == fatual && aux < atual)){
                atual = aux;
                fatual = mapa[aux];
            }
        }
    }
    for(const auto x : atual){
        cout<<x;
    }
    cout<<' '<<fatual<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}