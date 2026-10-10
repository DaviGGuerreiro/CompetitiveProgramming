#include<bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

void solve(){
    int n, m, q; cin>>n>>m>>q;
    vector<vector<int>> diplomata (n);
    vector<vector<int>> linguas (m+1, vector<int> (m+1, 100));
    for(int i = 1; i<=m; i++){
        linguas[i][i] = 0;
    }
    int num, aux;
    for(int i = 0; i<n; i++){
        cin>>num;
        for(int j = 0; j<num; j++){
            cin>>aux;
            diplomata[i].push_back(aux);
        }
        for(int j = 0; j <num; j++){
            for(int k = 0; k<num; k++){
                if(j == k) continue;
                linguas[diplomata[i][j]][diplomata[i][k]] = 1;
                linguas[diplomata[i][k]][diplomata[i][j]] = 1;
            }
        }
    }
    for(int k = 1; k <=m; k++){
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=m; j++){
                if(k == i || k == j || j == i) continue;
                if(linguas[i][j] > linguas[i][k] + linguas[k][j]){
                    linguas[i][j] = linguas[i][k] + linguas[k][j];
                }
            }
        }
    }

    int a, b;
    int minimo;

    for(int i = 0; i<q; i++){
        cin>>a>>b; a--; b--;
        minimo = 50;
        for(auto it : diplomata[a]){
            for(auto et: diplomata[b]){
                minimo = min(minimo, linguas[it][et]);
            }
        }
        if(minimo == 50) cout<<-1<<'\n';
        else cout<<minimo<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}