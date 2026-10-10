#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    string s; cin>>s;
    int n; cin>>n;
    vector<multiset<char>> val (n);
    int aux;
    for(int i = 0 ; i < s.size(); i++){
        aux = i % n;
        val[aux].insert(s[i]);
    }
    for(int i = 0 ; i<s.size(); i++){
        aux = i % n;
        auto it = val[aux].begin();
        cout<<(*it);
        val[aux].erase(it);
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
}