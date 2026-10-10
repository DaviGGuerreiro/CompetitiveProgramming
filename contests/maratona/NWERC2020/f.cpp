#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ld eps = 1e-8;

void solve(){
    int n; cin>>n;
    vector<tuple<ll,ll,ll>> vec (n);
    set<int> conjunto;
    vector<bool> presente (n, true);
    map<int, int> mapa;
    for(int i = 0; i<n; i++){
        cin>>get<0>(vec[i])>>get<1>(vec[i]); get<2>(vec[i]) = i;
        conjunto.insert(get<0>(vec[i]));
        mapa[get<0>(vec[i])] = i;
    }
    priority_queue<tuple<ld,ll,ll>, vector<tuple<ld,ll,ll>>, greater<tuple<ld,ll,ll>>> pq;
    for(int i = 0; i<n-1; i++){
        if(get<1>(vec[i]) > get<1>(vec[i+1])){
            pq.push(make_tuple((ld)((get<0>(vec[i+1]) - get<0>(vec[i]))) / ((ld)(get<1>(vec[i]) - get<1>(vec[i+1]))), i, i+1));
        }
    }

    while(!pq.empty()){
        auto aux = pq.top(); pq.pop();
        if(!presente[get<1>(aux)] || !presente[get<2>(aux)]) continue;
        presente[get<1>(aux)] = false;
        presente[get<2>(aux)] = false;

        bool bota = true;
        conjunto.erase(get<0>(vec[get<1>(aux)])); conjunto.erase(get<0>(vec[get<2>(aux)]));

        auto it = conjunto.lower_bound(get<0>(vec[get<1>(aux)]));
        bool fl1 = (it == conjunto.begin());
        if(fl1) bota = false;
        
        auto et = conjunto.upper_bound(get<0>(vec[get<2>(aux)]));
        bool fl2 = (et == conjunto.end());
        if(fl2) bota = false;
        
        if(bota){
            auto a = et; int ind2 = *a; ind2 = mapa[ind2];
            auto b = et; b--; int ind1 = *b; ind1 = mapa[ind1];
            if(get<1>(vec[ind1]) > get<1>(vec[ind2])) pq.push(make_tuple((ld)(get<0>(vec[ind2]) - get<0>(vec[ind1])) / ((ld)(get<1>(vec[ind1]) - get<1>(vec[ind2]))), ind1, ind2));
        }
    }
    cout<<conjunto.size()<<'\n';
    for(auto it : conjunto){
        cout<<mapa[it]+1<<' ';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}