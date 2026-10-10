#include<bits/stdc++.h>
using namespace std;
using ll = long long;



void solve(){
    int q; cin>>q;
    ll x, y, z, aux, resp, w;
    ll MOD;
    ll r1, r2;
    while(q--){
        cin>>x; z = 0;
        ll l = 0, r = 1e6 + 1;
        while(r >= l){
            ll mid = l + ((r-l)/2);
            w = (mid * 2) + 1;
            if(w * w <= x){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        z = l;
        aux = (z * 2ll) - 1ll;
        MOD = (aux * aux) + (z - 1);
        if(x <= MOD){
            y = MOD - x;
        }
        else{
            x -= MOD;
            r1 = (x % (z * 2));
            if(r1 <= z){
                y = r1;
            }
            else{
                y = z - (r1 - z);
            }
        }
        z = z * 2; y = y * 2; 
        resp = (z * z) + (y * y);
        cout<<resp<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}