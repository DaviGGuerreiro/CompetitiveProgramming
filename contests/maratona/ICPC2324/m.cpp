#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int n;

void solve(){
    cin>>n;
    vector<vector<int>> vec (n, vector<int> (n));
    for(int i = 0 ; i<n; i++){
        for(int j =  0; j<n; j++){
            cin>>vec[i][j];
        }
    }
    int resposta = 0;
    map<pair<int,int>, bool> mapa;
    for(int k = 0; k<n; k++){
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j<n; j++){
                if(i == j || i == k || j == k) continue;
                if(vec[i][j] == vec[i][k] + vec[k][j]){
                    if(mapa[{i, j}]) continue;
                    resposta++;
                    mapa[{i, j}] = true;
                    mapa[{j, i}] = true;
                }
                if(vec[i][j] > vec[i][k] + vec[k][j]){ cout<<"-1\n"; return; }
            }
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}