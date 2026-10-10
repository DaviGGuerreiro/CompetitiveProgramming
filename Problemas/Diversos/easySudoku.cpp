#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<vector<int>> vec;
vector<set<int>> disponivel_x;
vector<set<int>> disponivel_y;
vector<set<int>> disponivel_z;

bool backtracking(int i, int j){
    if(i == 9) return true;
    if(vec[i][j] != 0) return backtracking(i + (j == 8), j == 8 ? 0 : j+1);
    int aux1 = i/3;
    int aux2 = j/3;
    int setor = (aux1 * 3) + aux2;
    set<int> disponivel;
    for(const auto it : disponivel_x[j]){
        if(disponivel_y[i].find(it) != disponivel_y[i].end() && disponivel_z[setor].find(it) != disponivel_z[setor].end()){
            disponivel.insert(it);
        }
    }
    if(disponivel.size() == 0) return false;
    for(const auto it : disponivel){
        vec[i][j] = it;
        disponivel_x[j].erase(it);
        disponivel_y[i].erase(it);
        disponivel_z[setor].erase(it);
        if(!backtracking(i + (j == 8), j == 8 ? 0 : j+1)){
            vec[i][j] = 0;
            disponivel_x[j].insert(it);
            disponivel_y[i].insert(it);
            disponivel_z[setor].insert(it);
        }
        else return true;
    }
    return false;
}

void solve(){
    vec = vector<vector<int>> (9, vector<int> (9));
    disponivel_x = vector<set<int>> (9, {1,2,3,4,5,6,7,8,9});
    disponivel_y = vector<set<int>> (9, {1,2,3,4,5,6,7,8,9});
    disponivel_z = vector<set<int>> (9, {1,2,3,4,5,6,7,8,9});
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cin>>vec[i][j];
            int aux1 = i/3;
            int aux2 = j/3;
            int setor = (aux1 * 3) + aux2;
            disponivel_x[j].erase(vec[i][j]);
            disponivel_y[i].erase(vec[i][j]);
            disponivel_z[setor].erase(vec[i][j]);
        }
    }
    bool resposta = backtracking(0, 0);
    if(!resposta){
        cout<<"No solution\n";
    }
    else{
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                cout<<vec[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}