#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll resp = -(1e16);
    ll m; int n; cin>>n>>m;
    vector<ll> vec (n+1);
    priority_queue<ll> pq;
    ll soma = 0;
    for(int i = 1; i <= n; i++){
        cin>>vec[i];
        if(i < m){ pq.push(vec[i]); soma += vec[i]; }
        else{
            resp = max(resp, (m * (vec[i])) - soma);
            if(!pq.empty() && vec[i] < pq.top()){
                soma += (vec[i] - pq.top());
                pq.pop(); pq.push(vec[i]);
            }
        }
    }
    cout<<resp<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; 
    while(t--) solve();
}