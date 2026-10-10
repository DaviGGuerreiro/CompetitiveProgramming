#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    vector<int> vec (3);
    cin>>vec[0]>>vec[1]>>vec[2];
    sort(vec.begin(), vec.end());
    if(vec[2] > vec[0] + vec[1]) cout<<vec[1]<<'\n';
    else cout<<vec[2] - vec[0]<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
    //solve();
}