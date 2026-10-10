#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    string aux, aux1;
    priority_queue<pair<string, pair<string,int>>, vector<pair<string,pair<string,int>>>, greater<pair<string,pair<string,int>>>> pq;
    for(int i = 0 ; i < n; i++){
        cin>>aux;
        aux1 = aux;
        sort(aux.begin(), aux.end());
        pq.push({aux, {aux1, i+1}});
    }
    int q; cin>>q;
    priority_queue<pair<string, pair<string,int>>, vector<pair<string,pair<string,int>>>, greater<pair<string,pair<string,int>>>> ordens;
    vector<int> resposta (q+1);
    for(int i = 0 ; i<q; i++){
        cin>>aux;
        aux1 = aux;
        sort(aux.begin(), aux.end());
        ordens.push({aux, {aux1, i+1}});
    }
    int r = 0;
    while(!ordens.empty()){
        auto topo = ordens.top(); ordens.pop();
        while(!pq.empty() && topo.first >= pq.top().first){
            if(topo.first == pq.top().first){
                if(topo.second.first < pq.top().second.first) break;
            }
            r++; pq.pop();
        }
        resposta[topo.second.second] = r;
    }
    for(int i = 1; i<= q; i++){
        cout<<resposta[i]<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}