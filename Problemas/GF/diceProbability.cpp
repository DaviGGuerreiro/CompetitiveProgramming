#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    ll n, a, b; cin>>n>>a>>b;
    vector<ld> vec (1, 1.0);
    for(int i = 0; i<n; i++){
        vector<ld> nvec (6 * (i+1) + 1, 0.0);
        for(int j = i+1; j < (int)nvec.size(); j++){
            for(int k = 6; k > 0; k--){
                if(j - k < 0) continue;
                else if(j - k >= (int)vec.size()) break;
                nvec[j] += (vec[j - k] / 6.0);
            }
        }
        vec = move(nvec);
    }
    ld resposta = 0.0;
    for(int i = a; i<= b; i++){
        resposta += vec[i];
    }
    cout<<fixed<<setprecision(6)<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
    return 0;
}