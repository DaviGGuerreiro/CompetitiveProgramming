#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll n, x;

vector<ll> vec;

bool func(ll mid){
    ll total = 0;
    for(int i = 0; i<n; i++){
        if(vec[i] < mid){
            total += (mid - vec[i]);
            if(total > x) return false;
        }
    }
    return true;
}

void solve(){
    cin>>n>>x;
    vec = vector<ll> (n);
    for(int i = 0; i<n; i++){
        cin>>vec[i];
    }
    int l = 1, r = 2e9;
    int res = 1;
    while(r >= l){
        ll mid = l + ((r-l)/2);
        if(func(mid)){
            res = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout<<res<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}