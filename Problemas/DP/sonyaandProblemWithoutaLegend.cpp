#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long long;

void solve(){
    int n; cin>>n;
    vector<ll> vec (n);
    priority_queue<ll> pq;
    ll resposta = 0;
    for(int i = 0 ; i<n; i++){
        cin>>vec[i];
        vec[i] -= i;
        pq.push(vec[i]);
        if(pq.top() > vec[i]){
            resposta += (pq.top() - vec[i]);
            pq.pop();
            pq.push(vec[i]);
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}