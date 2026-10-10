#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const ll MOD = 998244353;
vector<vector<char>> periodo;

void solve(){
    int n; cin>>n;
    vector<char> vec (n);
    vector<bool> flg (4, true); 
    ll resposta = 4;
    for(int i = 0 ; i<n; i++){
        cin>>vec[i];
        for(int j = 0 ; j < 4; j++){
            if(vec[i] != '?' && flg[j] && vec[i] != periodo[j][i%4]){flg[j] = false; resposta--;}
        }
    }
    cout<<resposta<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    string s = "0011";
    periodo = vector<vector<char>> (4, vector<char> (4));
    for(int i = 0 ; i<4; i++){
        for(int j = 0; j<4; j++){
            periodo[i][j] = s[(j + i) % 4];
        }
    }
    int t; cin>>t; while(t--) solve();
    //solve();
}