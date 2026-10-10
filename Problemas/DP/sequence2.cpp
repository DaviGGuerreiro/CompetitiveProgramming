#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long long;

void solve(){
    int n; cin>>n;
    vector<ll> a (n);
    priority_queue<ll> pq;
    ll resposta = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i]; pq.push(a[i]);
        if(pq.top() > a[i]){
            resposta += pq.top() - a[i]; pq.pop();
            pq.push(a[i]);
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}