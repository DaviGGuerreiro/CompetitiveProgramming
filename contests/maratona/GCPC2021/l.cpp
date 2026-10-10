#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<long,long>;

int h, w;
int resposta = 1e5;
bool flg = false;
map<char, int> mapa;

void solve(){
    cin>>h>>w;
    vector<vector<vector<int>>> vec (h, vector<vector<int>> (w, vector<int> (5, 0)));
    vector<vector<char>> v (h, vector<char> (w));
    for(int i = 0; i<h; i++){
        for(int j = 0 ; j<w; j++){
            cin>>v[i][j];
        }
    }
    for(int i = 0; i<h; i++){
        for(int j = 0 ; j<w; j++){
            if(i != 0){
                for(int k = 0; k<5; k++){
                    vec[i][j][k] += vec[i-1][j][k];
                }
            }
            if(j != 0){
                for(int k = 0; k<5; k++){
                    vec[i][j][k] += vec[i][j-1][k];
                }
            }
            if(i != 0 && j != 0){
                for(int k = 0; k<5; k++){
                    vec[i][j][k] -= vec[i-1][j-1][k];
                }
            }
            if(mapa[v[i][j]] != 0){
                vec[i][j][mapa[v[i][j] - 1]]++;
            }
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    mapa['W'] = 1; mapa['A'] = 2; mapa['L'] = 3; mapa['D'] = 4; mapa['O'] = 5;
    solve();
    return 0;
}