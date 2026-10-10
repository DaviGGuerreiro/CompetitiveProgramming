#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    vector<pair<int,int>> vec (n);
    for(int i = 0; i<n; i++){
        cin>>vec[i].second;
    }
    for(int i = 0; i<n; i++){
        cin>>vec[i].first;
    }
    sort(vec.begin(), vec.end());
    for(int i = 0 ; i<n; i++){
        cout<<vec[i].second<<' ';
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
}