#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, q; cin>>n>>q;
    vector<pair<int,int>> v;
    map<int, string> mapa;
    string s; int x;
    for(int i = 1; i<=n; i++){
        cin>>s>>x;
        v.push_back({x, i});
        mapa[i] = s;
    }
    ll tempo = 0;
    while(!v.empty()){
        vector<pair<int,int>> vec;
        for(auto it : v){
            if(it.first <= q){
                tempo += it.first;
                for(auto et : mapa[it.second]){
                    cout<<et;
                }
                cout<<' '<<tempo<<'\n';
            }
            else{
                tempo += q;
                vec.push_back({it.first - q, it.second});
            }
        }
        swap(vec, v);
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}