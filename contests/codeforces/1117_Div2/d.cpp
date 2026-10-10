#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    ll s, q; cin>>s>>q;
    vector<ll> x;
    for(ll i = 1; i * i <= s; i++){
        if(s%i == 0){ 
            x.push_back(i); 
            if(i != s/i) x.push_back(s/i);
        }
    }
    sort(x.begin(), x.end());
    int tamanho = x.size();

    vector<ll> y(tamanho), pre (tamanho);
    for(int i = 0; i<tamanho; i++){
        y[i] = s / x[i];
        ll x_prev = (i == 0) ? 0 : x[i-1];
        ll area = (x[i] - x_prev) * y[i];
        pre[i] = (i == 0) ? area : pre[i-1] + area;
    }

    ll a, b;
    for(int i = 0; i<q; i++){
        cin>>a>>b;

        ll L = lower_bound(x.begin(), x.end(), (s + b - 1) / b) - x.begin();
        ll R = lower_bound(x.begin(), x.end(), a) - x.begin();
        
        if (L > R) {
            cout << a * b << '\n';
        } else {
            ll x_L_minus_1 = (L == 0) ? 0 : x[L-1];
            ll pre_R_minus_1 = (R == 0) ? 0 : pre[R-1];
            ll pre_L_minus_1 = (L == 0) ? 0 : pre[L-1];
            ll x_R_minus_1 = (R == 0) ? 0 : x[R-1];
            
            ll area = x_L_minus_1 * b;
            area += (pre_R_minus_1 - pre_L_minus_1);
            area += (a - x_R_minus_1) * y[R];
            
            cout << area << '\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
}