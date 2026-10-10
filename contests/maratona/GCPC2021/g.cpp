#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<long,long>;

int n, m;

void solve(){
    cin>>n>>m;
    vector<stack<int>> vec (n);
    char aux;
    int quantidade = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0 ; j < m; j++){
            cin>>aux;
            if(aux == 'C'){quantidade++; vec[i].push(j);}
        }
    }
    int resposta = 0, baixo, nivel;
    while(quantidade != 0){
        resposta++;
        nivel = 0;
        for(int i = 0 ;i < n; i++){
            if(vec[i].empty()) continue;
            if(vec[i].top() >= nivel){
                baixo = nivel;
                nivel = vec[i].top();
                while(!vec[i].empty() && vec[i].top() >= baixo){
                    vec[i].pop();
                    quantidade--;
                }
            }
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}