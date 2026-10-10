#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<int> vec (n);
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    int zero = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(int i = n-1; i>=0; i--){
        if(vec[i] == 0){
            zero++;
        }
        else{
            if(pq.size() < zero){
                pq.push(vec[i]);
            }
            else if(!pq.empty() && pq.top() < vec[i]){
                pq.pop();
                pq.push(vec[i]);
            }
        }
    }
    ll acc = 0;
    while(!pq.empty()){
        auto aux = pq.top(); pq.pop();
        acc += aux;
    }
    cout<<acc<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}