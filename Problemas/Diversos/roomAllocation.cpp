#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    priority_queue<ll, vector<ll>, greater<ll>> fila;
    vector<tuple<ll,ll,ll>> vec (n);
    for(int i = 0; i<n; i++){
        cin>>get<0>(vec[i])>>get<1>(vec[i]);
        get<2>(vec[i]) = i+1;
        fila.push(i+1);
    }
    sort(vec.begin(), vec.end());
    int maximo = 0;
    vector<int> resposta (n+1);
    for(int i = 0; i<n; i++){
        while(!pq.empty() && pq.top().first < get<0>(vec[i])){
            fila.push(pq.top().second); pq.pop();
        }
        resposta[get<2>(vec[i])] = fila.top();
        pq.push({get<1>(vec[i]), fila.top()});
        maximo = max(maximo, (int)fila.top());
        fila.pop();
    }
    cout<<maximo<<'\n';
    for(int i = 1; i<=n; i++){
        cout<<resposta[i]<<' ';
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}