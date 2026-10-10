#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int vec[1000001];

void solve(){
    int n; cin>>n;
    int aux;
    for(int i = 0; i<n; i++){
        cin>>aux;
        if(vec[aux] != 0){
            vec[aux]++;
            continue;
        }
        for(int j = 1; j * j <= aux; j++){
            if(aux % j == 0){
                vec[j]++;
                if(j != aux/j) vec[aux/j]++;
            }
        }
    }
    for(int i = 1e6; i >= 1; i--){
        if(vec[i] >= 2){
            cout<<i<<'\n';
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    for(int i = 0; i<=1e6; i++) vec[i] = 0;
    solve();
    return 0;
}