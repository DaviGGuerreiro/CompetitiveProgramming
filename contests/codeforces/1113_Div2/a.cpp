#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    string s; cin>>s;
    bool flg1 = true, flg2 = true;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '0' && flg1){
            s[i] = 'x'; flg1 = false;
        }
        else if(s[i] == '1' && flg2){
            s[i] = 'x'; flg2 = false;
        }
    }
    for(int i = 0 ; i < s.size(); i++){
        if(s[i] != 'x'){
            cout<<s[i];
        }
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t; while(t--) solve();
    //solve();
}