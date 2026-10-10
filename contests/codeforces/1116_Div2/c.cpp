#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    int n, k; cin>>n>>k;
    vector<char> vec (2 * n);
    pair<int,int> resposta = make_pair(0,0);
    for(int i = 0 ;i<(2*n); i++){
        cin>>vec[i];
    }
    for(int i = 0; i<(2*n); i++){
        if(vec[i] == '1'){
            if(vec[(i + 1) % (2*n)] == '0'){
                if(i % 2 == 0) resposta.first++;
                else resposta.second++;
            }
            else{
                if(i % 2 == 0) resposta.second++;
                else resposta.first++;
            }
        }
    }
    cout<<resposta.first<<' '<<resposta.second<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
    //solve();
}