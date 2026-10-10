#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<long,long>;
const ld eps = 1e-8;

void solve(){
    ll a, b, c; cin>>a>>b>>c;
    ld prob1 = ((ld)1/(ld)a);
    ld prob2 = (((prob1 * (a - b)))/((ld)(a - b - c)));
    ld resposta = 0.0;
    if(prob1 - eps > prob2){
        resposta = prob1 * b;
    }
    else{
        if(b - (a - b - c) > 0){
            resposta = prob2 * (a - b - c);
            resposta += prob1 * (b - (a - b - c));
        }
        else{
            resposta = prob2 * b;
        }
    }
    cout<<fixed<<setprecision(12)<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}