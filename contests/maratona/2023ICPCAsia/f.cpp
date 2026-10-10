#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

bool func(const pair<pair<ll, ll>, int>& a, const pair<pair<ll, ll>, int>& b){
    ll valor1 = a.first.second * b.first.first;
    ll valor2 = b.first.second * a.first.first;
    if(valor1 > valor2) return true;
    else if(valor1 == valor2) return a.second < b.second;
    return false;
}

void solve(){
    int n; cin>>n;
    vector<pair<pair<ll,ll>,int>> vec (n);
    for(int i = 0 ; i<n; i++){
        vec[i].second = i+1;
        cin>>vec[i].first.first>>vec[i].first.second;
    }
    sort(vec.begin(), vec.end(), func);
    for(int i = 0; i<n; i++) cout<<vec[i].second<<' ';
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
}