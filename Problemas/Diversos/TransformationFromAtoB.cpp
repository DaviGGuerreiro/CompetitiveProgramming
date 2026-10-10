#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void solve(){
    ll a, b; cin>>a>>b;
    stack<ll> respostas; respostas.push(b);
    while(a != b){
        if(b % 2 == 0){
            b /= 2;
            respostas.push(b);
        }
        else if((b - 1) % 10 == 0){
            b--;
            b /= 10;
            respostas.push(b);
        }
        else{
            cout<<"NO\n";
            return;
        }

        if(b < a){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n"<<respostas.size()<<'\n';
    while(!respostas.empty()){
        auto aux = respostas.top(); cout<<aux<<' '; respostas.pop();
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    solve();
    return 0;
}