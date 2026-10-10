#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long uniform(long long l, long long r){
    uniform_int_distribution<long long> uid(l, r);
    return uid(rng);
}

void solve(){
    int n; cin>>n;
    pll a, b;
    cin>>a.first>>a.second;
    cin>>b.first>>b.second;
    vector<pll> vec (n);
    pll distancia; distancia.first = (b.first - a.first); distancia.second = (b.second - a.second);
    map<pll, bool> mapa;
    bool ganha = false;
    for(int i = 0; i<n; i++){
        cin>>vec[i].first>>vec[i].second;
        mapa[vec[i]] = true;
        if(mapa[{distancia.first - vec[i].first, distancia.second - vec[i].second}] || mapa[distancia]) ganha = true;
    }
    if(ganha){ cout<<"Alice wins\n"; return;}
    if(n <= 3){
        map<pll, bool> mapa2; mapa2[b] = true;
        for(int i = 0; i<n; i++){
            mapa2[{b.first + vec[i].first, b.second + vec[i].second}] = true;
            for(int j = 0; j<n; j++){
                mapa2[{b.first + vec[i].first + vec[j].first, b.second + vec[i].second + vec[j].second}] = true;
            }
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(!mapa2[{i, j}]){ cout<<"tie "<<i<<' '<<j<<'\n'; return;}
            }
        }
        cout<<"Bob wins\n"; return;
    }
    bool encontrou = true; mapa[{0,0}] = true;
    while(encontrou){
        encontrou = false;
        pll origem = {uniform(1, n), uniform(1, n)};
        pll dist = {origem.first - b.first, origem.second - b.second};
        for(int i = 0; i<n; i++){
            if(mapa[{dist.first - vec[i].first, dist.second - vec[i].second}] || mapa[dist]){ encontrou = true; break; }
        }
        if(!encontrou){cout<<"tie "<<origem.first<<' '<<origem.second<<'\n'; return; }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}