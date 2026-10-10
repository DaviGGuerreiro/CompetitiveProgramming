#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, m, o, mi, oi, aux, q; cin>>n>>m>>o;
    map<int, int> igredientes;
    vector<vector<int>> custo (m+1, vector<int> (n+1, 0));

    for(int i = 0 ; i<n; i++){
        cin>>aux;
        igredientes[i+1] = aux;
    }
    for(int i = 0; i<m; i++){
        cin>>mi;
        for(int j = 0; j<mi; j++){
            cin>>aux>>q;
            custo[i+1][aux] = q;
        }
    }
    int resposta = 0;
    bool flg = true;
    for(int i = 0 ; i<o; i++){
        cin>>oi;
        for(int j = 0; j<oi; j++){
            cin>>aux;
            if(!flg) continue;
            for(int k = 1; k<=n; k++){
                igredientes[k] -= custo[aux][k];
                if(igredientes[k] < 0){ flg = false; break;}
            }
        }
        if(flg) resposta++;
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}