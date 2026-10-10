#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n; cin>>n;
    char opp; ll base, val;
    unordered_set<ll> SI, SP, MI, MP;
    for(int i = 0; i<n; i++){
        cin>>opp;
        if(opp == '+'){
            cin>>val;
            if(val % 2 == 1) SI.insert(val);
            else SP.insert(val);
        }
        else{
            cin>>val;
            if(val % 2 == 1) MI.insert(val);
            else MP.insert(val);
        }
    }
    bool comeco;
    cin>>base; 
    if(base % 2 == 0) comeco = true;
    ll nada = MI.size() + SP.size(); 
    ll flipa = SI.size(); 
    ll ativa = MP.size();
    vector<vector<vector<bool>>> dp (nada + 1, (vector<vector<bool>> (flipa + 1, (vector<bool> (ativa + 1, false)))));
    dp[0][0][0] = 
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}