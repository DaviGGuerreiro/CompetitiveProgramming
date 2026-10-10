#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

void solve(){
    int n; cin>>n;
    vector<char> vec (n);
    int uns = 0, zeros = 0;
    int aux1 = 0, aux2 = 0;
    char ultimo = '2';
    for(int i = 0 ; i<n; i++){
        cin>>vec[i];
        if(vec[i] == '0') zeros++;
        else uns++;
        if(vec[i] == ultimo){
            if(vec[i] == '0') aux1++;
            else aux2++;
        }
        ultimo = vec[i];
    }
    if(max(uns, zeros) - min(uns, zeros) >= 3){ cout<<-1<<'\n'; return;}
    if(aux1 == aux2){
        cout<<(aux1 + aux2)<<'\n';
    }
    else{
        int aux = max(aux1, aux2);
        aux *= 2; aux--;
        cout<<aux<<'\n';
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}