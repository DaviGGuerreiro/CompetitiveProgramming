#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool func(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
    if(a.first.first > b.first.first) return true;
    else if(a.first.first == b.first.first){
        if(a.first.second < b.first.second) return true;
        return false;
    }
    return false;
}

void solve(){
    int n, q; cin>>n>>q;
    vector<pair<int, pair<int,int>>> vec (n);
    for(int i = 0; i<n; i++){
        cin>>(vec[i].second).first>>(vec[i].second).second>>vec[i].first;
    }
    sort(vec.rbegin(), vec.rend());
    int t1, k1;
    vector<pair<pair<int,int>,int>> v (q);
    vector<int> respostas (q,0);
    for(int i = 0; i<q; i++){
        cin>>t1>>k1;
        v[i].first.first = t1; v[i].first.second = k1;
        v[i].second = i;
    }
    sort(v.begin(), v.end(), func);
    int ltemp = 0;
    int val, peso;
    vector<int> dp (1e4 + 2, 0);
    for(int i = 0; i < q; i++){
        while(ltemp < n && vec[ltemp].first > v[i].first.first){
            val = vec[ltemp].second.first;
            peso = vec[ltemp].second.second;
            for (int k = 1e4 - peso; k >= 0; --k) {
                dp[k + peso] = max(dp[k + peso], dp[k] + val);
            }
            ltemp++;
        }
        respostas[v[i].second] = dp[v[i].first.second];
    }
    for(int i = 0 ; i < q; i++) cout<<respostas[i]<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}